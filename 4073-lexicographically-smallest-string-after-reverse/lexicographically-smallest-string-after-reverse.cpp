class Solution {
public:
    string lexSmallest(string s) {

        string smallest = s;


        //d    c    a    b
        //0    1    2    3
        //4
        for(int i = 1; i <= s.size(); i++)
        {
            string left = s.substr(0, i);
            string right = s.substr(i, s.size() - i + 1);
            string rightReverse = right;

            reverse(rightReverse.begin(), rightReverse.end());

            string one = left + rightReverse;

            reverse(left.begin(), left.end());

            string two = left + right;

            if(one < smallest)
            {
                smallest = one;
            }

            if(two < smallest)
            {
                smallest = two;
            }

        }
        return smallest;
    }
};