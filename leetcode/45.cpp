#include<iostream>
#include<vector>
using namespace std;

// 贪心
int jump(vector<int>& nums) {
    if(nums.size() == 1  ) return 0;
    int k = nums.size(), i;
    vector<int> step(k);
    for(i=0; i<k; i++) step[i] = 0; // 初始化
    for(i=0; i<k; i++){
        if( i + nums[i] >= k-1  ) break; // 下一步就可以到达
        for(int j = i+1; j < k && j <= i+ nums[i]; j++){
            step[j] = step[i] + 1;
        }
    }
    return step[i]+1 ;
}

int main(){
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n; i++)
        cin >> k[i];
    cout << jump(k);
    return 0;
}