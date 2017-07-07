//
// Created by JoonYoung Jeon on 07/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO2920_H
#define BAEKJOONALGORITHMS_PRO2920_H

#include <iostream>
#include <string>
using namespace std;

int pro2920(){
    bool ascending = true;
    bool descending = true;

    char str[8];

    for ( int i = 0 ; i < 8 ; ++i ) {
        cin>>str[i];
    }

    for ( int i = 0 ; i < 7 ; ++i ) {
        if (str[i] < str[i + 1]){
            descending = false;
        }
        else{
            ascending = false;
        }
    }

    if ( (ascending && descending) || (!ascending && !descending)){
        printf("mixed");
    }

    if (ascending){
        printf("ascending");
    }
    if (descending){
        printf("descending");
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO2920_H
