#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

int reverse(int k){
    int ans = 0;
    while( k ){
        ans *=10;
        ans += k%10;
        k /= 10;
    }
    return ans;
}
bool cmp(int a, int b){
    a = reverse(a);
    b = reverse(b);
    while( a && b){
        if( a%10 != b %10) return a%10 > b%10;
        else{
            a /=10, b/=10;
            if( a == 0 ) return a > b;
            if( b == 0 ) return b > a;
        }
    }
}
string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), cmp);
    string ans = "";
    for (int i = 0; i < nums.size();i++){
        ans += string(nums[i]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> k(n);
    for (int i = 0; i < n;i++){
        cin >> k[i];
    }
    cout << largestNumber(k);
    return 0;
}