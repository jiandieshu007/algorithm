#include<iostream>
#include<unordered_map>
#include<vector>
#include<set>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    set<int> s;
    vector<int> res;
    unordered_map<int,int> m;
    int n = nums.size();
    int k = n / 3;
    for(int i=0; i<nums.size(); i++){
        m[ nums[i] ] ++;
        if( m[nums[i]] > k ) s.insert( nums[i] );
    }
    for( auto it = s.begin(); it != s.end(); it++){
        res.push_back( *it);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i];
    }
    majorityElement(s);
    return 0;
}