//
// Created by JoonYoung Jeon on 13/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1427_H
#define BAEKJOONALGORITHMS_PRO1427_H

#include <iostream>
using namespace std;

int pro1427(){
    unsigned int cnt[10] = {0};
    while(true){
        int num = getchar();
        if(num == '\n'){
            break;
        }
        cnt[num - '0']++;
    }
    for( int i = 9 ; i >= 0 ; --i ){
        for( int j = 0 ; j < cnt[i] ; ++j ){
            printf("%d", i);
        }
    }
    return 0;
}


#endif //BAEKJOONALGORITHMS_PRO1427_H
