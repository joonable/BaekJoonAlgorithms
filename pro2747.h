//
// Created by JoonYoung Jeon on 10/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2747_H
#define BAEKJOONALGORITHMS_PRO2747_H

#include <iostream>
using namespace std;


int pro2747(){
    int arr[45];

    arr[0] = 0;     arr[1] = 1;

    int n;      cin>>n;

    for( int i = 2 ; i < n + 1 ; ++i ){
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    cout<<arr[n];
}

#endif //BAEKJOONALGORITHMS_PRO2747_H
