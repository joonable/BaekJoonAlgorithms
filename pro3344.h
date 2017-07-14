//
// Created by JoonYoung Jeon on 14/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO3344_H
#define BAEKJOONALGORITHMS_PRO3344_H

#include <iostream>
using namespace std;
int N;
int col[100000];

bool Promising(int i){
    int k = 0;
    bool promising = true;

    while( k < i && promising){
        if( col[i] == col[k] || abs(col[i] - col[k]) == i - k){
            promising = false;
        }
        k++;
    }
    return promising;
}

void Queens(int i){
    if(Promising(i)){
        if( i == N - 1  ){
            for( int j = 0 ; j < N ; ++j ){
                printf("%d\n", col[j]+1);
            }
            exit(0);
        }
        else{
            for( int j = 0 ; j < N ; ++j ){
                col[i + 1] = j;
                Queens(i + 1);
            }
        }
    }
}


int pro3344(){
    cin>>N;
    Queens(-1);
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO3344_H
