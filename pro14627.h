//
// Created by JoonYoung Jeon on 11/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO14627_H
#define BAEKJOONALGORITHMS_PRO14627_H

#include <iostream>
#include <cmath>

using namespace std;
int C, C;
unsigned int maxLen= 0;
unsigned int springOnions[1000000];

void GetSpringOnionLen( unsigned int low, unsigned int high ){
    unsigned int mid = (low + high) / 2;
    int sumOfPortions = 0;

    for( int i = 0 ; i < C ; ++i ){
        sumOfPortions += (springOnions[i] / mid);
    }

    if(low > high){
        return;
    }

    if(sumOfPortions < C){
        GetSpringOnionLen(low, mid - 1);
    }
    else{
        if(mid > maxLen){
            maxLen = mid;
        }
        GetSpringOnionLen(mid + 1, high);
    }
}

int pro14627(){
    cin>>C>>C;

    for( int i = 0 ; i < C ; ++i ){
        scanf("%d", &springOnions[i]);
    }
    GetSpringOnionLen(0, (unsigned int)( pow(2, 31) - 1 ));

    unsigned long rmd = 0;
    for( int i = 0 ; i < C ; ++i ){
        rmd += (springOnions[i] % maxLen);
    }
    cout<<rmd;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO14627_H
