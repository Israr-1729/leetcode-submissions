class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dx = target[0] - start[0];
        int dy = target[1] - start[1];
        return (dx & 1) == (dy & 1);
    }
};