//
// Created by JoonYoung Jeon on 08/09/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2252_H
#define BAEKJOONALGORITHMS_PRO2252_H

#include <iostream>
#include <queue>
#include <vector>
#include <array>

using namespace std;
typedef pair<int, int> iPair;
int N;
class Graph{
    const int V;
    vector<int>* adj;
public:
    Graph( int V ) : V(V){
        adj = new vector<int>[V];
    }
    void AddEdge(int u, int v){
        adj[u].push_back(v);
    }

    void TopologicalSort(){
        vector<int> inDegree(V, 0);
        for( int u = 0 ; u < V ; ++u )
            for( auto& v : adj[u] )
                inDegree[v]++;

        queue<int> Queue;
        for( int i = 0 ; i < V ; ++i )
            if(inDegree[i] == 0) Queue.push(i);

        int tIdx = 0;
        vector<int> topologicalOrder(V);

        while(!Queue.empty()){
            int u = Queue.front();
            Queue.pop();
            topologicalOrder[tIdx++] = u;

            for( auto& v : adj[u] )
                if(--inDegree[v] == 0) Queue.push(v);

//            cnt++;
        }

        for( auto& element : topologicalOrder )
            printf("%d ", element+1);
    }
};

int pro2252(){
    int N, M;       cin>>N>>M;

    Graph graph(N);

    int a, b;
    for( int m = 0 ; m < M ; ++m ){
        scanf("%d %d", &a, &b);
        graph.AddEdge(a - 1, b - 1);
    }

    graph.TopologicalSort( );
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2252_H
