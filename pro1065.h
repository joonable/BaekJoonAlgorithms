//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1065_H
#define BAEKJOONALGORITHMS_PRO1065_H

#include <iostream>
#include <cmath>
using namespace std;
int numDigits(int number);
int GetDividend(int* &arr, const int& num, int i, const int& digits);
int cnt = 0;

int pro1065(){
    int N;      cin>>N;
    for ( int num = 1 ; num <= N ; ++num ) {
        int digits = numDigits(num);

        if (digits < 3){
            cnt++;
            continue;
        }

        int* arr = new int[digits];
        arr[0] = num / (int)pow(10, digits - 1);
        for ( int i = 1 ; i < digits ; ++i ) {
            arr[i] = GetDividend(arr, num, i, digits) / (int)pow(10, digits - i - 1);
        }


        bool swt = true;
        int diff = arr[0] - arr[1];
        for ( int i = 1 ; i < digits - 1 ; ++i ) {
            if( diff != (arr[i] - arr[i + 1]) ){
                swt = false;
                break;
            }
        }

        if (swt){
            cnt++;
        }
        delete[](arr);
    }
    cout<<cnt;
    return 0;
}

int numDigits(int number) {
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

int GetDividend(int* &arr, const int& num, int i, const int& digits){
    int dividend = num;
    while(i){
        dividend -= (arr[i - 1] * (int)pow(10, digits - i));
        i--;
    }
    return dividend;
}

#endif //BAEKJOONALGORITHMS_PRO1065_H
