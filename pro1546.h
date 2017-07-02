//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1546_H
#define BAEKJOONALGORITHMS_PRO1546_H
#include <iostream>
using namespace std;

int pro1546(){
    int N;
    double newScore[1000], max = 0, avg = 0;
    cin>>N;

    for ( int i = 0 ; i < N ; ++i ) {
        cin>>newScore[i];
    }

    for ( int i = 0 ; i < N ; ++i ) {
        if (newScore[i] > max){
            max = newScore[i];
        }
    }

    for ( int i = 0 ; i < N ; ++i ) {
        newScore[i] = newScore[i] / max * 100;
        avg += newScore[i];
    }

    avg = avg / N;
    printf("%.2lf", avg);

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1546_H
