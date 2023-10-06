#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void sortColors(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n -1;
    for(int i=0; i<n; i++){
        if( nums[i] == 0 ){
            swap( nums[l], nums[i] );
            l++;
        }else if(  nums[i] == 2){
            swap(nums[i], nums[r] );
            r--;
            n--;
            i--;
        }
    }
}

int main(){
    vector<int> v = {1, 2, 0};
    stack<int> p;
    p.push(1);
    v(p);
    sortColors(v);
    return 0;
}