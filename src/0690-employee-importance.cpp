// You have a data structure of employee information, which includes the employee's unique id, their importance value, and their direct subordinates' id.
//
// You are given an array of employees employees where:
//
// - employees[i].id is the ID of the ith employee.
// - employees[i].importance is the importance value of the ith employee.
// - employees[i].subordinates is a list of the IDs of the subordinates of the ith employee.
// 
// Given an integer id that represents the ID of an employee, return the total importance value of this employee and all their subordinates.
//

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        unordered_map<int, Employee*> m;
        for (const auto em : employees) {
            m[em->id] = em;
        }
        deque<int> q;
        q.push_back(id);
        while (!q.empty()) {
            id = q.front();
            q.pop_front();
            ans += m[id]->importance;
            for (const auto k : m[id]->subordinates) {
                q.push_back(k);
            }
        }
        return ans;
    }
};
