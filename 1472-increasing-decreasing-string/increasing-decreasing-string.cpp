class Solution {
public:

    bool isEmpty(const vector<int> &arr)
    {
        for(int a : arr)
        {
            if(a!=0)
            return false;
        }
        return true;
    }
    string sortString(string s) {
        vector<int> freq(26, 0);

        for(char c : s)
        {
            freq[c-'a']++;
        }

        string result = "";

        while(!isEmpty(freq))
        {
        for(int i = 0; i<26; i++)
        {
            if(freq[i] != 0)
            {
            result += 'a' + i;
            freq[i]--;
            }
        }

        if(isEmpty(freq))
        break;

        for(int i = 25; i>=0; i--)
        {
            if(freq[i] != 0)
            {
            result += 'a' + i;
            freq[i]--;
            }
        }

        if(isEmpty(freq))
        break;
        }
    return result;
    }
};