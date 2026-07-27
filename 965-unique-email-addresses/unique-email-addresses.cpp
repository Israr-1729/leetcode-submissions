class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> pureEmails;
        for(string &s : emails)
        {
            int size = s.size();
            int i = 0;

            string localName = "";
            while(i<size && s[i] != '@')
            {
                while(isalpha(s[i]))
                {
                    localName += s[i];
                    i++;
                }

                while(s[i]=='.')
                i++;

                if(s[i] == '+')
                break;

                if(s[i] == '@')
                break;
            }

            while(s[i] != '@')
            i++;

            string domainName = "";
            
            while(i<size)
            {
                domainName += s[i];
                i++;
            }

            pureEmails.insert(localName + domainName);
        }
        return pureEmails.size();
    }
};