class Solution {

    vector<int> sequentialNumbers;

public:
    long long toll(string s) {
        reverse(s.begin(), s.end());
        long long ans = 0;
        int i = s.size() - 1;

        while (i >= 0) {
            ans = ans * 10 + (s[i] - '0');
            i--;
        }

        return ans;
    }

    void generateSequentialNumbers() {
        for (int i = 1; i <= 9; i++) {
            string start = to_string(i);
            int idx = i+1;

            while (idx <= 9) {
                start.push_back(idx + '0');
                long long num = toll(start);
                if (num > INT_MAX)
                    break;
                else
                    sequentialNumbers.push_back(num);
                idx++;
            }
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        generateSequentialNumbers();
        vector<int> result;
        for (int a : sequentialNumbers) {
            if (a >= low && a <= high) {
                result.push_back(a);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};