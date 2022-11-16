#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class SparseGraph{
public:
    SparseGraph() {
        // Your code here
        for(int i=0; i<3; i++) g.push_back(vector<int> ());
    }

    SparseGraph(int n_in) {
        // Your code here
        for(int i=0; i<n_in; i++) g.push_back(vector<int> ());
    }

    SparseGraph(const SparseGraph& G) {
        // Your code here
        g = G.g;
    }

    void AddEdge(int a, int b) {
        // Your code here
        g[a].push_back(b);
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        for(int i=0; i<g[a].size(); i++){
            if(g[a][i] == b) g[a].erase(g[a].begin()+i);
        }
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        for(int i=0; i<g[a].size(); i++){
            if(g[a][i] == b) return true;
        }
        return false;
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph G(g.size());
        for(int i=0; i<g.size(); i++){
            for(int j=0; j<g[i].size(); j++) G.AddEdge(g[i][j], i);
        }
        return G;
    }

protected:
    // Your code here
    int n;
    vector<vector<int> > g;
};
#endif // __SPARSE_GRAPH_H__


