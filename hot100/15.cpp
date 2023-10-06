#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end() );
    unordered_map<int,int> hass;
    for(int k=0; k<n; k++){
        if( hass[ nums[k] ] ) hass[nums[k]]++;
        else hass[nums[k]] = 1;
    }
    for (int i = 0; i < n; i += hass[nums[i]])
    {
        int j = i+1;
        while( j < n){
            int k = nums[i] + nums[j];
            if( ( -k != nums[j] && hass[ -k] ) || (-k == nums[j] && hass[-k] > 1) ) ans.push_back( vector<int>{nums[i],nums[j], -k} );
            if( nums[j] == nums[i] ) j += hass[ nums[j] ] - 1 ;
            else j += hass[nums[j] ];
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    auto a = threeSum(num);
    return 0;
}