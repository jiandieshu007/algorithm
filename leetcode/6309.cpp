#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
    int i;
    for(i = a; i >= 2; --i) {
        if(a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

int findValidSplit(vector<int>& nums) {
    int n = nums.size(), res = -1;
    vector<long long> pre(n,0), suf(n,0);
    pre[0] = nums[0], pre[n-1] = nums[n-1];
    for(int i=1; i<n; i++) 
        pre[i] = pre[i-1] * nums[i];
    for(int i=n-2; i>=0; i-- )
        suf[i] = suf[i + 1] * nums[i];

    for(int i=0; i<n-1; i++ ){
        if( gcd( pre[i], suf[i+1] ) == 1 ) res = i;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i<n; i++ )
        cin >> k[i];
    cout << findValidSplit(k);
    return 0;
}