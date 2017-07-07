//
// Created by JoonYoung Jeon on 07/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO10039_H
#define BAEKJOONALGORITHMS_PRO10039_H

#include <iostream>
using namespace std;

const int NUMOFSTUD = 5;

int pro10039(){
    int scores[NUMOFSTUD];
    int sum = 0;
    for ( int i = 0 ; i < NUMOFSTUD ; ++i ) {
        int score;      cin>>score;
        if (score < 40){
            scores[i] = 40;
        }
        else{
            scores[i] = score;
        }
        sum += scores[i];
    }

    printf("%d", sum / 5);

    return 0;
};

#endif //BAEKJOONALGORITHMS_PRO10039_H
