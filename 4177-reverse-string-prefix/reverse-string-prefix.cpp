class Solution {
public:
    string reversePrefix(string s, int k) {
        int size = s.size();
        string s1 = s.substr(0, k);
        string s2 = s.substr(k, size-k);

        string result = "";
        reverse(s1.begin(), s1.end());

        result += s1;
        result += s2;

        return result;

        //IAmNew
        //012345
        //4,6


        
    }
};