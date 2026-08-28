class Solution {
public:
    string getSmallestString(int n, int k) {
        int pointsLeft = k;
        int lettersLeft = n;
        string result = "";


        while(lettersLeft * 26 >= pointsLeft)
        {
            result += 'a';
            lettersLeft--;
            pointsLeft--;
        }

        if(!result.empty())
        {
        result.pop_back(); lettersLeft++; pointsLeft++;
        result.push_back(0);
        lettersLeft++;
        }

 int toChangeIndex = result.size() - 1;

        while(pointsLeft >= 26)
        {
            result.push_back('z');
            pointsLeft -= 26;
        }

        if(pointsLeft != 0);
        {
            cout<<pointsLeft;
            result[toChangeIndex] = pointsLeft + 'a' - 1;
        }

        string correctAns = "";
        for(char c : result)
        {
            if(isalpha(c))
            correctAns += c;
        }

        return correctAns;

        //cout<<result<<"\n"<<pointsLeft<<"\n"<<lettersLeft;

    }
};