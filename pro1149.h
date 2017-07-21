//
// Created by JoonYoung Jeon on 18/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1149_H
#define BAEKJOONALGORITHMS_PRO1149_H

#include <iostream>
#include <algorithm>
using namespace std;

int pro1149(){
    int colour[1000][3];
    int D[1000][3];

    int N;      cin>>N;
    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < 3 ; ++j ){
            scanf("%d", &colour[i][j]);
        }
    }

    for( int j = 0 ; j < 3 ; ++j ){
        D[0][j] = colour[0][j];
    }

    for( int i = 1 ; i < N ; ++i ){
        D[i][0] = min(D[i-1][1], D[i-1][2]) + colour[i][0];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + colour[i][1];
        D[i][2] = min(D[i-1][0], D[i-1][1]) + colour[i][2];
    }

    cout<<min( min(D[N-1][0], D[N-1][1]), D[N-1][2]);
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1149_H
