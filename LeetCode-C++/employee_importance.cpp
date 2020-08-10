#include <bits/stdc++.h>
using namespace std;

// problem link : https://leetcode.com/problems/employee-importance/

class Employee {
  public:
    int id;
    int importance;
    vector<int> subordinates;
    Employee(int id, int importance, vector<int> subordinates) {
        this->id = id;
        this->importance = importance;
        this->subordinates = subordinates;
    }
};

class Solution {
  public:
    int getImportance(vector<Employee *> employees, int id) {
        unordered_map<int, Employee *> empMap;
        unordered_map<int, int> mp;
        for (Employee *employee : employees) {
            empMap[employee->id] = employee;
            mp[employee->id] = employee->importance;
        }
        dfs(id, empMap, mp);
        return mp[id];
    }

    void dfs(int empId, unordered_map<int, Employee *> empMap, unordered_map<int, int> &mp) {
        for (int id : empMap[empId]->subordinates) {
            dfs(id, empMap, mp);
            mp[empId] += mp[id];
        }
    }
};

// mock
int main() {
    Solution m;
    Employee *emp1, *emp2, *emp3;
    emp1 = new Employee(1, 5, {2, 3});
    emp2 = new Employee(2, 3, {});
    emp3 = new Employee(3, 3, {});
    vector<Employee *> employees;
    employees.push_back(emp1);
    employees.push_back(emp2);
    employees.push_back(emp3);
    int ans = m.getImportance(employees, 1);
    cout << ans << endl;
    return 0;
}