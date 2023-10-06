#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int minStoneSum(vector<int>& piles, int k) {
    int n = piles.size();
    sort(piles.begin(), piles.end() );
    while( k ){
        piles[n-1] = (piles[n-1] + 1) /2;
        for(int i=n-2; i>=0; i--){
            if( piles[i] > piles[i+1] ) swap(piles[i], piles[i+1] );
            else break;
        }
        k--;
    }
    int ans = accumulate(piles.begin(), piles.end(), 0 );
    return ans;
}

int main(){
    int n, k, t;
    cin >> n >> k;
    vector<int> s;
    while( n -- ){
        cin >> t;
        s.push_back(t);
    }
    cout << minStoneSum(s, k);
    return 0;
}