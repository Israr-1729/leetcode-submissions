// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        if(isBadVersion(1))
        return 1;
        int i = n;
        while(isBadVersion(i))
        {
            i--;
        }
        return i+1;
    }
};