#include<iostream>
#include<vector>
#include<memory>
using namespace std;

int main(){
    auto it = make_shared<int>(9);
    int *q = it.get();
    cout << q << ' ' << *q << endl;
    cout << it << ' ' << *it;
    return 0;
}
