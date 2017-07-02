//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1110_H
#define BAEKJOONALGORITHMS_PRO1110_H
#include <iostream>
using namespace std;

int pro1110(){
    int num[2], sum[2], newNum[2], N, x = 0, cycle = 0;

    cin>>N;
    if (0 < N && N < 10){
        num[0] = 0;
        num[1] = N;
    }
    else {
        num[0] = N / 10;
        num[1] = N - 10 * num[0];
    }

    while ( true ) {
        cycle++;
        x = num[0] + num[1];
        if (0 < x && x < 10){
            sum[0] = 0;
            sum[1] = x;
        }
        else {
            sum[0] = x / 10;
            sum[1] = x - 10 * sum[0];
        }

        x = num[1] * 10 + sum[1];

        if (x == N){
            printf("%d", cycle);
            break;
        }

        newNum[0] = x / 10;
        newNum[1] = x - 10 * newNum[0];

        num[0] = newNum[0];
        num[1] = newNum[1];

    }

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1110_H
