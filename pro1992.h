//
// Created by JoonYoung Jeon on 25/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1992_H
#define BAEKJOONALGORITHMS_PRO1992_H
#define MAX 64

#include <iostream>
#include <array>
#include <string>

using namespace std;

string Divide(const array<array<char, MAX>, MAX>& arr, const int& iLow, const int& iHigh, const int& jLow, const int& jHigh){
    if(iLow == iHigh && jLow == jHigh){
        string ch;
        ch += (arr[iLow][jLow]);
        return ch;
    }

    int iMid = (iLow + iHigh)/2;
    int jMid = (jLow + jHigh)/2;

    string ch1 = Divide(arr, iLow, iMid, jLow, jMid);
    string ch2 = Divide(arr, iLow, iMid, jMid + 1, jHigh);
    string ch3 = Divide(arr, iMid + 1, iHigh, jLow, jMid);
    string ch4 = Divide(arr, iMid + 1, iHigh, jMid + 1, jHigh);

    if(ch1 == ch2 && ch2 == ch3 && ch3 == ch4 && ch1.length() == 1){
        return ch1;
    }
    return '(' + ch1 + ch2 + ch3 + ch4 + ')';
}

int pro1992(){
    array<array<char, MAX>, MAX> arr = {0};
    int N;      cin>>N;
    for( int i = 0 ; i < N ; ++i ){
        scanf("%s", &arr[i]);
    }
    string result = Divide(arr, 0, N - 1, 0, N - 1);
    cout<<result;
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1992_H
