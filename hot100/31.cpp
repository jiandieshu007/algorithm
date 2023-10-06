#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    if( nums.size() == 1) return ;
    int x= -1, y  , t = 101;;
    for(size_t i= nums.size()-1 ; i ; i--){
        if( nums[i] > nums[i-1] ){
            x = i-1;
            break;
        }
    }
    if( x == -1 ){
        sort(nums.begin(), nums.end());
        return ;
    }
    for(size_t i = x+1; i < nums.size(); i++){
        if( nums[i] >  nums[x]  &&  nums[i] < t ){
            t = nums[i];
            y = i;
        }
    }
    swap( nums[x], nums[y] );
    sort(nums.begin()+x+1, nums.end() );
}

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    nextPermutation(x);
    return 0;

}