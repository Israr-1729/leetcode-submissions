class Solution {
public:
    bool isNumber(string s) {
        //checks if there are characters other than e
        for(char c : s)
        {
            if(isalpha(c) && c != 'e' && c != 'E')
            return false;
        }

        //checks the number of e
        int countE = 0;
        for(char c : s)
        {
            if(c=='e' || c=='E')
            countE++;
        }
        if(countE > 1)
        return false;



        //finds the position of 'e'
        int posnE = -1;
        for(int i = 0; i<s.size(); i++)
        {
            if(tolower(s[i]) == 'e')
            {
                posnE = i;
                break;
            }
        }

        //checks if 'e' is at the first or last position 
        if(tolower(s.front()) == 'e' || tolower(s.back()) == 'e')
        return false;

        //checks if there is anything other than digit/plus/minus after e
        if(posnE != -1)
        {
            if(!isdigit(s[posnE-1]) && s[posnE-1] != '.')
            return false;

            if(s[posnE -1] == '.')
            {
                if(posnE == 1)
                return false;

                if(!isdigit(s[posnE-2]))
                return false;
            }

            if(!isdigit(s[posnE+1]) && s[posnE+1] != '+' && s[posnE+1] != '-')
            return false;

            //if there is '+' or '-' after e, then it should be followed by a digit
            if(s[posnE+1] == '+' || s[posnE+1] == '-')
            {
                if(posnE == s.size() - 2)
                return false;

                if(!isdigit(s[posnE + 2]))
                return false;
            }
        }

        //Decimal Point

        //if number of decimal points is greater than 1, return false.
        int decimalPoints = 0;
        for(char c : s)
        {
            if(c == '.')
            decimalPoints++;

            if(decimalPoints > 1)
            return false;
        }

        //if decimal comes after posn of e, return false. (If e exists)
        if(posnE != -1)
        {
            for(int i = posnE; i<s.size(); i++)
            {
                if(s[i]=='.')
                return false;
            }
        }

        //if '.' is alone
        if(s.size() == 1 && s[0] == '.')
        return false;

        //Signs
        //Counts number of plus and minus signs
        int signsCount = 0;
        for(char c : s)
        {
            if(c == '+' || c=='-')
            signsCount++;
        }

        if(signsCount > 2)
        return false;
        //0 if there are no decimal points
        //1 if there is a decimal point. either at the beginning or right after e
        //2 if there are two decimal points. one at beginning and other than e

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '+' || s[i]=='-')
            {
                if(i == 0)
                continue;

                else
                {
                    if(tolower(s[i-1]) != 'e')
                    return false;
                }
            }
        }

        //if it contains no digit at all
        bool found = false;
        for(char c : s)
        {
            if(isdigit(c))
            found = true;
        }

        if(!found)
        return false;


    return true;
        
    }
};