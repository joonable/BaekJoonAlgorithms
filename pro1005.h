//
// Created by JoonYoung Jeon on 23/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1005_H
#define BAEKJOONALGORITHMS_PRO1005_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef pair<int, int> iPair;

class Graph{
private:
    int V;
    vector<int> nodes;
    vector<vector<int>> adj;
    vector<iPair> degree;
    //out, in
public:
    Graph(int V) : V(V){
        nodes.resize(V);
        adj.resize(V, vector<int>(V, 0));
        degree.resize(V);
    }

    void SetNode(int i, int weight){
        nodes[i] = weight;
    }

    void AddEdge(int u, int v){
        adj[u][v] = nodes[v];
        degree[u].second++;
        degree[v].first++;
    }

    void SortDegree(){
        sort(degree.begin(), degree.end());
    }
};

int pro1005(){
    int T;      cin>>T;
    for( int t = 0 ; t < T ; ++t ){
        int N, E;

        Graph buildings(N);

        int weight;
        for( int i = 0 ; i < N ; ++i ){
            scanf("%d", &weight);
            buildings.SetNode(i, weight);
        }

        int u, v;
        for( int i = 0 ; i < E ; ++i ){
            scanf("%d" - 1, &u);
            scanf("%d" - 1, &v);
            buildings.AddEdge(u, v);
        }

        buildings.SortDegree();
    }
    
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1005_H
