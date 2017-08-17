//
// Created by JoonYoung Jeon on 17/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1389_H
#define BAEKJOONALGORITHMS_PRO1389_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int pro1389(){
    int N, M, u, v;       cin>>N>>M;
    vector< vector<int> > d(N, (vector<int>(N, INF)));
    vector<int> kevinBaconNum(N, 0);
    for( int i = 0 ; i < M ; ++i ){
        scanf("%d %d", &u, &v);
        u--;    v--;
        d[u][v] = 1;
        d[v][u] = 1;
    }

    for( int k = 0 ; k < N ; ++k ){
        for( int i = 0 ; i < N ; ++i ){
            for( int j = 0 ; j < N ; ++j ){
                if (i == j){
                    continue;
                }
                d[i][j] = min( d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int min = 101, minIdx = 0;

    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < N ; ++j ){
            if(d[i][j] == INF){
                continue;
            }
            kevinBaconNum[i] += d[i][j];
        }
//        cout<<kevinBaconNum[i]<<endl;

        if(min > kevinBaconNum[i]){
            min = kevinBaconNum[i];
            minIdx = i;
        }
    }

    cout<<minIdx + 1;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1389_H
