class Solution {
public:
    string digitSum(string s, int k) {

        if(s.size()<=k)
        return s;
        int size = s.size();
        int numOfGroups = (size + k - 1)/k;
        vector<string> Groups(numOfGroups);
        int j = 0;
        for (int i = 0; i < numOfGroups; i++) {
            string thisGroup = "";
            int count = 0;
            while (j < size && count < k) {
                thisGroup += (s[j++]);
                count++;
            }
            Groups[i] = thisGroup;
        }
        if (j < size) {
            string extraString = "";
            while (j < size) {
                extraString += (s[j]);
                j++;
            }
            Groups[numOfGroups - 1] = extraString;
        }

        for (int i = 0; i < numOfGroups; i++) {
            int sum = 0;
            for (int j = 0; j < Groups[i].size(); j++)
                sum += Groups[i][j] - '0';
            Groups[i] = to_string(sum);
        }

        string result = "";
        for (int i = 0; i < numOfGroups; i++) {
            result += Groups[i];
        }
        return digitSum(result,k);
    }
};