#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include <vector>
#include <algorithm>
using namespace std;

class SparseGraph{
public:
    SparseGraph() {
        v.resize(3);
    }

    SparseGraph(int n_in) {
        v.resize(n_in);
    }

    SparseGraph(const SparseGraph& G) {
        v.clear();
        for(auto itr = G.v.begin();itr!=G.v.end();itr++){
            v.push_back(*itr);
        }
    }

    void AddEdge(int a, int b) {
        if(find(v[a].begin(),v[a].end(),b)==v[a].end()){
            v[a].push_back(b);
        }
    }

    void RemoveEdge(int a, int b) {
        auto itr = find(v[a].begin(),v[a].end(),b);
        if(itr!=v[a].end()){
            v[a].erase(itr);
        }
    }

    bool DoesEdgeExist(int a, int b) const {
        auto itr = find(v[a].begin(),v[a].end(),b);
        if(itr!=v[a].end()) return true;
        return false;
    }

    SparseGraph Transpose() const {
        SparseGraph t(v.size());
        for(int i=0;i<v.size();i++){
            for(auto itr = v[i].begin(); itr!=v[i].end();itr++){
                t.AddEdge(*itr,i);
            }
        }
        return t;
    }

protected:
    // Your code here
    vector<vector<int>> v;
};
#endif // __SPARSE_GRAPH_H__

