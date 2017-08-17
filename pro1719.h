//
// Created by JoonYoung Jeon on 10/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1719_H
#define BAEKJOONALGORITHMS_PRO1719_H

#include <iostream>
#include <vector>
using namespace std;

int N;
const int INF = 2012345678;

struct Edge{
    int src, dest, weight;
    Edge(int src = 0, int dest = 0, int weight = 0)
            : src(src), dest(dest), weight(weight){ }
};

void dijkstra(const vector<vector<int>>& W, int src = 0){
    vector<int> length(N);
    vector<int> first_touch(N);
    vector<int> last_touch(N);
    vector<Edge> F;

    for( int i = 0 ; i < N ; ++i ){
        last_touch[i] = src;
        first_touch[i] = src;
        length[i] = W[src][i];
    }

    length[src] = -1;
    first_touch[src] = -1;

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

        F.emplace_back( Edge( last_touch[min_idx], min_idx, W[last_touch[min_idx]][min_idx] ) );

        if (min == INF){
            continue;
        }

        for( int i = 0 ; i < N ; ++i ){
            if(min + W[min_idx][i] < length[i]){
                length[i] = min + W[min_idx][i];
                last_touch[i] = min_idx;
            }
        }
        length[min_idx] = -1;
    }


    for( int n = 0 ; n < N ; ++n ){
        if (n == src)
            continue;

        int idx = last_touch[n];

        if (idx == src){
            first_touch[n] = n;
            continue;
        }

        while( true ){
            if(last_touch[idx] == src){
                first_touch[n] = idx;
                break;
            }
            idx = last_touch[idx];
        }
    }

    for( int i = 0 ; i < N ; ++i ){
        if(i == src)
            printf("- ");
        else
            printf("%d ", first_touch[i] + 1);
    }
    printf("\n");
}

int pro1719(){
    int M;      cin>>N>>M;
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
