//
// Created by JoonYoung Jeon on 07/07/2017.
//

#ifndef BAEKJOONALGORITHMS_PRO10866_H
#define BAEKJOONALGORITHMS_PRO10866_H

#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    Node(int val) : val(val), prev(nullptr), next(nullptr){ }
    int val;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;
int size = 0;

bool isEmpty(){
    if (head == nullptr || tail == nullptr ){
        return true;        
    }
    else{
        return false;
    }
}


void Size(){
    printf("%d\n", size);
}

void Front(){
    if (head == nullptr){
        printf("-1\n");
    }
    else{
        printf("%d\n", head->val);
    }
}


void Back(){
    if ( tail == nullptr){
        printf("-1\n");
    }
    else{
        printf("%d\n", tail->val);
    }
}

void PopFront(){
    if (isEmpty()){
        printf("-1\n");
    }
    else{
        Front();
        if (head == tail){
            delete[](head);
            head = nullptr;
            tail = nullptr;
        }
        else{
            Node* temp = head->next;
            delete[](head);
            head = temp;
            head->prev = nullptr;
        }
        size--;
    }
}

void PopBack(){
    if( isEmpty()){
        printf("-1\n");
    }
    else {
        Back();
        if ( tail == head ) {
            delete[]( tail );
            head = nullptr;
            tail = nullptr;
        }
        else{
            Node* temp = tail->prev;
            delete[](tail);
            tail = temp;
            tail->next = nullptr;
        }
        size--;
    }

}

void PushFront(int x) {
    Node* newNode = new Node(x);
    if ( isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else{
        Node* temp = head;
        head->prev = newNode;
        head = newNode;
        head->next = temp;
    }
    size++;
}

void PushBack(int x) {
    Node* newNode = new Node(x);
    if ( isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else{
        Node* temp = tail;
        tail->next = newNode;
        tail = newNode;
        tail->prev = temp;
    }
    size++;
}

void Empty(){
    if( isEmpty() ){
        printf("1\n");
    }
    else{
        printf("0\n");
    }
}


int pro10866(){
    int N;      cin>>N;
    for ( int i = 0 ; i < N ; ++i ) {
        char menu[12];
        cin >> menu;
        cin.ignore();
        if ( strcmp(menu, "push_front") == 0 ) {
            int x;
            cin >> x;
            PushFront(x);
        }
        else if ( strcmp(menu, "push_back") == 0 ) {
            int x;
            cin >> x;
            PushBack(x);
        }
        else if ( strcmp(menu, "pop_front") == 0 ) {
            PopFront();
        }
        else if ( strcmp(menu, "pop_back") == 0 ) {
            PopBack();
        }
        else if ( strcmp(menu, "size") == 0 ) {
            Size();
        }
        else if ( strcmp(menu, "empty") == 0 ) {
            Empty();
        }
        else if ( strcmp(menu, "front") == 0 ) {
            Front();
        }
        else if ( strcmp(menu, "back") == 0 ) {
            Back();
        }
        else {
            break;
        }
    }

    while (head != nullptr){
        if (head == tail){
            delete[](head);
            head = nullptr;
            tail = nullptr;
        }
        else{
            Node* temp = head->next;
            delete[](head);
            head = temp;
            head->prev = nullptr;
        }
        size--;
    }
    return 0;
}
#endif //BAEKJOONALGORITHMS_PRO10866_H