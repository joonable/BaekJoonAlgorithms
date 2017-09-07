//
// Created by JoonYoung Jeon on 04/09/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2188_H
#define BAEKJOONALGORITHMS_PRO2188_H
// C++ implementation of Hopcroft Karp algorithm for
// maximum matching
#include <iostream>
#include <list>
#include <queue>

using namespace std;
#define NIL 0
#define INF INT_MAX

// A class to represent Bipartite graph for Hopcroft Karp implementation
class BipGraph{
    // m and n are number of vertices
    // on left and right sides of Bipartite Graph
    int m, n;

    // adj[u] stores adjacents of left side vertex 'u'.
    // The value of u ranges from 1 to m.
    // 0 is used for dummy vertex
    list<int>* adj;

    // These are basically pointers to arrays needed for hopcroftKarp()
    int* pairU, * pairV, * dist;

public:
    BipGraph( int m, int n ){
        this->m = m;
        this->n = n;
        adj = new list<int>[m + 1];
    }

    void AddEdge( int u, int v ){
        adj[u].push_back(v); // Add u to v’s list.
        adj[v].push_back(u); // Add u to v’s list.
    }

// Returns true if there is an augmenting path, else returns false
    bool BFS(){
        queue<int> Q; //an integer queue

        // First layer of vertices (set distance as 0)
        for( int u = 1 ; u <= m ; u++ ){
            // If this is a free vertex, add it to queue
            if( pairU[u] == NIL ){
                // u is not matched
                dist[u] = 0;
                Q.push(u);
            }
            else dist[u] = INF;
            // Else set distance as infinite
            // so that this vertex is considered next time
        }

        // Initialize distance to NIL as infinite
        dist[NIL] = INF;

        // Q is going to contain vertices of left side only.
        while( !Q.empty( ) ){
            // Dequeue a vertex
            int u = Q.front( );
            Q.pop( );

            // If this node is not NIL and can provide a shorter path to NIL
            if( dist[u] < dist[NIL] ){
                // Get all adjacent vertices of the dequeued vertex u
                for( auto& element: adj[u] ){
                    int v = element;
                    // If pair of v is not considered so far
                    // (v, pairV[V]) is not yet explored edge.
                    if( dist[pairV[v]] == INF ){
                        // Consider the pair and add it to queue
                        dist[pairV[v]] = dist[u] + 1;
                        Q.push(pairV[v]);
                    }
                }
            }
        }

        // If we could come back to NIL using alternating path of distinct
        // vertices then there is an augmenting path
        return ( dist[NIL] != INF );
    }

    // Adds augmenting path if there is one beginning with u
    // Returns true if there is an augmenting path beginning with free vertex u
    bool DFS( int u ){
        if( u != NIL ){
            for( auto& element: adj[u] ){
                // Adjacent to u
                int v = element;

                // Follow the distances set by BFS
                if( dist[pairV[v]] == dist[u] + 1 ){
                    // If dfs for pair of v also returns rue
                    if( DFS(pairV[v]) ){
                        pairV[v] = u;
                        pairU[u] = v;
                        return true;
                    }
                }
            }
            // If there is no augmenting path beginning with u.
            dist[u] = INF;
            return false;
        }
        return true;
    }

    // Returns size of maximum matcing
    int HopcroftKarp(){
        // pairU[u] stores pair of u in matching where u
        // is a vertex on left side of Bipartite Graph.
        // If u doesn't have any pair, then pairU[u] is NIL
        pairU = new int[m + 1];

        // pairV[v] stores pair of v in matching.
        // If v doesn't have any pair, then pairU[v] is NIL
        pairV = new int[n + 1];

        // dist[u] stores distance of left side vertices
        // dist[u] is one more than dist[u'] if u is next
        // to u'in augmenting path
        dist = new int[m + 1];

        // Initialize NIL as pair of all vertices
        for( int u = 0 ; u < m ; u++ )
            pairU[u] = NIL;
        for( int v = 0 ; v < n ; v++ )
            pairV[v] = NIL;

        // Initialize result
        int result = 0;

        // Keep updating the result while there is an augmenting path.
        while( BFS() ){
            // Find a free vertex
            for( int u = 1 ; u <= m ; u++ ){
                // If current vertex is free and there is
                // an augmenting path from current vertex
                if( pairU[u] == NIL && DFS(u) )
                    result++;
            }
        }
        return result;
    };
};

// Driver Program
int main(){
    BipGraph g(4, 4);
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(2, 1);
    g.AddEdge(3, 2);
    g.AddEdge(4, 2);
    g.AddEdge(4, 4);

    cout<<"Size of maximum matching is "<<g.HopcroftKarp( );

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2188_H
