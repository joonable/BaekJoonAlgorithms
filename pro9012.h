//
// Created by JoonYoung Jeon on 03/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9012_H
#define BAEKJOONALGORITHMS_PRO9012_H

#include <iostream>
#include <cstring>
using namespace std;

int pro9012(){
    int N;      cin>>N;
    char roundBrackets[10000][51];
    for ( int i = 0 ; i < N ; ++i ) {
        cin>>*(roundBrackets + i);
    }
    for ( int i = 0 ; i < N ; ++i ) {
        int cnt = 0;
        int len = (int)strlen(roundBrackets[i]);

        for ( int j = 0 ; j < len + 1 ; ++j ) {

            if (cnt < 0){
                break;
            }

            if( roundBrackets[i][j] == '(' ){
                cnt++;
            }
            else if ( roundBrackets[i][j] == ')' ){
                cnt--;
            }
            else{

            }
        }
        if(cnt == 0){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO9012_H
