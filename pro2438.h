//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2438_H
#define BAEKJOONALGORITHMS_PRO2438_H
#include <iostream>
using namespace std;

int pro2438(){
    int N;  cin>>N;
    for ( int i = 1 ; i < N + 1 ; ++i ) {
        for ( int j = 1 ; j < i + 1  ; ++j ) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO2438_H
