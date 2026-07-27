class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for(char c : brokenLetters)
        {
            broken.insert(c);
        }

        int i = 0; int size = text.size();


        int result = 0;
        while(i<size)
        {
            string thisWord = "";
            while(i<size && text[i] != ' ')
            {
                thisWord += text[i];
                i++;
            }

            bool possible = true;
            for(char c : thisWord)
            {
                if(broken.contains(c))
                {
                    possible = false;
                    break;
                }
            }

            i++; 
            
            if(possible)
            result++;
        }
        return result;
    }
};