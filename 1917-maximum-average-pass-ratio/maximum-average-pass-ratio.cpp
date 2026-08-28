class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<
            pair<double, int>
        > pq;

        for (int i = 0; i < classes.size(); i++) {
            double p = classes[i][0];
            double t = classes[i][1];

            double change = (p + 1) / (t + 1) - p / t;

            pq.push({change, i});
        }

        while (extraStudents--) {
            auto [change, i] = pq.top();
            pq.pop();

            classes[i][0]++;
            classes[i][1]++;

            double p = classes[i][0];
            double t = classes[i][1];

            double newChange =
                (p + 1) / (t + 1) - p / t;

            pq.push({newChange, i});
        }

        double sum = 0;

        for (auto &a : classes) {
            sum += (double)a[0] / a[1];
        }

        return sum / classes.size();
    }
};