//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1924_H
#define BAEKJOONALGORITHMS_PRO1924_H
#include <iostream>
using namespace std;

int pro1924(){
    char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int x, y, daySum = 0;
    cin>>x>>y;

    for ( int i = 0 ; i < x - 1 ; ++i ) {
        daySum += month[i];
    }
    daySum += y;

    printf("%s", day[((daySum - 1) % 7) ] );

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1924_H
