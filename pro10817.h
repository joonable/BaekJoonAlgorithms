//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO10817_H
#define BAEKJOONALGORITHMS_PRO10817_H
#include <iostream>
using namespace std;

int pro10817(){
    int x, y, z;
    cin>>x>>y>>z;

    if( (x >= y && x <= z) || (x <= y && x >= z) ){
        cout<<x;
        return 0;
    }
    if( (y >= x && y <= z) || (y <= x && y >= z) ){
        cout<<y;
        return 0;
    }
    if( (z >= y && z <= x) || (z <= y && z >= x) ){
        cout<<z;
        return 0;
    }
};
#endif //BAEKJOONALGORITHMS_PRO10817_H
