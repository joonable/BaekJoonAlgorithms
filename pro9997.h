//
// Created by JoonYoung Jeon on 31/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9997_H
#define BAEKJOONALGORITHMS_PRO9997_H

#include <iostream>
using namespace std;
#include <cmath>
#include <bitset>
int bitSet[26] = {0};
int N;


void Add(int i, int x){
    bitSet[i] |= (1 << x);
}

void Remove(int i, int x){
    bitSet[i] &= ~(1 << x);
}

void Check(int i, int x){
    if(bitSet[i] & (1 << x)){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}

void Toggle(int i, int x){
    bitSet[i] ^= (1 << x);
}

void All(int i){
    bitSet[i] = (1 << (N+1)) -1;
}

void Empty(int i){
    bitSet[i] = 0;
}

int pro9997(){
    int arr[(int)pow(2, 25) - 1] = {0};
        cin>>N;

    string word;

    for( int n = 0 ; n < N ; ++n ){
        cin>>word;
        for( int i = 0 ; i < word.length() + 1 ; ++i ){
            Add(n, word[i] - 'a');
        }
    }
    int min = 250000;
    for( int i = 0 ; i < 26 ; ++i ){
        if( min > bitSet[i] ){
            min = bitSet[i];
        }
    }
    cout<<min;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO9997_H
