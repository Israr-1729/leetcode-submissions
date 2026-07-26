class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> morseWords;
        vector<string> morseLetters = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(string &s : words)
        {
            string morse = "";
            for(char c : s)
            {
                morse += morseLetters[c-'a'];
            }
            morseWords.insert(morse);
        }
        return morseWords.size();
    }
};