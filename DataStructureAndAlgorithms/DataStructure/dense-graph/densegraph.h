#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        n=0;
    }

    DenseGraph(int n_in) {
        n=0;
    }

    DenseGraph(const DenseGraph& G) {
        e = G.e;
        n = G.n;
    }

    void AddEdge(int a, int b) {
        pair<int,int> searchpair = make_pair(a,b);
        if(e.find(searchpair)==e.end()) e.insert(searchpair);
    }

    void RemoveEdge(int a, int b) {
        pair<int,int> searchpair = make_pair(a,b);
        auto itr = e.find(searchpair);
        if(itr!=e.end()) e.erase(itr);
    }

    bool DoesEdgeExist(int a, int b) const {
        pair<int,int> searchpair = make_pair(a,b);
        auto itr = e.find(searchpair);
        if(itr!=e.end()) return true;
        return false;
    }

    DenseGraph Transpose() const {
        DenseGraph t;
        for(auto itr = e.begin();itr!=e.end();itr++){
            t.e.insert(make_pair(itr->second,itr->first));
        }
        return t;
    }

protected:
    int n;
    set<pair<int,int>> e;
};
#endif // __DENSE_GRAPH_H__
