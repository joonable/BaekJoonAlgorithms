//
// Created by JoonYoung Jeon on 31/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2003_H
#define BAEKJOONALGORITHMS_PRO2003_H

#include <iostream>
using namespace std;
int pro2003(){
    int M;
    int N, cnt = 0;      cin>>N>>M;
    int series[10000] = {0};

    for( int i = 0 ; i < N ; ++i ){
        scanf("%d", &series[i]);
    }

    int head = 0, tail = 0;
    int sum = series[0] ;

    while( true ){
        if(tail == N){
            break;
        }

        if(head > tail){
            printf("overflow");
        }

        if( sum < M ){
            tail += 1;
            sum += series[tail];
        }
        else if( sum > M ){
            if(head != tail){
                sum -= series[head];
                head += 1;
            }
            else{
                tail += 1;
                sum += series[tail];
            }
        }
        else{
            tail += 1;
            sum += series[tail];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2003_H
