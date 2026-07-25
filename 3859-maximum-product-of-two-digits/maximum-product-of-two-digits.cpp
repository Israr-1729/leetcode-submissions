class Solution {
public:
    int maxProduct(int n) {
        string num = to_string(n);
        sort(num.begin(), num.end());
        int size = num.size();
        return (num[size-1]-'0')*(num[size-2]-'0');
        
    }
};