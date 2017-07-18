//
// Created by JoonYoung Jeon on 17/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1676_H
#define BAEKJOONALGORITHMS_PRO1676_H

#include <iostream>
using namespace std;

int pro1676(){
    int N;      cin>>N;

    int m = 0;
    for( int j = 1 ; j <= N ; ++j ){
        int i = j;

        while( true ){
            if(i % 5 != 0){
                break;
            }
            i /= 5;
            m++;
        }
    }
    cout<<m;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1676_H
