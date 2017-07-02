//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11720_H
#define BAEKJOONALGORITHMS_PRO11720_H
#include <iostream>

using namespace std;

int pro11720(){
    int N, sum = 0;
    char arr[100];
    cin>>N>>arr;

    for ( int i = 0 ; i < N ; ++i ) {
        sum += (int)arr[i] - 48;
    }
    cout<<sum;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO11720_H
