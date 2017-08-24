//
// Created by JoonYoung Jeon on 23/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1463_H
#define BAEKJOONALGORITHMS_PRO1463_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = (int)pow(10, 6) + 1;

int pro1463(){
    int N;      cin>>N;
    vector<int> d(N, MAX);

    d[N - 1] = 0;
    for( int x = N ; x > 1 ; --x ){
        if( x % 3 == 0 ){
            d[x/3 - 1] = min(d[x/3 - 1], d[x - 1] + 1);
        }
        if( x % 2 == 0 ){
            d[x/2 - 1] = min(d[x/2 - 1], d[x - 1] + 1);
        }
        d[x - 2] = min(d[x - 2], d[x - 1] + 1);
    }

//    for( auto& element : d){
//        cout<<element<<" ";
//    }
    cout<<d[0];
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1463_H
