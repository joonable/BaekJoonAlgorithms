//
// Created by JoonYoung Jeon on 07/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11724_H
#define BAEKJOONALGORITHMS_PRO11724_H

// A simple representation of graph using STL,
// for the purpose of competitive programming
//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
// A utility function to add an edge in an undirected graph.
void addEdge(vector<int>* adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// A utility function to do DFS of graph recursively from a given vertex u.
void DFSUtil(int u, vector<int>* adj, vector<bool> &visited){
    visited[u] = true;
//    cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false){
            DFSUtil(adj[u][i], adj, visited);
        }
}

// This function does DFSUtil() for all unvisited vertices.
void DFS(vector<int> adj[], int V){

    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false){
            DFSUtil(u, adj, visited);
            cnt++;
        }
}

// Driver code
int pro11724(){
    int N, M;   cin>>N>>M;
    int& V = N;

    vector<int> adj[V];
    for( int i = 0 ; i < M ; ++i ){
        int u, v;       cin>>u>>v;
        addEdge(adj, u-1, v-1);
    }

    DFS(adj, V);
    cout<<cnt;
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO11724_H
