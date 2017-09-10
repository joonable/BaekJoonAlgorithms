//
// Created by JoonYoung Jeon on 08/09/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1766_H
#define BAEKJOONALGORITHMS_PRO1766_H
#include <iostream>
#include <vector>
#include <array>
#include <stack>

using namespace std;
typedef pair<int, int> iPair;
int N;

class Graph{
    const int V;
    vector<int>* adj;
    void DFS( int u, vector<bool>& visited, stack<int>& Stack ){
        Stack.push(u);
        visited[u] = true;
        for( auto& v : adj[u] ){
            if(!visited[v]) {
                DFS(v, visited, Stack);
            }
        }
    }
public:
    Graph( int V ) : V(V){
        adj = new vector<int>[V];
    }
    void AddEdge(int u, int v){
        adj[u].push_back(v);
    }

    void TopologicalSort(){
        stack<int> Stack;
        vector<bool> visited(V, false);

        for( int u = 0 ; u < V ; ++u ){
            if( !visited[u] ){
                DFS(u, visited, Stack);
                while(!Stack.empty()){
                    cout<<Stack.top() + 1<<" ";
                    Stack.pop();
                }
            }
        }
    }
};

int pro1766(){
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
#endif //BAEKJOONALGORITHMS_PRO1766_H
