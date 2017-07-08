//
// Created by JoonYoung Jeon on 08/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2750_H
#define BAEKJOONALGORITHMS_PRO2750_H

#include <iostream>
using namespace std;

int pro2750(){
    int arr[1000];
    int N;      cin>>N;

    for ( int i = 0 ; i < N ; ++i ) {
        cin>>arr[i];
    }

    for ( int i = 0 ; i < N - 1 ; ++i ) {
        int min = arr[i];
        for ( int j = i + 1 ; j < N ; ++j ) {
            if (arr[j] < min){
                min = arr[j];
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for ( int i = 0 ; i < N ; ++i ) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2750_H
