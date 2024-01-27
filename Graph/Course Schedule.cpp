//You have to complete n courses. There are m requirements of the form "course a has to be completed before course b". Your task is to find an order in which you can complete the courses.
//Print an order in which you can complete the courses. You can print any valid order that includes all the courses.If there are no solutions, print "IMPOSSIBLE".
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Graph {
    public:
    int numCourses;
    vector<vector<int>> adj;
    vector<int> inDegree;

    Graph(int n) : numCourses(n), adj(n), inDegree(n, 0) {}

    void addEdge(int a, int b) {
        adj[a].push_back(b);
        inDegree[b]++;
    }
    bool topologicalSort(vector<int>& result) {
        stack<int> s;

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                s.push(i);
            }
        }
        while (!s.empty()) {
            int course = s.top();
            s.pop();
            result.push_back(course);

            for (int neighbor : adj[course]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    s.push(neighbor);
                }
            }
        }
        return result.size() == numCourses;
    }
};
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    Graph g(numCourses);

    for (const vector<int>& prereq : prerequisites) {
        g.addEdge(prereq[1], prereq[0]);
    }
    vector<int> order;
    if (g.topologicalSort(order))
        return order;
    else {
        return {};
    }
}
int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> order = findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << "Order to complete the courses: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }
    return 0;
}

