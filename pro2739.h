//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2739_H
#define BAEKJOONALGORITHMS_PRO2739_H
#include <iostream>
using namespace std;

int pro2739(){
    int N;
    cin>>N;
    for ( int i = 1 ; i < 10 ; ++i ) {
        printf("%d * %d = %d\n", N, i, N * i);
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2739_H
