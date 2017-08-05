//
// Created by JoonYoung Jeon on 31/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9997_H
#define BAEKJOONALGORITHMS_PRO9997_H

#include <iostream>
using namespace std;
#include <cmath>
#include <cstring>
//#include <bitset>
int pro9997(){
    unsigned int words[25] = {0};
    int N;     cin>>N;

    char word[101];
    for( int n = 0 ; n < N ; ++n ){
        scanf("%s", &word);


        for( int i = 0 ; i < strlen(word) ; ++i ){
            words[n] |= (1 << (word[i] - 'a'));
//            cout<<word[i] - 'a' + 1<<" ";
        }
//        cout<<endl;
    }
    unsigned int wholeSet = (1 << N) - 1;
    unsigned int subSet = wholeSet;
    unsigned int testSentence, cnt = 0;
    while(subSet){
//        cout<<subSet<<" ";
        testSentence = 0;
        for( int i = 0 ; i < N ; ++i ){
//            if(subSet & (1 << i )){
//                cout<<i<<" ";
//                cout<<i<<" : "<<words[i]<<" ";
//                testSentence |= words[i];
//            }
            testSentence |= (words[i] * (bool)(subSet & (1 << i)));
        }

        if( testSentence == (1<<26)-1 ){
            cnt++;
        }

        subSet  = ((subSet - 1) & wholeSet);
//        bitset<26> x(testSentence);
//        cout<<x<<endl;
    }

//    for( int i = 0 ; i < N ; ++i ){
//        bitset<26> x(words[i]);
//        cout<<x<<endl;
//    }
//    bitset<26> x(words[0] | words[1]);
//    cout<<x<<endl;

    cout<<cnt;
    return 0;
}


#endif //BAEKJOONALGORITHMS_PRO9997_H
