//
// Created by JoonYoung Jeon on 31/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO11723_H
#define BAEKJOONALGORITHMS_PRO11723_H

#include <iostream>
#include <cstring>
using namespace std;

int pro11723(){
    int bitSet = 0;

    int T, x;      cin>>T;
    char menu[8];
    for( int i = 0 ; i < T ; ++i ){
        scanf("%s", menu);

        if(strcmp(menu, "add") == 0){
            scanf("%d", &x);
            bitSet |= (1 << x);
        }
        else if(strcmp(menu, "remove") == 0){
            scanf("%d", &x);
            bitSet &= ~(1 << x);
        }
        else if(strcmp(menu, "check") == 0){
            scanf("%d", &x);
            if(bitSet & (1 << x)){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
        else if(strcmp(menu, "toggle") == 0){
            scanf("%d", &x);
            bitSet ^= (1 << x);
        }
        else if(strcmp(menu, "all") == 0){
            bitSet = (1 << 21) -1;
        }
        else if(strcmp(menu, "empty") == 0){
            bitSet = 0;
        }
        else{
            continue;
        }
    }

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO11723_H
