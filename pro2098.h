//
// Created by JoonYoung Jeon on 19/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2098_H
#define BAEKJOONALGORITHMS_PRO2098_H

#include <iostream>
using namespace std;

int W[16][16];
int D[16][32768];
int pro2098(){
    int N;      cin>>N;
    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < N ; ++j ){
            scanf("%d", &W[i][j]);
        }
    }

    for( int i = 0 ; i < N ; ++i ){
        D[i][0] = W[i][1];
    }


    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO2098_H
