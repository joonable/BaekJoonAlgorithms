//
// Created by JoonYoung Jeon on 12/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1629_H
#define BAEKJOONALGORITHMS_PRO1629_H

#include <iostream>
#include <cmath>
using namespace std;

unsigned long long c;

unsigned long long Power(unsigned long long a, unsigned long long  b){
    if( b == 1 ){
        return a % c;
    }
    unsigned long long X = Power(a, b/2) % c;

    if( b % 2 == 1 ){
        return ( (X % c) * (X % c) * (a % c) ) % c;
    }
    else{
        return ( (X % c) * (X % c) ) % c;
    }
}

int pro1629(){
    unsigned long long a, b;

    cin>>a>>b>>c;
    cout<<Power(a, b)<<endl;
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO1629_H
