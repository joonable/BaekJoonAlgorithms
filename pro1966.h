//
// Created by JoonYoung Jeon on 05/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1966_H
#define BAEKJOONALGORITHMS_PRO1966_H

#include <iostream>
#include <queue>

using namespace std;

struct Document{
public:
    int idx;
    int priority;

    Document(int idx, int priority)
            : idx(idx), priority(priority) { }
    Document(const Document& ref)
            : idx(ref.idx), priority(ref.priority) { }

    Document& operator=(const Document& ref){
        this->idx = ref.idx;
        this->priority = ref.priority;
        return *this;
    }
};

int pro1966(){
    int T;      cin>>T;
    int result[10000];
    for ( int i = 0 ; i < T ; ++i ) {
        priority_queue<int> PQ;
        queue<Document> Q;

        int N, idx;
        cin>>N>>idx;
        for ( int j = 0 ; j < N ; ++j ) {
            int priority;   cin>>priority;
            Document doc(j, priority);
            Q.push(doc);
            PQ.push(priority);
        }
        int order = 0;
        while ( !Q.empty() ) {
            if (Q.front().priority >= PQ.top()){
                order++;
                if ( Q.front().idx == idx){
                    result[i] = order;
                    break;
                }
                Q.pop();
                PQ.pop();
            }
            else{
                Document doc(Q.front());
                Q.push(doc);
                Q.pop();
            }
        }
    }
    for ( int i = 0 ; i < T ; ++i ) {
        printf("%d\n", result[i]);
    }
    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1966_H
