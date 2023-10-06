#include<iostream>
#include<vector>
#include<memory>
using namespace std;

int main(){
    auto p = make_shared<int>(1);
    cout << *p;
    auto q(p);
    cout << endl;
    cout << q.unique();
    v.begin();
    return 0;
}
