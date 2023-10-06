#include<iostream>
#include<vector>
using namespace std;

int reinitializePermutation(int n) {
    vector<int> prem(n), arr(n);
    for(int i=0; i<n; i++) prem[i] = i;
    int ans = 1;
    while(1){
        for(int i=0; i<n; i++) arr[i] = i % 2 == 0 ? prem[ i/2 ] : prem[ n/2 + (i-1) / 2] ;
        for(int i=0; i<n && prem[i] == arr[i]; i++){
            if( i == n-1 ) return ans;
        }
        ans++;
    }
}

int main(){
    int n;
    cin >> n;
    cout << reinitializePermutation(n);
    return 0;
}