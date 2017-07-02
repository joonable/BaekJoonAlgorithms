//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO4673_H
#define BAEKJOONALGORITHMS_PRO4673_H
#include <iostream>
#include <cmath>
using namespace std;

bool selfNum[10000] = { false };

void CheckSelfNum(const int& num);
int numDigits(int number);
int GetDividend(int* &arr, const int& num, int i, const int& digits);
void CheckSelfNum(const int& num);
int numDigits(int number);


int pro4673(){

    for ( int i = 1 ; i < 10000 ; ++i ) {
        CheckSelfNum(i);
    }

    for ( int i = 0 ; i < 9999 ; ++i ) {
        if(!selfNum[i]){
            printf("%d\n", i + 1);
        }
    }
    return 0;
};


int GetDividend(int* &arr, const int& num, int i, const int& digits){
    int dividend = num;
    while(i){
        dividend -= (arr[i - 1] * (int)pow(10, digits - i));
        i--;
    }
    return dividend;
}


void CheckSelfNum(const int& num) {
    int digits = numDigits(num);
    int* arr = new int[digits];

    arr[0] = num / (int)pow(10, digits - 1);
    for ( int i = 1 ; i < digits ; ++i ) {
        arr[i] = GetDividend(arr, num, i, digits) / (int)pow(10, digits - i - 1);
    }

    int constructor = num;
    for ( int i = 0 ; i < digits ; ++i ) {
        constructor += arr[i];
    }
    delete[](arr);

    if( numDigits(constructor) < 5 ){
        if(!selfNum[constructor - 1]){
            selfNum[constructor - 1] = true;
            CheckSelfNum(constructor);
        }
    }
}

int numDigits(int number) {
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

#endif //BAEKJOONALGORITHMS_PRO4673_H
