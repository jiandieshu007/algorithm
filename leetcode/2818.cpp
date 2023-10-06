#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;


int maximumScore(vector<int>& nums, int k) {
    int maxx = 1e5+9, mod = 1e9+7, n = nums.size();
    long ans = 1;
    vector<int> v(maxx+1,0);
    function<void()> f = [&](){
        for (int i = 2; i <= maxx; i++) {
            if (!v[i]){
                for (int j = i; j <= maxx; j += i) 
                    v[j]++;
            }
        }
    };
    f();
    vector<pair<int,int>> vv;
    vector<int> left(n,-1), right(n,n);
    stack<int> stk;
    for(int i=0; i<n; ++i){
        vv.push_back({i,nums[i]} );
        while( !stk.empty() && v[nums[stk.top()]] < v[ nums[i]] ){
            right[stk.top() ] = i;
            stk.pop();
        }
        if( !stk.empty() ) left[i] = stk.top();
        stk.push(i);
    }
            sort(vv.begin(), vv.end(), [&](const pair<int,int>& a, const pair<int,int>& b){
        int y1 = a.second, y2 = b.second;
        if( v[y1] != v[y2] ) return v[y1] > v[y2];
        else return y1>y2;
    });

    function<long(int,int)> quick_exp = [&](int x, int y){
        long res = 1, t = a;
        while( y ){
            if( y&1 ) res *=t;
            t*= t;
            y>>=1;
            res %= mod;
        }
        return res;
    };
    for(int i=0; i<n ; ++i){
        int x = vv[i].first, y = vv[i].second;
        int l = x - left[x], r = right[x] - x;
        int tot = l * r;
        if( k > tot )  ans *= quick_exp(y,tot), k-=tot;
        else{
            ans *= quick_exp(y,k);
            break;
        }
        ans %= mod;
    }
    return ans%mod;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i ){
        cin >> v[i];
    }
    cout << maximumScore(v, k);
    return 0;
}