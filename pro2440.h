//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2440_H
#define BAEKJOONALGORITHMS_PRO2440_H
#include <iostream>
using namespace std;

int pro2440(){
    int N;      cin>>N;
    for ( int i = N ; i > 0 ; --i ) {
        for ( int j = i ; j > 0  ; --j ) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO2440_H
