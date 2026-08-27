class Solution {
public:
    string freqAlphabets(string s) {
        vector<string> eachLetter;
        for(int i = 0; i <s.size()-2; i++)
        {
            if(s[i] == '#')
            continue;

            if(s[i+2] != '#')
            {
                string toAdd = ""; toAdd += s[i];
                eachLetter.push_back(toAdd);
            }

            else
            {
                eachLetter.push_back(s.substr(i, 2));
                i = i+2;
            }
        }

        if(s.back() != '#')
        {
            string toAdd = "";
            toAdd += s[s.size()-2];
            eachLetter.push_back(toAdd);
            toAdd = "";
            toAdd += s[s.size()-1];
            eachLetter.push_back(toAdd);
        }

        else if(s[s.size()-2] == '#')
        {
            string toAdd = "";
            toAdd += s[s.size()-1];
            eachLetter.push_back(toAdd);
        }

        string result = "";



        for(const string &st : eachLetter)
        {
            if(st == "#")
            continue;

            result += stoi(st) -1 + 'a';
        }



        return result;
        
    }
};