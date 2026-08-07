class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> encountered;
        pair<int, int> posn;
        posn.first = 0;
        posn.second = 0;

        encountered.insert("0#0");

        for(char c : path)
        {
            switch (c)
            {
                case 'N' : posn.second++; break;
                case 'S' : posn.second--; break;
                case 'E' : posn.first++; break;
                case 'W' : posn.first--; break;
            }

            string newKey = "";
            newKey += to_string(posn.first);
            newKey += "#";
            newKey += to_string(posn.second);

            if(encountered.contains(newKey))
            return true;

            encountered.insert(newKey);
        }
        return false;
    }
};