//
// Created by JoonYoung Jeon on 01/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11003_H
#define BAEKJOONALGORITHMS_PRO11003_H

#include <iostream>
#include <deque>
using namespace std;

int pro11003(){
    int N, L;       cin>>N>>L;
    int min = 1000000001, minIdx = L;
    int head = 0, tail = 0;
    deque<int> numbers;
    int num = 0;
    for( int i = 0 ; i < L ; ++i ){
        scanf("%d", &num);
        numbers.push_back(num);
        if(min > num){
            min = num;
            minIdx = i;
        }
        tail++;
        printf("%d ", min);
    }
    for( int i = L ; i < N ; ++i ){
        head++;
        scanf("%d", &num);
        numbers.push_back(num);
        numbers.pop_front();

        if(head > minIdx){
            min = 1000000001;
            int j = 0;
            for( int element : numbers){
                if(min > element){
                    min = element;
                    minIdx = head + j;
                }
                j++;
            }
        }
        if( min > num ){
            min = num;
            minIdx = i;
        }
        printf("%d ", min);
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO11003_H
