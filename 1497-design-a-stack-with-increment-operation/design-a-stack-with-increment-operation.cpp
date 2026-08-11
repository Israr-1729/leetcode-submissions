class CustomStack {
public:

    vector<int> v;
    int maxLength;
    CustomStack(int maxSize) {
        maxLength = maxSize;
    }
    
    void push(int x) {
        if(v.size() != maxLength)
        v.push_back(x);
    }
    
    int pop() {
        if(v.size() != 0)
        {
            int toReturn = v.back();
        v.pop_back();
        return toReturn;
        }

        return -1;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < ((v.size() < k) ? v.size() : k); i++)
        {
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */