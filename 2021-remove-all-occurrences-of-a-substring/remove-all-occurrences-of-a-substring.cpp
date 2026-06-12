class Solution {
public:

    bool doesContain(const string &s, const string &part)
    {
        int size = s.size();
        int partSize = part.size();
        int i = 0;
        while(i<=size-partSize)
        {
            if(s[i]==part[0] && (s.substr(i, partSize) == part))
            return false;

            i++;
        }
        return true;
    }
    string removeOccurrences(string s, string part) {

        if(doesContain (s, part))
        return s;

        int size = s.size();
        int partSize = part.size();
        int i = 0;

        string result = "";
        while(i<=size-partSize)
        {
            if(s[i]==part[0] && (s.substr(i, partSize) == part))
            {
                i+=partSize;
                break;
            }
            else
            {
                result += s[i];
                i++;
            }
        }

        while(i<size)
        {
            result += s[i];
            i++;
        }
        return removeOccurrences(result, part);
    }
};