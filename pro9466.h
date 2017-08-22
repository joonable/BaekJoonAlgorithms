//
// Created by JoonYoung Jeon on 18/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO9466_H
#define BAEKJOONALGORITHMS_PRO9466_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<bool> visited;
vector<int> survey;
stack<int> Stack;

void DFS(int student){
    visited[student] = true;

    if (visited[survey[student]]){
        return;
    }

    Stack.push(survey[student]);
    cout<<"push : "<<Stack.top()<<endl;
    DFS(survey[student]);
    /////////////////////////////

    if( visited[student] ){
        Stack.push(student);
        cout<<"push : "<<Stack.top()<<endl;
        return;
    }
    Stack.push(survey[student]);
    cout<<"push : "<<Stack.top()<<endl;
    DFS(survey[student]);
}

int pro9466(){
    int T, N;       cin>>T;
    for( int t = 0 ; t < T ; ++t ){
        scanf("%d", &N);
        survey.resize(N);
        visited.resize(N, false);
        int noTeamStuds = 0;
        int teamStuds = 0;
//        vector<bool> team(N, false);

        for( int i = 0 ; i < N ; ++i ){
            scanf("%d", &survey[i]);
            survey[i]--;
        }
        for( int i = 0 ; i < N ; ++i ){
            if(visited[i]){
                continue;
            }

            Stack.push(i);
            cout<<"push : "<<Stack.top()<<endl;

            DFS(survey[i]);

            int lastMember = Stack.top();
            cout<<"pop : "<<Stack.top()<<endl;
            Stack.pop();
            while( true ){
                if(Stack.top() == lastMember){
                    cout<<"pop : "<<Stack.top()<<endl;
                    Stack.pop();
                    break;
                }
                cout<<"pop : "<<Stack.top()<<endl;
                Stack.pop();
                teamStuds++;
            }
            while(!Stack.empty()){
                noTeamStuds++;
                cout<<"pop num++ : "<<Stack.top()<<endl;
                Stack.pop();
            }
            cout<<noTeamStuds<<endl;
            cout<<N - teamStuds<<endl;
        }
        cout<<noTeamStuds<<endl;
        cout<<N - teamStuds<<endl;

        cout<<endl;
    }


    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO9466_H
