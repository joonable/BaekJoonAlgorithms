//
// Created by JoonYoung Jeon on 07/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO8958_H
#define BAEKJOONALGORITHMS_PRO8958_H

#include <iostream>
#include <string>
using namespace std;

int pro8958(){
    int score = 0;
    int bonus = 0;
    string str[100];

    int T;      cin>>T;

    for ( int i = 0 ; i < T ; ++i ) {
        cin>>str[i];
    }

    for ( int i = 0 ; i < T ; ++i ) {
        score = 0;
        bonus = 0;
        for ( int j = 0 ; j < str[i].length() ; ++j ) {
            if(str[i][j] == 'X'){
                bonus = 0;
            }
            else{
                score += (1 + bonus++);
            }
        }
        printf("%d\n", score);
    }
}

#endif //BAEKJOONALGORITHMS_PRO8958_H
