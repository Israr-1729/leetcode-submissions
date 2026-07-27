class FreqStack {
public:

    int maxFrequency = 0;
    unordered_map<int, int> numtofreq;
    unordered_map<int, stack<int>> freqtonum;

    FreqStack() {
    }

    void push(int val) {
        //Increase frequency of the number
        numtofreq[val]++;

        //Insert number to list of numbers with new frequencies.
        freqtonum[numtofreq[val]].push(val);

        //Update maximum frequency if needed.
        maxFrequency = max(maxFrequency, numtofreq[val]);
    }

    int pop() {
        //Find maximum frequency
        int highestFrequency = maxFrequency;

        //Find numbers with that maximum frequency
        stack<int> &numbersWithHighestFrequency = freqtonum[highestFrequency];

        //Choose most recently inserted number from this list
        int toPop = numbersWithHighestFrequency.top();

        //Remove toPop from the list of numbers with that maximum frequency
        numbersWithHighestFrequency.pop();

        //Decrease frequency of toPop in numtofreq
        numtofreq[toPop]--;

        //Decrease maximum frequency if there are no more numbers with that frequency.
        if (numbersWithHighestFrequency.empty())
            maxFrequency--;

        //Return the number that was popped
        return toPop;
    }
};