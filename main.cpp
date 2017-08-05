
//#include "pro11003.h"
//
//int main() {
//
//    pro11003();
//    return 0;
//}
#include <iostream>
#include <vector>
#include "pro11003.h"
using namespace std;

int main() {
    vector<vector<int> > v(3);
//     scanf("%d", &v[0][0]);
//     scanf("%d", &v[0][1]);
//     scanf("%d", &v[1][0]);
//     scanf("%d", &v[1][1]);
//     scanf("%d", &v[2][0]);
//     scanf("%d", &v[2][1]);
//      scanf("%d", &v[3][0]);
     // scanf("%d", &v[3][1]);


    vector<int> ans(2);

    int flag = 0;
    if( v[0][flag] == v[1][flag] ){
        ans.push_back(v[2][flag]);

    }
    else {
        ans.push_back(v[0][flag] + v[1][flag] - v[2][flag]);
    }

    flag = 1;

    if( v[0][flag] == v[1][flag] ){
        ans.push_back(v[2][flag]);
    }
    else {
        ans.push_back(v[0][flag] + v[1][flag] - v[2][flag]);
    }
//    return ans;
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}