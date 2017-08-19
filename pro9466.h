//
// Created by JoonYoung Jeon on 18/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9466_H
#define BAEKJOONALGORITHMS_PRO9466_H

#include <iostream>
#include <vector>

using namespace std;

int pro9466(){
    int T, N;       cin>>T;
    for( int t = 0 ; t < T ; ++t ){
        scanf("%d", &N);
        vector<int > students(N);
        vector<bool> team(N, false);
        vector<bool> visited(N, false);

        for( int i = 0 ; i < N ; ++i ){
            scanf("%d" - 1, &students[i]);
        }

    }

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO9466_H
