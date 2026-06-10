class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int sentenceLength = sentence.size();
        vector<string> wordsOfSentence;
        for(int i = 0; i<sentenceLength; i++)
        {
            string thisWord = "";
            while(i<sentenceLength && sentence[i] != ' ')
            {
                thisWord += sentence[i];
                i++;
            }
            wordsOfSentence.push_back(thisWord);
        }

        sort(dictionary.begin(), dictionary.end(),
             [](string &a, string &b) {
                 return a.size() < b.size();
             });

        int wordCount = wordsOfSentence.size();

        string answer = "";

        for(int i = 0; i<wordCount; i++)
        {
            string thisWord = wordsOfSentence[i];
            bool found = false;
            for(int j = 0; j<dictionary.size(); j++)
            {
                found = false;
                string dictionaryWord = dictionary[j];
                if(thisWord.substr(0, dictionaryWord.size())==dictionaryWord)                
                {
                    answer += dictionaryWord + " ";
                    found = true;
                    break;
                }
            }
            if(!found)
            answer += thisWord + " ";
        }
        answer.pop_back();
        return answer;
    }
};