//
// Created by JoonYoung Jeon on 17/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11404_H
#define BAEKJOONALGORITHMS_PRO11404_H
#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 100001;

using namespace std;

int pro11404(){
    int N, M, a, b, c;       cin>>N>>M;
    vector< vector<int> > d(N, vector<int>(N, INF));

    for( int i = 0 ; i < M ; ++i ){
        scanf("%d %d %d", &a, &b, &c);
        a--, b--;
        d[a][b] = min(d[a][b], c);
    }

    for( int k = 0 ; k < N ; ++k ){
        for( int i = 0 ; i < N ; ++i ){
            for( int j = 0 ; j < N ; ++j ){
                if(i == j){
                    continue;
                }
                d[i][j] = min( d[i][k] + d[k][j], d[i][j]);
            }
        }
    }

    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < N ; ++j ){
            if(d[i][j] == INF){
                printf("0 ");
                continue;
            }
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO11404_H
