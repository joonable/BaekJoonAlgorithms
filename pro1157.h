//
// Created by JoonYoung Jeon on 20/11/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1157_H
#define BAEKJOONALGORITHMS_PRO1157_H

#include <iostream>
#include <array>
#include <cstring>

using namespace std;

int pro1157(){
    array<int, 26> alphabets;       alphabets.fill(0);
    char str[1000000];      cin>>str;
    int len = (int)strlen(str);
    char ch;

    for( int i = 0 ; i < len ; ++i ){
        ch = str[i];
        if ('a' <= ch && ch <= 'z'){
            alphabets[ch - 'a']++;
        }
        else {
            alphabets[ch - 'A']++;
        }
    }
    int maxChar = 'A';
    int maxCount = alphabets[0];

    for( int i = 1 ; i < 26 ; ++i ){
        if( maxCount < alphabets[i]){
            maxCount = alphabets[i];
            maxChar = 'A' + i;
        }
        else if( maxCount == alphabets[i]){
            maxChar = '?';
        }
    }
    printf("%c", maxChar);
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1157_H
