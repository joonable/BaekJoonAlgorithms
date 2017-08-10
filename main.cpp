#include <iostream>
#include <vector>
using namespace std;

//
//struct Edge{
//    int src, dest, weight;
//    Edge(int src = 0, int dest = 0, int weight = 0)
//            : src(src), dest(dest), weight(weight){ }
//};
//
///*
// * Dijkstra's Algorithm
// * Problem : Determine the shortest paths from v1 to all other verticies in a wighted, directed graph
// * Inputs : W(adjacency matrix) - connected, weighted, directed graph containing N verticies
// * Outputs : F set of edges F containing edges in shortest paths
// */
////
////while(the instance is not solved){
//////    V = all verticies {v0, v1, v2, ... , vn-1}
//////    V-Y = {v1, v2, ... , vn-1}
////    select a vertex v from (N - Y), that has a shortest path from v1,
////    using only verticies in Y as intermediates
//////    selection procedure and feasibility check
////
////    add the new vertex v to Y
////    add the edge (on the shortest path) that touches v to F
////
////    if( Y == N ) the instance is solved
//////    solution check
////
////
////}
//void dijkstra(int N, const vector<vector<int>>& W, vector<Edge>& F, int src = 0){
//    const int INF = numeric_limits<int>::max();
//
///*
// * N = num of verticies
// * W = adjacency matrix
// * F = set of shortest path
// * src = source index
// * touch = last edge on the current shortest path from source to vi
// * length = current shortest path from src to vi
// */
//
//    vector<int> touch(N);
//    vector<int> length(N);
//
//    for( int i = 0 ; i < N ; ++i ){
//        touch[i] = 0;
//        length[i] = W[src][i];
//    }
//
//    length[src] = -1;
//
//    //repeat n-1 times because of the number of edges
//    for( int n = 0 ; n < N - 1 ; ++n ){
//        int min = INF;
//        int vnear = -1;
//
//        //get minimum and min_idx
//        for( int i = 0 ; i < N ; ++i ){
//            if( -1 < length[i] && length[i] <= min){
//                vnear = i;
//                min = length[vnear];
//            }
//        }
//
//        F.push_back(Edge(touch[vnear], vnear, W[touch[vnear]][vnear]));
//
//        if (min == INF){
//            continue;
//        }
//
//        for( int i = 0 ; i < N ; ++i ){
//            if(min + W[vnear][i] < length[i]){
//                length[i] = min + W[vnear][i];
//                touch[i] = vnear;
//            }
//        }
//        length[vnear] = -1;
//    }
//}

#include "pro1719.h"

int main() {
    pro1719();
    return 0;
}