//
// Created by JoonYoung Jeon on 21/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1780_H
#define BAEKJOONALGORITHMS_PRO1780_H

#include <iostream>
#include <cmath>
#include <map>

using namespace std;
map<int, int> cnt;
int arr[2187][2187];

void Divide( int x, int y, int k ){

    if( k == 1){
        cnt[(arr[x][y])]++;
        return;
    }

    bool promising = true;
    for( int i = x ; i < x + k ; ++i ){
        if(promising){
            for( int j = y ; j < y + k ; ++j ){
                if( arr[x][y] != arr[i][j]){
                    promising = false;
                    break;
                }
            }
        }
        else{
            break;
        }
    }

    if (promising){
        cnt[arr[x][y]]++;
    }
    else{
        int k_ = k/3;
        Divide(x, y, k_ );
        Divide(x, y + k_ , k_);
        Divide(x, y + 2*k_ , k_);

        Divide(x + k_ , y, k_);
        Divide(x + k_ , y + k_, k_);
        Divide(x + k_ , y + 2*k_, k_);

        Divide(x + 2*k_ , y , k_);
        Divide(x + 2*k_ , y + k_ , k_);
        Divide(x + 2*k_ , y + 2*k_ , k_);
    }
}

int pro1780(){
    int N;      cin>>N;
    cnt[-1] = 0;
    cnt[0] = 0;
    cnt[1] = 0;
    for( int i = 0 ; i < N ; ++i ){
        for( int j = 0 ; j < N ; ++j ){
            scanf("%d", &arr[i][j]);
        }
    }
    Divide(0, 0, N);

    cout<<cnt[-1]<<endl;
    cout<<cnt[0]<<endl;
    cout<<cnt[1]<<endl;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1780_H
