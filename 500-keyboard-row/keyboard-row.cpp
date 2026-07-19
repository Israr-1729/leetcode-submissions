class Solution {
public:

    char to_lower(char c)
    {
        if(c>='A' && c<='Z')
        return c+32;
        return c;
    }
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1; unordered_set<char> row2; unordered_set<char> row3;
        row1.insert('q'); row1.insert('w'); row1.insert('e'); row1.insert('r'); row1.insert('t'); row1.insert('y'); row1.insert('u'); row1.insert('i'); row1.insert('o'); row1.insert('p');

        row2.insert('a'); row2.insert('s'); row2.insert('d'); row2.insert('f'); row2.insert('g'); row2.insert('h'); row2.insert('j'); row2.insert('k'); row2.insert('l');

        row3.insert('z'); row3.insert('x'); row3.insert('c'); row3.insert('v'); row3.insert('b'); row3.insert('n'); row3.insert('m');

        vector<string> result;

        for(string &s : words)
        {
            bool isTrue = true;
            if(row1.contains(to_lower(s[0])))
            {
                for(char &c : s)
                {
                    if(!row1.contains(to_lower(c)))
                    isTrue = false;
                }

                if(isTrue)
                result.push_back(s);

            }

            else if(row2.contains(to_lower(s[0])))
            {
                for(char &c : s)
                {
                    if(!row2.contains(to_lower(c)))
                    isTrue = false;
                }

                if(isTrue)
                result.push_back(s);
            }

            else
            {
                for(char &c : s)
                {
                    if(!row3.contains(to_lower(c)))
                    isTrue = false;
                }

                if(isTrue)
                result.push_back(s);

            }
        }
        return result;
    }
};