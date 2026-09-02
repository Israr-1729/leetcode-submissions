class Solution {
public:
    string clearDigits(string s) {
        string newString = "";
        bool doneOnce = false;
        for(char c : s)
        {
            newString += c;
            if(isdigit(c) && !doneOnce && newString.size() != 0)
            {
                newString.pop_back();
                newString.pop_back();
                doneOnce = true;
            }
        }
        if(doneOnce == false)
        return s;

        return clearDigits(newString);
    }
};