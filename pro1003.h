//
// Created by JoonYoung Jeon on 10/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1003_H
#define BAEKJOONALGORITHMS_PRO1003_H

#include <iostream>
using namespace std;
int numOfZero = 0, numOfOne = 0;

int fibonacci(int n){
    if( n == 0 ){
        numOfZero++;
        return 0;
    }
    else if (n == 1){
        numOfOne++;
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int pro1003(){
    int T;      cin>>T;

    for( int i = 0 ; i < T ; ++i ){
        int n;      cin>>n;
        numOfZero = 0;      numOfOne = 0;
        fibonacci(n);
        printf("%d %d\n", numOfZero, numOfOne);
    }

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1003_H
