//
// Created by JoonYoung Jeon on 15/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO10872_H
#define BAEKJOONALGORITHMS_PRO10872_H

#include <iostream>
using namespace std;

int pro10872(){
    int d[13];
    int N;      cin>>N;
    d[0] = 1;
    d[1] = 1;
    for( int i = 2 ; i <= N ; ++i ){
        d[i] = i * d[i-1];
    }
    cout<<d[N];
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO10872_H
