//
// Created by JoonYoung Jeon on 10/08/2017.
//

#ifndef BOOSTTEST_PRO1753_H
#define BOOSTTEST_PRO1753_H
// Program to find Dijkstra's shortest path using
// priority_queue in STL
#define INF 987654321
#include <iostream>
#include <list>
#include <queue>

using namespace std;

// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

// This class represents a directed graph using
// adjacency list representation
class Graph{
    int V;    // No. of vertices

    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list<iPair> *adj;

public:
    // Constructor - Allocates memory for adjacency list
    Graph(int V){
        this->V = V;
        adj = new list<iPair>[V];
    }

    // function to add an edge to graph
    void addEdge(int u, int v, int w){
        adj[u].emplace_back(iPair(v, w));
//        adj[v].push_back(iPair(u, w));
    }

    // Prints shortest paths from src to all other vertices
    void shortestPath(int src){
        // Create a priority queue to store vertices that
        // are being preprocessed. This is weird syntax in C++.
        // Refer below link for details of this syntax
        // http://geeksquiz.com/implement-min-heap-using-stl/
        priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

        // Create a vector for distances and initialize all
        // distances as infinite (INF)
        vector<int> dist(V, INF);

        // Insert source itself in priority queue and initialize
        // its distance as 0.
        pq.push(make_pair(0, src));
        dist[src] = 0;

        /* Looping till priority queue becomes empty (or all
          distances are not finalized) */
        while (!pq.empty())
        {
            // The first vertex in pair is the minimum distance
            // vertex, extract it from priority queue.
            // vertex label is stored in second of pair (it
            // has to be done this way to keep the vertices
            // sorted distance (distance must be first item
            // in pair)
            int u = pq.top().second;
            pq.pop();

            // 'i' is used to get all adjacent vertices of a vertex
//            list< pair<int, int> >::iterator i;
            for( auto& element : adj[u] ){
                // Get vertex label and weight of current adjacent
                // of u.
                int v = element.first;
                int weight = element.second;

                //  If there is shorted path to v through u.
                if (dist[v] > dist[u] + weight){
                    // Updating distance of v
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        // Print shortest distances stored in dist[]
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < V; ++i){
            if (dist[i] == INF){
                printf("INF\n");
            }
            else{
                printf("%d\n", dist[i]);
            }
        }

    }
};

// Driver program to test methods of graph class
int pro1753(){
    // create the graph given in above fugure
    int V, M, u, v, w, src;   cin>>V>>M>>src;
    Graph g(V);

    for( int i = 0 ; i < M ; ++i ){
        scanf("%d %d %d",&u, &v, &w);
        g.addEdge(u - 1, v - 1, w);
    }

    g.shortestPath(src - 1);

    return 0;
}
#endif //BOOSTTEST_PRO1753_H
