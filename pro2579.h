//
// Created by JoonYoung Jeon on 18/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2579_H
#define BAEKJOONALGORITHMS_PRO2579_H

#include <iostream>
#include <cmath>
using namespace std;

int pro2579 (){
    int stair[300] = {0};
    int D[2][300] = {0};

    int N;      cin>>N;
    for( int i = 0 ; i < N ; ++i ){
        scanf("%d", &stair[i]);
    }

    D[0][0] = 0;
    D[1][0] = stair[0];

    D[0][1] = stair[0];
    D[1][1] = D[1][0] + stair[1];

    D[0][2] = D[1][1];
    D[1][2] = max(D[0][0] + stair[1] + stair[2], D[0][1] + stair[2]);

    for( int i = 3 ; i < N - 1 ; ++i ){
        D[0][i] = D[1][i-1];
        D[1][i] = max(D[1][i-2] + stair[i], D[1][i-3] + stair[i-1] + stair[i]);
    }

    D[1][N-1] = max(D[1][N-3] + stair[N-1], D[1][N-4] + stair[N-2] + stair[N-1]);

    cout<<max(D[0][N-1], D[1][N-1]);

    return 0;

}


#endif //BAEKJOONALGORITHMS_PRO2579_H
