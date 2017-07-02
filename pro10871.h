//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO10871_H
#define BAEKJOONALGORITHMS_PRO10871_H
#include <iostream>
using namespace std;

int pro10871(){
    int N, X, arr[10000];
    cin>>N>>X;
    for ( int i = 0 ; i < N ; ++i ) {
        cin>>arr[i];
    }
    for ( int i = 0 ; i < N ; ++i ) {
        if (arr[i] < X) {
            printf("%d ", arr[i]);
        }
    }
}
#endif //BAEKJOONALGORITHMS_PRO10871_H
