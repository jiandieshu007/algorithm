#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0 ) ; // accumulate(begin, end, initsum)
    if( sum < x ) return -1;
    if( sum == x ) return n;
    int left =-1  , right =0 , ans = 0x7fffffff;
    int lsum = 0, rsum = sum;
    while( left < n && lsum <=x ){
        while( right <n && lsum + rsum > x ){
            rsum -=nums[right++];
        }
        if( lsum + rsum == x ){
            ans = min(ans, left+1 + n-right);
        }
        lsum += nums[++left];
    } 
    return ans > n? -1:ans;
}

int main(){
    vector<int> v;
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << minOperations(v, x);
    return 0;
}