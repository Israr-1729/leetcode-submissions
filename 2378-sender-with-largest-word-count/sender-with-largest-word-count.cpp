class Solution {
public:

    int wordsCounter(const string &s)
    {
        int wordCount = 1;
        for(char c : s)
        {
            if(c==' ')
            wordCount++;
        }
        return wordCount;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> senderToWordCount;

        for(int i = 0; i<messages.size(); i++)
        {
            senderToWordCount[senders[i]] += wordsCounter(messages[i]);
        }

        int largestWordCount = INT_MIN;

        for(auto &a : senderToWordCount)
        {
            if(largestWordCount < a.second)
            {
                largestWordCount = a.second;
            }
        }

        cout<<largestWordCount;
        bool found = false;

        string sender = "";
        for(auto &a : senderToWordCount)
        {
            if(a.second == largestWordCount && (!found || a.first > sender))
            {
            sender = a.first;
            found = true;
            }
        }
        return sender;
    }
};