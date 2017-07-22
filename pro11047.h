//
// Created by JoonYoung Jeon on 22/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11047_H
#define BAEKJOONALGORITHMS_PRO11047_H

#include <iostream>
using namespace std;

int pro11047(){
    int arr[10];
    int N, K;      cin>>N>>K;
    int money = 0, cnt = 0;

    for( int i = 0 ; i < N ; ++i ){
        scanf("%d", &arr[i]);
    }

    for( int i = N-1 ; i >= 0  ; --i ){
        if( money == K ){
            break;
        }

        while( true ){
            if (money + arr[i] <= K){
//                cout<<money<<" "<<arr[i]<<endl;

                money += arr[i];
                cnt++;
            }
            else{
                break;
            }
        }
    }
    cout<<cnt;

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO11047_H
