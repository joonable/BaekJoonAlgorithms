//
// Created by JoonYoung Jeon on 08/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1197_H
#define BAEKJOONALGORITHMS_PRO1197_H

#include <iostream>
using namespace std;

//#include <map>
//#include <boost/pending/disjoint_sets.hpp>
//
//using namespace boost;
//
//class DisjointSet {
//public:
//    DisjointSet( int numOfNodes);
//    int Find( int element );
//    void Union( int elment_a, int element_b );
//
//private:
//    vector<int> parent, rank;
//};
//
//DisjointSet::DisjointSet(int numOfNodes)
//        : parent(numOfNodes),rank(numOfNodes, 0) {
//    for(int i=0; i<numOfNodes; ++i) {
//        parent[i] = i;
//    }
//}
//
//int DisjointSet::Find( int element ) {
//    if(parent[element] == element) {
//        return element;
//    }
//    //1)path compression
//    return parent[element] = Find(parent[element]);
//}
//
//void DisjointSet::Union( int a, int b ) {
//    if(parent[a] == parent[b]) return;
//    int fa = Find(a), fb = Find(b);
//
//    //2)union by rank
//    if(rank[fa] < rank[fb]) {
//        parent[fa] = fb;
//    }
//    else {
//        parent[fb] = fa;
//
//        if(rank[fa] == rank[fb]){
//            rank[fa]++;
//        }
//    }
//}
//struct Edge{
//    int src, dest, weight;
//};
//
//
//bool cpr(Edge e1, Edge e2){
//    return e1.weight > e2.weight;
//}
//
//int pro1197(){
////    vector< int > vertices(V);
////    multimap< int, pair<int, int> > edges;
//
////    map<pair<int, int>, int > edges;
//    int N, E;       cin>>N>>E;
//
//    DisjointSet dSet(N);
//    vector<Edge> edges(E);
//    vector<int> verticies(N);
//
//    for( Edge& edge : edges){
//        int i, j, weight;
//        scanf("%d %d %d", &i, &j, &weight);
//        edge = {i, j, weight};
//    }
//
//    sort(edges.begin(), edges.end(), cpr);
//
//
//
//    for( Edge& edge : edges){
//        cout<<edge.src<<edge.dest<<" "<<edge.weight<<endl;
//    }
//
//    for( int k = 0 ; k < K ; ++k ){
//
//    }
//
//    return 0;
//}
//
//// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
//// of a given connected, undirected and weighted graph
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // N-> Number of vertices, E-> Number of edges
    int N, E;

    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int N, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->N = N;
    graph->E = E;

    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

        // If ranks are same, then make one as root and increment
        // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    Edge* a1 = (struct Edge*)a;
    Edge* b1 = (struct Edge*)b;
    return (a1->weight > b1->weight);
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
    int N = graph->N;
    struct Edge result[N];  // Tnis will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges

    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

    // Allocate memory for creating N ssubsets
    subset *subsets =
            (subset*) malloc( N * sizeof(subset) );

    // Create N subsets with single elements
    for (int v = 0; v < N; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to N-1
    while (e < N - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }

    // print the contents of result[] to display the built MST
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
               result[i].weight);
}

// Driver program to test above functions
int pro1197(){
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int N = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = createGraph(N, E);


    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 10;

    // add edge 0-2
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    // add edge 0-3
    graph->edge[2].src = 0;
    graph->edge[2].dest = 3;
    graph->edge[2].weight = 5;

    // add edge 1-3
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 15;

    // add edge 2-3
    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 4;

    KruskalMST(graph);

    return 0;
}




#endif //BAEKJOONALGORITHMS_PRO1197_H
