//
// Created by JoonYoung Jeon on 08/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2751_H
#define BAEKJOONALGORITHMS_PRO2751_H

#include <iostream>
using namespace std;

int arr[1000000];

void Merge(int low, int mid, int high, int len){
    int temp[len];
    int idx = 0;
    int idx1 = low;
    int idx2 = mid + 1;

    while( true ) {
        if (idx1 > mid || idx2 > high){
            break;
        }

        if (arr[idx1] <= arr[idx2]){
            temp[idx++] = arr[idx1++];
        }
        else {
            temp[idx++] = arr[idx2++];
        }
    }

    if(idx2 > high){
        while(idx < len){
            temp[idx++] =  arr[idx1++];
        }
        for ( int i = 0; i < len ; ++i ) {
            arr[low + i] = temp[i];
        }
    }
    else{
        for ( int i = 0; i < idx; ++i ) {
            arr[low + i] = temp[i];
        }
    }
}

void MergeSort(int low, int high){
    if (low >= high || (low + high) == 0){
        return;
    }
    int mid = (low + high) / 2;
    MergeSort(low, mid);
    MergeSort(mid + 1, high);
    Merge(low, mid, high, high - low + 1);
}

int pro2751(){
    int N;      cin>>N;
    for ( int i = 0 ; i < N ; ++i ) {
        scanf("%d", &arr[i]);
    }
    MergeSort(0, N - 1);

    for ( int i = 0 ; i < N ; ++i ) {
        printf("%d\n", arr[i]);
    }
    return 0;
}



#endif //BAEKJOONALGORITHMS_PRO2751_H
