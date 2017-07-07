//
// Created by JoonYoung Jeon on 07/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2577_H
#define BAEKJOONALGORITHMS_PRO2577_H

#include <iostream>
#include <cmath>
using namespace std;

int NumDigits(int number);
int GetDividend(int* &arr, const int& num, int i, const int& digits);

int pro2577(){
    int result[10] = {0};

    int a, b ,c;    cin>>a>>b>>c;
    int mul = a*b*c;

    int digits = NumDigits(mul);
    int* arr = new(int[digits]);

    arr[0] = mul / (int)pow(10, digits - 1);
    result[arr[0]]++;
    for ( int i = 1 ; i < digits ; ++i ) {
        arr[i] = GetDividend(arr, mul, i, digits) / (int)pow(10, digits - i - 1);
        result[arr[i]]++;
    }

    for ( int i = 0 ; i < 10 ; ++i ) {
        printf("%d\n", result[i]);
    }

    delete[](arr);
    return 0;
}

int NumDigits(int number) {
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
#endif //BAEKJOONALGORITHMS_PRO2577_H
