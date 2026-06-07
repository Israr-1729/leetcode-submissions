class Solution {
public:
    string reverseWords(string s) {
        vector<string> arr;
        int size = s.size();
        int i = 0;
        while(i<size)
        {
            string thisResult = "";
            while(i<size && s[i]!=' ')
            {
                thisResult += s[i];
                i++;
            }
            if(thisResult != "")
            arr.push_back(thisResult);
            while(i<size && s[i]==' ')
            {
                i++;
            }
        }
        string finalResult = "";
        int size2 = arr.size();

        for(int j = size2-1; j>=0; j--)
        {
            finalResult += arr[j];
            if(j!=0)
            finalResult += " ";
        }
        return finalResult;
    }
};