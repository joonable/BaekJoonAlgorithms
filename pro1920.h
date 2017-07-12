//
// Created by JoonYoung Jeon on 12/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1920_H
#define BAEKJOONALGORITHMS_PRO1920_H

#include <iostream>
using namespace std;

int arr[100000];
int num;
bool found;

int Compare( const void* a, const void* b ){
    return ( *(int*)a > *(int*)b );
}
void GetLineLen( int low, int high ){
    int mid = (low + high) / 2;
    if(low > high){
        return;
    }

    if(arr[mid] == num){
        found = true;
        return;
    }
    else if(arr[mid] > num){
        GetLineLen(low, mid - 1);
    }
    else{
        GetLineLen(mid + 1, high);
    }
}

int pro1920(){
    int N;          scanf("%d", &N);
    for( int i = 0 ; i < N ; ++i ){
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), Compare);
    int M;          scanf("%d", &M);

    for( int i = 0 ; i < M ; ++i ){
        scanf("%d", &num);
        found = false;
        GetLineLen(0, N - 1);

        if(found){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1920_H
