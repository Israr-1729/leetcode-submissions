class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for (char c : s) {
            if (c != '*') {
                st.push(c);
            } else {
                st.pop();
            }
        }

        string result = "";

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};