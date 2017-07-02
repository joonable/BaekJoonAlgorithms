//
// Created by JoonYoung Jeon on 02/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11721_H
#define BAEKJOONALGORITHMS_PRO11721_H
#include <iostream>
#include <cstring>

using namespace std;

int pro11721(){

    char arr[101] = {0};
    cin>>arr;
    int len = (int)strlen(arr);


    for ( int i = 0 ; i < len ; ++i ) {
        if ( ((i % 10) == 0) && (i != 0) ) {
            printf("\n");
        }
        printf("%c", arr[i]);
    }
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO11721_H
