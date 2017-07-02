//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO8393_H
#define BAEKJOONALGORITHMS_PRO8393_H
#include <iostream>
using namespace std;

int pro8393(){
    int N, sum = 0;      cin>>N;
    for ( int i = 1 ; i < N + 1 ; ++i ) {
        sum += i;
    }
    cout<<sum;
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO8393_H
