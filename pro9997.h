//
// Created by JoonYoung Jeon on 31/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9997_H
#define BAEKJOONALGORITHMS_PRO9997_H

#include <iostream>
using namespace std;

int pro9997(){
    int N;      cin>>N;
    string word;
    int vocabulary[26] = {0};

    for( int n = 0 ; n < N ; ++n ){
        cin>>word;
        for( int i = 0 ; i < word.length() + 1 ; ++i ){
            vocabulary[word[i] - 'a']++;
        }
    }
    int min = 250000;
    for( int i = 0 ; i < 26 ; ++i ){
        if( min > vocabulary[i] ){
            min = vocabulary[i];
        }
    }
    cout<<min;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO9997_H
