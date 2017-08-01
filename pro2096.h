//
// Created by JoonYoung Jeon on 01/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2096_H
#define BAEKJOONALGORITHMS_PRO2096_H

#include <iostream>
#include <algorithm>
using namespace std;

int pro2096(){
    int N;      cin>>N;

    int dpForMin[2][3] = {0};
    int dpForMax[2][3] = {0};
    int temp[3];
    bool flag = false;

    cin>>dpForMin[flag][0];
    dpForMax[flag][0] = dpForMin[flag][0];

    cin>>dpForMin[flag][1];
    dpForMax[flag][1] = dpForMin[flag][1];

    cin>>dpForMin[flag][2];
    dpForMax[flag][2] = dpForMin[flag][2];

    flag = !flag;
    for( int n = 1 ; n < N ; ++n ){
        scanf("%d", &temp[0]);
        scanf("%d", &temp[1]);
        scanf("%d", &temp[2]);

        dpForMax[flag][0] = temp[0] + max(dpForMax[!flag][0], dpForMax[!flag][1]);
        dpForMin[flag][0] = temp[0] + min(dpForMin[!flag][0], dpForMin[!flag][1]);

        dpForMax[flag][1] = temp[1] + max(max(dpForMax[!flag][0], dpForMax[!flag][1]), dpForMax[!flag][2]);
        dpForMin[flag][1] = temp[1] + min(min(dpForMin[!flag][0], dpForMin[!flag][1]), dpForMin[!flag][2]);

        dpForMax[flag][2] = temp[2] + max(dpForMax[!flag][1], dpForMax[!flag][2]);
        dpForMin[flag][2] = temp[2] + min(dpForMin[!flag][1], dpForMin[!flag][2]);

        flag = !flag;
    }

    int max_num = max(max(dpForMax[!flag][0], dpForMax[!flag][1]), dpForMax[!flag][2]);
    int min_num = min(min(dpForMin[!flag][0], dpForMin[!flag][1]), dpForMin[!flag][2]);

    cout<<max_num<<" "<<min_num;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2096_H
