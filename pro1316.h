//
// Created by JoonYoung Jeon on 20/11/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1316_H
#define BAEKJOONALGORITHMS_PRO1316_H

#include <iostream>
#include <array>
#include <string>
using namespace std;

bool IsGroupWord(string word){
    array<bool, 26> alphabets;      alphabets.fill(true);
    int len = (int)word.length();


    if( word[0] != word[1] && word[0] == word[2]){
        return false;
    }

    for( int i = 1 ; i < len ; ++i ){
        if( word[i - 1] != word[i] ){
            if( alphabets[word[i - 1] - 'a'] ){
                alphabets[word[i - 1] - 'a'] = false;
            }
            else {
                return false;
            }
        }
    }

    if ( !alphabets[word[len - 1] - 'a'] ){
        return false;
    }

    return true;
}

int pro1316(){
    int N;      cin>>N;
    int numOfGroupWords = 0;

    for( int i = 0 ; i < N ; ++i ){
        string word;     cin>>word;
        if( IsGroupWord(word) ){
            numOfGroupWords++;
        }
    }

    cout<<numOfGroupWords;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1316_H
