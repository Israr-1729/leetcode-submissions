class Solution {
public:
    unordered_map<int, Employee*> mp;

    int dfs(int id)
    {
        Employee* emp = mp[id];

        int importance = emp->importance;

        for(int sub : emp->subordinates)
            importance += dfs(sub);

        return importance;
    }

    int getImportance(vector<Employee*> employees, int id)
    {
        for(Employee* emp : employees)
            mp[emp->id] = emp;

        return dfs(id);
    }
};