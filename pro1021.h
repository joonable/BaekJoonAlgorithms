//
// Created by JoonYoung Jeon on 08/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1021_H
#define BAEKJOONALGORITHMS_PRO1021_H

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int pro1021(){
    int arr[50];
    int arrIdx = 0;
    deque<int> Deque;
    int N, M;   cin>>N>>M;
    for( int i = 0 ; i < N ; ++i ) {
        Deque.push_back(i + 1);
    }
    for( int i = 0 ; i < M ; ++i ) {
        cin>>arr[i];
    }

    int total = 0;
    for( int i = 0 ; i < M ; ++i ){
        int val = Deque.front();
        int target = arr[arrIdx++];
        if( target == val ){
//            cout<<"pass "<<target<<" "<<n<<endl;
            Deque.pop_front();
            continue;
        }
        int cntToRight = abs(target - val);
        int cntToLeft = N - cntToRight;
//        int cntToLeft = N - i - cntToRight;
        if( target < val ){
            int temp = cntToLeft;
            cntToLeft = cntToRight;
            cntToRight = temp;
        }
        if( val < target ){
            for( int j = 0 ; j < arrIdx - 1 ; ++j ){
                if( val < arr[j] && arr[j] < target ){
                    cntToRight--;
                }
                else{
                    cntToLeft--;
                }
            }
        }
        else{
            for( int j = 0 ; j < arrIdx - 1 ; ++j ){
                if( target < arr[j] && arr[j] < val ){
                    cntToLeft--;
                }
                else{
                    cntToRight--;
                }
            }
        }
        if (cntToLeft < cntToRight ){
//            cout<<"cntToLeft "<<cntToLeft<<endl;
            for( int i = 0 ; i <  cntToLeft ; ++i ){
                int temp = Deque.back();
                Deque.push_front(temp);
                Deque.pop_back();
            }
            total += cntToLeft;
        }
        else{
//            cout<<"cntToRight "<<cntToRight<<endl;
            for( int i = 0 ; i <  cntToRight ; ++i ){
                int temp = Deque.front();
                Deque.push_back(temp);
                Deque.pop_front();
            }
            total += cntToRight;
        }
//        cout<<target<<" "<<Deque.front()<<endl;
        Deque.pop_front();
    }
    printf("%d", total);
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1021_H
