//
// Created by JoonYoung Jeon on 29/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9461_H
#define BAEKJOONALGORITHMS_PRO9461_H

#include <iostream>
#include <array>
using namespace std;

const int MAX = 100;

int pro9461(){
    int T;  cin>>T;
    for( int t = 0 ; t < T ; ++t ){
        array<long long, 100> padovan = {1, 1, 1, };
        int N;      cin>>N;
        if(N < 4){
            cout<<1<<endl;
            continue;
        }

        for( int n = 3 ; n < N ; ++n ){
            padovan[n] = padovan[n - 3] + padovan[n - 2];
        }
        cout<<padovan[N - 1]<<endl;
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO9461_H
