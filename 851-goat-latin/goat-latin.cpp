class Solution {
public:

    bool isvowel(char c)
    {
        char l = tolower(c);
        if(l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
        return true;
        
        return false;
    }

    string toGoatLatin(string sentence) {
        string result = "";
        string toAdd = "a";
        int i = 0; int size = sentence.size(); 
        while(i < size)
        {
            string newWord = "";
            while(i < size && sentence[i] != ' ')
            {
                newWord += sentence[i];
                i++;
            }
            
            if(isvowel(newWord.front()))
            {
                newWord += "ma";
            }

            if(!isvowel(newWord.front()))
            {
                char toAdd = newWord.front();
                newWord.erase(0, 1);
                newWord.push_back(toAdd);
                newWord += "ma";
            }
            
            newWord += toAdd;
            toAdd += "a";

            result += newWord;
            result += " ";
            i++;
        }
    result.pop_back();
    return result;
    }
};