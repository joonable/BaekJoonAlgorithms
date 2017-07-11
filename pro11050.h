//
// Created by JoonYoung Jeon on 11/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11050_H
#define BAEKJOONALGORITHMS_PRO11050_H

#include <iostream>
using namespace std;

int pro11050(){
    int dividend = 1, divisor = 1;
    int n, k;       cin>>n>>k;
    for( int i = 0 ; i < k ; ++i ){
        dividend *= (n - i);
    }
    for( int i = 0 ; i < k ; ++i ){
        divisor *= (i + 1);
    }
    printf("%d", dividend / divisor);
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO11050_H
