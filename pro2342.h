//
// Created by JoonYoung Jeon on 04/09/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2342_H
#define BAEKJOONALGORITHMS_PRO2342_H

#include <iostream>
#include <array>
using namespace std;

int pro2342(){
    array<array<int, 5>, 5> power = {0};
    array<array<int, 5>, 5> dp = {0};
    for( int i = 1 ; i < 5 ; ++i ){
        power[0][i] = 2;
        for( int j = i ; j < 5 ; ++j ){
            if(abs(i - j) == 0){
                power[i][j] = 1;
            }
            else if( abs(i - j ) == 2){
                power[i][j] = 4;
                power[j][i] = 4;
            }
            else{
                power[i][j] = 3;
                power[j][i] = 3;
            }
        }
    }

    pair<int, int> step = make_pair(0, 0);

    int numOfSteps = 0;
    int nextStep = 0;

    while(true){
        scanf("%d", &nextStep);
        if(nextStep == 0) break;

        if( step.first == nextStep || step.second == nextStep ) {
            numOfSteps++;
            continue;
        }

        if(power[step.first][nextStep] < power[step.second][nextStep]){
            numOfSteps += power[step.first][nextStep];
            step.first = nextStep;
        }
        else{
            numOfSteps += power[step.second][nextStep];
            step.second = nextStep;
        }
    }
    cout<<numOfSteps;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2342_H
