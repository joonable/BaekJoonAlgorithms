//
// Created by JoonYoung Jeon on 02/09/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11657_H
#define BAEKJOONALGORITHMS_PRO11657_H


#include <iostream>
#include <list>
#include <vector>
#define MAX 10001
using namespace std;

typedef pair<int, int> iPair;


struct Edge {
    int src, dest, weight;

    Edge( int src = 0, int dest = 0, int weight = 0 )
            : src(src), dest(dest), weight(weight){ }
};

class Graph{
    int V, E;
    Edge* edge;

public:
    Graph(int V, int E) : V(V), E(E){
        this->edge = new(Edge[this->E]);
    }
    void AddEdge( int m, int u, int v, int w ){
        edge[m] = Edge(u, v, w);
    }
// The main function that finds shortest distances
// from src to all other vertices using Bellman-Ford algorithm.
// The function also detects negative weight cycle
    void BellmanFord(int src){
        // Step 1: Initialize distances from src to all other vertices
        // as INFINITE
//        int dist[V] = {INF};
        vector<int> dist(V, MAX);
        dist[src] = 0;

        // Step 2: Relax all edges |V| - 1 times. A simple shortest
        // path from src to any other vertex can have at-most |V| - 1 edges
        for (int n = 0; n < V; n++) {
            for (int i = 0; i < E; i++) {
                int u = edge[i].src;
                int v = edge[i].dest;
                int weight = edge[i].weight;
                if (dist[u] != MAX && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }


        // Step 3: check for negative-weight cycles.
        // The above step guarantees shortest distances
        // if graph doesn't contain negative weight cycle.
        // If we get a shorter path, then there is a cycle.
        for (int i = 0; i < E; i++) {
            int u = edge[i].src;
            int v = edge[i].dest;
            int weight = edge[i].weight;
            if (dist[u] != MAX && dist[u] + weight < dist[v]){
                cout<<-1;
                return;
            }
        }

        for( int i = 1 ; i < V ; ++i ){
            if( dist[i] == MAX ) {
                cout<<-1<<endl;
                continue;
            }
            cout<<dist[i]<<endl;
        }
    }
};

int pro11657(){
    int N, M;       cin>>N>>M;
    Graph graph(N, M);
    int u, v, weight;
    for( int m = 0 ; m < M ; ++m ){
        scanf("%d %d %d",&u, &v, &weight);
        graph.AddEdge(m, u-1, v-1, weight);
    }
    graph.BellmanFord(0);
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO11657_H
