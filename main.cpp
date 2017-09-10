
// Created by JoonYoung Jeon on 21/08/2017.

#include "pro1766.h"

using namespace std;

class AAA {
public:
    virtual void SimpleFunc(){
        cout<<"AAA SimpleFunc()"<<endl;
    }
};

class BBB : public AAA{
public:
    virtual void SimpleFunc(){
        AAA::SimpleFunc();
        cout<<"BBB SimpleFunc()"<<endl;
    }
    void SimpleFunc2(){
        cout<<"BBB SimpleFunc2()"<<endl;
    }
};

int main(){
    AAA* aaa = new BBB();
//    BBB bbb;
//    cout<<"case1 : "<<endl;
//    bbb.AAA::SimpleFunc();
//    cout<<endl;
//    cout<<"case2 : "<<endl;
//    bbb.SimpleFunc();
//    cout<<endl;
    aaa->SimpleFunc();
    return 0;
}