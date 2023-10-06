#include<iostream>

using namespace std;
/*
左侧第一个更大	从右到左	单调递减
左侧第一个更小	从右到左	单调递增
右侧第一个更大	从左到右	单调递减
右侧第一个更小	从左到右	单调递增
*/
const int N = 10010;
int stk[N], top = 0  ;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
            while( top>0 && stk[top] >= x) top--;
            stk[ ++top ] = x ;
    }
    for (int i = 0; i < top; i++)
            cout << stk[i];
    return 0;
}