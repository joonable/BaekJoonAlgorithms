//
// Created by JoonYoung Jeon on 10/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1719_H
#define BAEKJOONALGORITHMS_PRO1719_H

#include <iostream>
#include <vector>
using namespace std;

int N;
const int INF = 987654321;

struct Edge{
    int src, dest, weight;
    Edge(int src = 0, int dest = 0, int weight = 0)
            : src(src), dest(dest), weight(weight){ }
};

void dijkstra(const vector<vector<int>>& W, int src = 0){
    vector<int> touch(N);
    vector<int> length(N);
    vector<int> first(N);
    vector<Edge> F;

    for( int i = 0 ; i < N ; ++i ){
        touch[i] = src;
        first[i] = src;
        length[i] = W[src][i];
    }

//    touch[src] = src;
    length[src] = -1;
    first[src] = -1;

//    for( int i = 0 ; i < N ; ++i ){
//        if(i == src)
//            printf("- ");
//        else
//            printf("%d ", touch[i] + 1);
//    }
//    cout<<endl;

//    repeat n-1 times because of the number of edges
    for( int n = 0 ; n < N - 1 ; ++n ){
        int min = INF;
        int min_idx = -1;

        //get minimum and min_idx
        for( int i = 0 ; i < N ; ++i ){
            if( 0 < length[i] && length[i] <= min){
                min_idx = i;
                min = length[min_idx];
            }
        }

        F.emplace_back(Edge(touch[min_idx], min_idx, W[touch[min_idx]][min_idx]));

        if (min == INF){
            continue;
        }

        for( int i = 0 ; i < N ; ++i ){
            if(min + W[min_idx][i] < length[i]){
                length[i] = min + W[min_idx][i];
                touch[i] = min_idx;
            }
        }
        length[min_idx] = -1;
//        for( int i = 0 ; i < N ; ++i ){
//            if(i == src)
//                printf("- ");
//            else
//                printf("%d ", touch[i] + 1);
//        }
//        cout<<endl;
    }

    for( int n = 0 ; n < N ; ++n ){
        if (n == src)
            continue;
        int idx = touch[n];
        if (idx == src){
            first[n] = n;
            continue;
        }

        while( true ){
            if(touch[idx] == src){
                first[n] = idx;
                break;
            }
            idx = touch[idx];
        }
    }

    for( int i = 0 ; i < N ; ++i ){
        if(i == src)
            printf("- ");
        else
            printf("%d ", first[i] + 1);
    }
    printf("\n");
//    for( int i = 0 ; i < N ; ++i ){
//        if(i == src)
//            printf("- ");
//        else
//            printf("%d ", touch[i] + 1);
//    }
//    printf("\n");
}


int pro1719(){
    int M;  cin>>N>>M;
    vector<vector<int>> W(N, vector<int>(N, INF));

    for( int n = 0 ; n < N ; ++n ){
        W[n][n] = 0;
    }

    for( int m = 0 ; m < M ; ++m ){
        int i, j, w;    scanf("%d %d %d", &i, &j, &w);
        W[i-1][j-1] = w;
        W[j-1][i-1] = w;
    }

    for( int n = 0 ; n < N ; ++n ){
        dijkstra(W, n);
    }

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1719_H
