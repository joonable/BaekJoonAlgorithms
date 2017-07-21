//
// Created by JoonYoung Jeon on 19/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2098_H
#define BAEKJOONALGORITHMS_PRO2098_H

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <cmath>

using namespace std;


const int MAX = 16;
int W[MAX][MAX];
//int D[MAX][32768];
int pro2098(){
    int N;          cin>>N;

    array< array<int, MAX>, MAX> W = {0};
    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < N ; ++j ){
            scanf("%d", &W[i][j]);
        }
    }

    map< bitset<MAX>, vector<int> > D;
    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < N ; ++j ){
            scanf("%d", &W[i][j]);
        }
    }

//    D.insert(0, vector<int>() );
    for( int i = 0 ; i < N ; ++i ){
        vector<int> temp;
        int j = 0;
        for( int k = 0 ; k < N ; ++k ){
            temp[k]= W[k][0];
        }
        D[i] = temp;
    }


    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO2098_H
