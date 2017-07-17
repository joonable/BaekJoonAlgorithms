//
// Created by JoonYoung Jeon on 15/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1932_H
#define BAEKJOONALGORITHMS_PRO1932_H

#include <iostream>
using namespace std;

int pro1932(){
    char d[500][500];
    int n;      cin>>n;
    int num = n * ( n + 1 ) / 2;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j <= i ; ++j ){
            cin>>d[i][j];
        }
    }
    d[0][0] = 5;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1932_H
