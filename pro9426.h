//
// Created by JoonYoung Jeon on 10/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9426_H
#define BAEKJOONALGORITHMS_PRO9426_H

#include <iostream>
#include <algorithm>

using namespace std;

int GetMedian(int len){
    return (len - 1) / 2;
}

int Equal( const void* a, const void* b ){
    return ( *(short*)a - *(short*)b );
}

int pro9426(){
    int N, K;   cin>>N>>K;
    int result = 0;
    unsigned short temperatures[250000];

    for( int i = 0 ; i < N ; ++i ){
        scanf("%hu", &temperatures[i]);
    }
    for( int i = 0 ; i < N - K + 1 ; ++i ){
        unsigned short* temp = new unsigned short[K];
        for( int j = 0 ; j < K ; ++j ){
            temp[j] = temperatures[i + j];
        }
        qsort(temp, K, sizeof(short), Equal);
        int mid = GetMedian(K);
        result += temp[mid];
        delete[](temp);
    }
    cout<<result;
    return 0;
}


#endif //BAEKJOONALGORITHMS_PRO9426_H
