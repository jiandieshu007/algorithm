#include<iostream>
#include<vector>
using namespace std;

int wiggleMaxLength(vector<int>& nums) {
    if( nums.size() == 1 || ( nums.size() == 2 && nums[0] == nums[1] ) ) return 1;
    int res = 2;
    bool flg = true; // true 表示 前一个是大于
    int k = 1;
    while( k<nums.size() && nums[k] == nums[k-1] ){
        k++;
    }
    if( k < nums.size() &&  nums[k] < nums[k-1] ){
        flg = false;
    }
    for(int i=k+1; i<nums.size(); i++){
        if( flg ){
            while( i< nums.size() && nums[i] >= nums[i-1] ){
                i++;
            }
            if( i < nums.size() ){
                res++;
                flg = false;
            }
        }else{
            while( i < nums.size() && nums[i] <= nums[i-1] ){
                i++;
            }
            if( i < nums.size() ){
                res ++;
                flg = true;
            }
        }
    }
    return res;
}

int main(){
    vector<int> k(6);
    for (int i = 0; i < 6; i++)
        cin >> k[i];
    cout << wiggleMaxLength(k);
    return 0;
}