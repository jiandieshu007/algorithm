#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

int maxSumDivThree(vector<int>& nums) {
    int ans = accumulate(nums.begin(), nums.end(), 0), two_sum = 0, one;
    sort(nums.begin(), nums.end() );
    int k = ans % 3;
    
    if( k == 0 ) return ans;
    if( k == 1 ){
        for(size_t i = 0; i < nums.size(); i++){
            if( nums[i] % 3 == 1 ){
                ans -= nums[i];
                break;
            }
        }
    }else{
        bool flg = false;
        int cnt = 0;
        for(size_t i = 0; i < nums.size(); ++i ){
            if( nums[i] % 3 == 1 && cnt < 2){
                two_sum += nums[i];
                cnt++;
            }
            if( nums[i] % 3 == 2 && flg == false){
                one = nums[i];
                flg = true;
            }
            if( flg == true && cnt == 2 ){
                break;
            }
        }
        if( cnt == 2 ) ans -= min(one, two_sum);  
        else ans -= one;
    }
    return ans;
}

int main(){
    vector<int> v;
    int n;
    cin >> n;
    while(n--){
        int t;
        cin >> t;
        v.push_back(t);
    }
    cout << maxSumDivThree(v);
    return 0;
}