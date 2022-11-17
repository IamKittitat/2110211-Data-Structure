#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
#include<bits/stdc++.h>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        // Your code here
        n = 3;
    }

    DenseGraph(int n_in) {
        // Your code here
        n = n_in;
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
        n = G.n;
        for(int i =0;i<n;i++) graph[i] = G.graph[i];
    }

    void AddEdge(int a, int b) {
        // Your code here
        graph[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        graph[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return graph[a].count(b);
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph ans(n);
        for(int i = 0;i<n;i++){
            for(auto &x: graph[i]) ans.graph[x].insert(i);
        }
        return ans;
    }

protected:
    int n;
    // Your code here
    std::set<int> graph[1000];
};
#endif // __DENSE_GRAPH_H__
