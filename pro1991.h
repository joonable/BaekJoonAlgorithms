//
// Created by JoonYoung Jeon on 07/08/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO1991_H
#define BAEKJOONALGORITHMS_PRO1991_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    int left;
    int right;

    Node(int data = NULL, int left = NULL, int right = NULL){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node alphabet[26];

void PreOrder(Node node){
    printf("%c", node.data + 'A');
    if( node.left != NULL){
        PreOrder(alphabet[node.left]);
    }
    if( node.right != NULL){
        PreOrder(alphabet[node.right]);
    }
}

void InOrder(Node node){
    if( node.left != NULL ){
        InOrder(alphabet[node.left]);
    }
    printf("%c", node.data + 'A');
    if( node.right != NULL){
        InOrder(alphabet[node.right]);
    }
}

void PostOrder(Node node){
    if( node.left != NULL ){
        PostOrder(alphabet[node.left]);
    }
    if( node.right != NULL ){
        PostOrder(alphabet[node.right]);
    }
    printf("%c", node.data + 'A');
}

int pro1991(){
    int N;      cin>>N;

    char data, left, right;

    for( int i = 0 ; i < 26 ; ++i ){
        alphabet[i] = Node(i);
    }

    for( int i = 0 ; i < N ; ++i ){
        cin>>data>>left>>right;

        data -= 'A';
        left -= 'A';
        right -= 'A';

        if( left == '.' - 'A')
            left = NULL;
        if( right == '.' - 'A')
            right = NULL;

        alphabet[data] = Node(data, left, right);
    }

    PreOrder(alphabet[0]);          cout<<endl;
    InOrder(alphabet[0]);           cout<<endl;
    PostOrder(alphabet[0]);         cout<<endl;

    return 0;
}

#endif //BAEKJOONALGORITHMS_PRO1991_H
