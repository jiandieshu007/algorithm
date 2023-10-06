#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int Sum( int x){
    int ans = 0;
    while( x ){
        ans += x%10;
        x /=10;
    }
    return ans;
}

bool isP( int x){
    if( x == 1) return false;
    if( x == 2 || x == 3 ) return true;
    int t = sqrt(x);
    for(int i=2; i<=t; i++){
        if( x%i ) return false;
    }
    return true;
}

bool cmp( pair<int,int> a, pair<int,int> b){
    if( a.first != b.first){
        return a.first < b.first;
    }else return a.second < b.second;
}
int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        if( i != 1 ) cout<<endl;
        cout<<"Case "<<i;
        vector<pair<int,int>> ans;
        int a, m;
        cin>>a >> m;
        if( a*9 < m ){
            cout<<endl<<"No Solution";
            continue;
        }
        int t1 = m/9, t2 = m%9;
        int x = t2;
        for(int i=0; i<t1; i++){
            x *=10;
            x += 9;
        }
        int y = 0;
        for(int i=0; i<t1; i++){
            y *= 10;
            y += 9;
        }
        y *=10;
        y += t2;
        cout<<endl<<x<<' '<<y;
        for(int j=x; j<=y; j++){
            int t1 = Sum(j), t2 = Sum(j + 1);
            if( t1 == m && isP( __gcd(t1,t2) ) ){
                ans.push_back(make_pair(t1, j));
            }
        }
        sort(ans.begin(), ans.end(), cmp );
        for(int j=0; j<ans.size(); j++){
            cout<<endl<<ans[j].first<<' '<<ans[j].second;
        }
    }
    return 0;
}