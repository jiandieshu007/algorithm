#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<numeric>
using namespace std;

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        for(int i=0; i<nums.size(); ++i){
            int k = s.empty() ? 1 :gcd(s.top(), nums[i] );
            while( !s.empty() &&  k > 1 ){
                int x = s.top()/k*nums[i]/k;
                k *= x;
                nums[i] = k;
                s.pop();
                k = s.empty() ? 1 :gcd(s.top(), nums[i] );
            }
            s.push(nums[i]);
        }
        int n = s.size();
        vector<int> ans(n);
        for(int i = n-1; i >=0; --i){
            ans[i] = s.top();
            s.pop();
        }
        return ans;
    }

    int main(){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        auto ans = replaceNonCoprimes(v);
        return 0;
    }