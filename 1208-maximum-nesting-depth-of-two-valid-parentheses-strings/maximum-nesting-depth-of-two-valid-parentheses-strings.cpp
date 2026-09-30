class Solution {
public:
    std::vector<int> maxDepthAfterSplit(std::string& seq) {
        int n = seq.size();
        std::vector<int> r(n, 0);
        int depth = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                depth++;
                r[i] = depth & 1;
                continue;
            }
            r[i] = depth & 1;
            depth--;
        }
        return r;
    }
};