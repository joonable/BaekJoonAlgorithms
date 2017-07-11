//
// Created by JoonYoung Jeon on 11/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11051_H
#define BAEKJOONALGORITHMS_PRO11051_H

#include <iostream>

using namespace std;
int pro11051(){
    int nCk[2][1000] = {0};
    int N, K;       cin>>N>>K;
    int n = 0;
    bool flag = true;
    while(n != N){
        nCk[flag][0] = n + 1;
        for( int k = 1 ; k < n ; ++k ){
            nCk[flag][k] = (nCk[!flag][k - 1] + nCk[!flag][k]) % 10007;
        }
        nCk[flag][n] = 1;
        flag = (!flag);
        n++;
    }
    cout<<nCk[!flag][K-1];
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO11051_H
