/*
Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

Each process only has one parent process, but may have one or more children processes. This is just
like a tree structure. Only one process has PPID that is 0, which means this process has no parent
process. All the PIDs will be distinct positive integers.

We use two list of integers to represent a list of processes, where the first list contains PID for
each process and the second list contains the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of
processes that will be killed in the end. You should assume that when a process is killed, all its
children processes will be killed. No order is required for the final answer.

Example 1:
Input:
pid =  [1, 3, 10, 5]
ppid = [3, 0, 5, 3]
kill = 5
Output: [5,10]
Explanation:
           3
         /   \
        1     5
             /
            10
Kill 5 will also kill 10.
Note:
The given kill id is guaranteed to be one of the given PIDs.
n >= 1.
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::map;

class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> result;
        map<int, vector<int>> trees;
        for(int i = 0 ; i < ppid.size(); i++) {
            trees[ppid[i]].push_back(pid[i]);
        }
        int temp;
        deque<int> processes = {kill};
        while(!processes.empty()) {
            temp = processes.front();
            processes.pop_front();
            result.push_back(temp);
            for(auto x : trees[temp]) {
                processes.push_back(x);
            }
        }
        return result;
    }
    vector<int> killProcess_(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> result;
        deque<int> processes;
        int temp;
        processes.push_back(kill);
        while(!processes.empty()) {
            temp = processes.front();
            processes.pop_front();
            result.push_back(temp);
            for(int i = 0 ; i < ppid.size(); i++) {
                if(ppid[i] == temp) {
                    processes.push_back(pid[i]);
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> pid = {1, 3, 10, 5};
    vector<int> ppid = {3, 0, 5, 3};
    Solution slt;
    vector<int> ret = slt.killProcess(pid, ppid, 3);
    for(auto x : ret) {
        cout<<x<<",";
    }
    cout<<endl;
    cout<<"[1";
    for(int i = 2; i < 100; i++){
        cout<<","<<i;
    }
    cout<<"]"<<endl;
    cout<<"[0";
    for(int i = 1; i < 99; i++)
        cout<<","<<i;
    cout<<"]"<<endl;
    return 0;
}
