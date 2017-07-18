//
// Created by JoonYoung Jeon on 17/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2749_H
#define BAEKJOONALGORITHMS_PRO2749_H

#include <iostream>
using namespace std;
int A[2][2] = {1, 1, 1, 0};

void mul(int B[2][2]){
    int temp[2][2];
    temp[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    temp[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    temp[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    temp[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];

    A[0][0] = temp[0][0] % 1000000;
    A[0][1] = temp[0][1] % 1000000;
    A[1][0] = temp[1][0] % 1000000;
    A[1][1] = temp[1][1] % 1000000;
}

void power(int n){
    if(n == 1){
//        re
    }
    if( n % 2 == 0){
        power(n / 2);
    }
    else{

    }
}

int pro2749(){
    unsigned long N;    cin>>N;


    int& a = A[0][0];
    int& b = A[0][1];
    int& c = A[1][0];
    int& d = A[1][1];

    int B[2][2] = {1, 1, 1, 0};

    int& a_ = B[0][0];
    int& b_ = B[0][1];
    int& c_ = B[1][0];
    int& d_ = B[1][1];

    for( int i = 1 ; i < N ; ++i ){
        int temp[2][2];
        temp[0][0] = a_ * a + b_ * c;
        temp[0][1] = a_ * b + b_ * d;
        temp[1][0] = c_ * a + d_ * c;
        temp[1][1] = c_ * b + d_ * d;

        a_ = temp[0][0] % 1000000;
        b_ = temp[0][1] % 1000000;
        c_ = temp[1][0] % 1000000;
        d_ = temp[1][1] % 1000000;
    }

    cout<<b_;

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2749_H
