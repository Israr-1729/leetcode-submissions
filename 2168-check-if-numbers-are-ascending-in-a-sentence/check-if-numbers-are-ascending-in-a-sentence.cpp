class Solution {
public:
    bool isSorted(const vector<int> &v)
    {
        for(int i = 0; i < v.size()-1; i++)
        {
            if(v[i] >= v[i+1])
            return false;
        }
        return true;
    }
    vector<int> numbers(const string &s)
    {
        vector<int> result;
        int i = 0; int size = s.size();

        while(i < size)
        {
            while(i < size && !isdigit(s[i]))
            i++;

            int newNum = 0; bool found = false;
            while(i < size && isdigit(s[i]))
            {
                found = true;
                newNum = newNum * 10 + (s[i] - '0');
                i++;
            }
            if(found)
            result.push_back(newNum);
        }
        return result;
    }
    bool areNumbersAscending(string s) {
        vector<int> nums = numbers(s);
        return isSorted(numbers(s));
        
    }
};