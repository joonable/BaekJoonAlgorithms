//
// Created by JoonYoung Jeon on 12/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1629_H
#define BAEKJOONALGORITHMS_PRO1629_H

#include <iostream>

using namespace std;

long long c;

long long Power( const long long& a, long long b ){
    if( b == 0 ){
        return 1;
    }
//    if( b == 1 ){
//        return a % c;
//    }

    long long x = Power(a, b / 2) % c;
    if( b % 2 == 1 ){
        return (x * x * (a % c) ) % c;
    }

    if( b % 2 == 0 ){
        return (x * x) % c;
    }
}

int pro1629(){
    long long a, b;

    cin>>a>>b>>c;
    cout<<Power(a % c, b)<<endl;
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO1629_H
