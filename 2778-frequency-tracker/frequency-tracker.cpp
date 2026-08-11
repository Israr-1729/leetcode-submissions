class FrequencyTracker {
public:

    unordered_map<int, int> numToFreq;
    unordered_multiset<int> freqPresent;
    FrequencyTracker() {
        
    }
    
    void add(int num) {
        int oldFreq = numToFreq.contains(num) ? numToFreq[num] : 0;

        auto it = freqPresent.find(oldFreq);
        if (it != freqPresent.end())
        freqPresent.erase(it);

        int newFreq = oldFreq + 1;

        freqPresent.insert(newFreq);

        numToFreq[num]++;
    }
    
    void deleteOne(int num) {
        int oldFreq = numToFreq.contains(num) ? numToFreq[num] : 0;

        auto it = freqPresent.find(oldFreq);
        if(it != freqPresent.end())
        freqPresent.erase(it);

        if (oldFreq > 1)
        freqPresent.insert(oldFreq-1);

        if(oldFreq != 0)
        numToFreq[num]--;
    }
    
    bool hasFrequency(int frequency) {
        if(freqPresent.contains(frequency))
        return true;

        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */