class Solution {
public:
    set<int> isSeen;

    bool isHappy(int n) {

        if(n==1)
        return true;
        isSeen.insert(n);
        int copy = n;
        int next = 0;
        while(copy!=0)
        {
            next += (copy%10)*(copy%10);
            copy/=10;
        }
        if(isSeen.find(next)!=isSeen.end())
        return false;
        else
        {
        isSeen.insert(next);
        }
        return isHappy(next);
    }
};