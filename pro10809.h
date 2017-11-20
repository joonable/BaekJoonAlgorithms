//
// Created by JoonYoung Jeon on 20/11/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO10809_H
#define BAEKJOONALGORITHMS_PRO10809_H

#include <iostream>
#include <array>
#include <cstring>

using namespace std;

int pro10809(){
    array<int, 26> alphabets;   alphabets.fill(-1);

    char str[100];      cin>>str;

    int len = (int)strlen(str);
    char ch;

    for( int i = 0 ; i < len ; ++i ){
        ch = str[i];
        if(alphabets[ch - 'a'] == -1 ){
            alphabets[ch - 'a'] = i;
        }
    }

    for ( auto& element : alphabets){
        printf("%d ", element);
    }

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO10809_H
