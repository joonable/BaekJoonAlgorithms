//
// Created by JoonYoung Jeon on 06/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11866_H
#define BAEKJOONALGORITHMS_PRO11866_H

#include <iostream>
#include <queue>
using namespace std;

int pro11866(){
    queue<int> Q;
    int N, M;       cin>>N>>M;
    for ( int i = 0 ; i < N ; ++i ) {
        Q.push(i + 1);
    }

    printf("<");
    for ( int i = 0 ; i < M - 1 ; ++i ) {
        int num = Q.front();
        Q.push(num);
        Q.pop();
    }
    while ( true ) {
        printf("%d", Q.front());
        Q.pop();

        if ( Q.empty() ) {
            break;
        }
        printf(", ");

        for ( int j = 0 ; j < M - 1 ; ++j ) {
            int num = Q.front();
            Q.push(num);
            Q.pop();
        }
    }
    printf(">");
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO11866_H
