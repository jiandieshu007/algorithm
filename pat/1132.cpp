#include<iostream>
#include<vector>
#include<cmath>
using namespace std;



bool judge( int k){
    int cnt = 0;
    for(int i=k; i; i/=10) cnt++;
    int a = k / pow(10,cnt/2);
    int b = k % (int)pow(10,cnt/2);
    double ans = 1.0* k /a / b;
    if( ans -(int)ans ) return false;
    else return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> info(n);
    vector<int> ans;
    for(int i=0; i<n; i++) cin>>info[i];
    
    for(int i=0; i<n; i++){
        if( judge( info[i]) ) ans.push_back(1);
        else ans.push_back(0);
    }
    for(int i=0; i<n; i++){
        if(i ) cout<<endl;
        if( ans[i] ) cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}