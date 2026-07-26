class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int i = 0;
        int size = employees.size();
        for (i = 0; i < size; i++) {
            if (employees[i]->id == id)
                break;
        }
        if (employees[i]->subordinates.size() == 0)
            return employees[i]->importance;
        else {
            int importance = employees[i]->importance;
            vector<int> subor = employees[i]->subordinates;
            for (int a : subor) {
                importance += getImportance(employees, a);
            }
            return importance;
        }
    }
};