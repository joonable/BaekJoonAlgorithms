//
// Created by JoonYoung Jeon on 06/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1152_H
#define BAEKJOONALGORITHMS_PRO1152_H

#include <iostream>
#include <cstring>
using namespace std;

int pro1152(){
    char str[1000001];
    cin.getline(str, 1000001);
    bool found = false;
    int len = (int)strlen(str);

    int numOfWords = 0;
    if (str[0] != ' ') {
        numOfWords = 1;
        found = true;
    }

        for ( int i = 0 ; i < len - 1; ++i ) {
        if (str[i] == ' '){
            if (str[i + 1] != ' '){
                numOfWords++;
                found = true;
            }
        }
    }

    if(str[len] == ' '){
        numOfWords--;
    }


    if (found){
        printf("%d", numOfWords);
    }
    else{
        printf("0");
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1152_H
