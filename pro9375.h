//
// Created by JoonYoung Jeon on 17/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9375_H
#define BAEKJOONALGORITHMS_PRO9375_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

int pro9375(){

    int T;      cin>>T;
    for( int t = 0 ; t < T ; ++t ){
        list<string> items[30];
        int listIdx = 0;
        int N;      cin>>N;
        for( int n = 0 ; n < N ; ++n ){
            string string1, string2;
            cin>>string1>>string2;

            bool found = false;
            for( int i = 0 ; i < listIdx  ; ++i ){
                if(items[i].front() == string2){
                    items[i].push_back(string1);
                    found = true;
                    break;
                }
            }
            if(!found){
                items[listIdx].push_front(string2);
                items[listIdx++].push_back(string1);
            }
        }
        int size = 1;
        for( int i = 0 ; i < listIdx ; ++i ){
            size *= items[i].size();
        }
        cout<<size-1<<endl;
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO9375_H
