#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

double string_double( string s){
    double  ans = 0;
    int  i = 0, t=0;
    bool flg = false;
    if(s[0] == '-'){
        i = 1;
        flg = true;
    }
    while( i<s.size( )){
        if(s[i] !='.'){
            ans *= 10;
            ans += s[i]-'0';
        }else t = i;
        i++;
    }
    ans /= pow(10, s.size() - t - 1);
    if (flg == true)
        ans *= -1;
    return ans;
}

const int INF = 10000000;
struct node{
    int a, b;
    // 类似于 构造函数
    node(){
        a = INF;
        b = INF;
    }
};

int tomax( vector<int> v, int i){
    if( i = v.size() - 1 )
        return v[i];
    return (max(v[i], tomax(v, i + 1)));
}

void f1( vector<int> &t){
    t[0] = 0;
}

int main(){
    int a = 100, b = 50;
    cout << __gcd(a, b);
    return 0;
}
