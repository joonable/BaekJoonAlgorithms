//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO4344_H
#define BAEKJOONALGORITHMS_PRO4344_H
#include <iostream>
using namespace std;

int pro4344(){
    int score[100][1000], numOfStud, testCase;
    double avg[100] = {0}, percentage[100] = {0}, cnt;
    cin>>testCase;

    for ( int i = 0 ; i < testCase ; ++i ) {
        cnt = 0;
        cin>>numOfStud;

        for ( int j = 0 ; j < numOfStud ; ++j ) {
            cin>>score[i][j];
            avg[i] += score[i][j];
        }
        avg[i] /= numOfStud;

        for ( int j = 0 ; j < numOfStud ; ++j ) {
            if(avg[i] < score[i][j]){
                cnt++;
            }
            percentage[i] = cnt / numOfStud * 100;
        }
    }

    for ( int i = 0 ; i < testCase ; ++i ) {
        printf("%.3lf%%\n", percentage[i]);
    }

    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO4344_H
