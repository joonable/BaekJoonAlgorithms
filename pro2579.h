//
// Created by JoonYoung Jeon on 18/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2579_H
#define BAEKJOONALGORITHMS_PRO2579_H

#include <iostream>
using namespace std;

int pro2579(){
    int arr[300] = {0};
    int max[300] = {0};

    int N;      cin>>N;
    for( int i = 0 ; i < N ; ++i ){
        scanf("%d", &arr[i]);
    }
    bool flag = false;
    max[N - 1] = arr[N - 1];
    for( int i = N - 2 ; i > 0 ; --i ){
        if(flag || (arr[i] + max[i + 1] < arr[i - 1] + max[i + i]) ){
            max[i] = arr[i - 1] + max[i + i];
            --i;
            flag = false;
        }
        else{
//            arr[i] + max[i + 1] > arr[i - 1] + max[i + i]
            max[i] = arr[i] + max[i + 1];
            flag = true;
        }
    }
//    cout
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2579_H
