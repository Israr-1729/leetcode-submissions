class Solution {
public:
    bool canAliceWin(int n) {
        bool aliceWins = false;
        int i = 10;
        while(n >= i)
        {
            n-=i;
            aliceWins = !aliceWins;
            i--;
        }

        return aliceWins;
    }
};