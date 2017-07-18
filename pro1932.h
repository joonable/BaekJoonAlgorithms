//
// Created by JoonYoung Jeon on 15/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1932_H
#define BAEKJOONALGORITHMS_PRO1932_H

#include <iostream>

using namespace std;
int pro1932(){

    int d[500][500] = {0};
    int n;      cin>>n;

    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j <= i ; ++j ){
            int num;
            scanf("%d", &num);
            d[i][j] = num;
        }
    }

    for( int i = 1 ; i < n ; ++i ){
        d[i][0] += d[i-1][0];

        for( int j = 1 ; j < i ; ++j ){
            if( d[i-1][j-1] > d[i-1][j]){
                d[i][j] += d[i-1][j-1];
            }
            else{
                d[i][j] += d[i-1][j];
            }
        }
        d[i][i] += d[i-1][i-1];
    }

    int max = d[n-1][0];

    for( int i = 1 ; i < n ; ++i ){
        if( d[n-1][i] > max ){
            max = d[n-1][i];
        }
    }

    cout<<max;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1932_H
