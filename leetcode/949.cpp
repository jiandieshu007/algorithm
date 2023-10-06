#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool find(vector<int>& arr, int x, string &s, int t){
    if( t == 2 && (s[0] =='0' || s[0] =='1' ) )
        x = 9;
    int i=0;
    while( i < arr.size() && arr[i] <= x){
        i++;
    }
    if( i <= arr.size() ){
        s += arr[i - 1] + '0';
        arr.erase(arr.begin() + i -1 );
        return true;
    }else return false;
}
string largestTimeFromDigits(vector<int>& arr) {
    string ans ="";
    sort(arr.begin(), arr.end() );
    if( arr[0] > 2 ) return "";
    if( find(arr, 2, ans,1 ) == false ) return "";
    if( find(arr,3, ans, 2) == false ) return "";
    ans +=':';
    if( find( arr,5, ans , 3) == false ) return "";
    ans += arr[0] + '0';
    return ans;
}

int main(){
    vector<int> arr;
    int t;
    for (int i = 0; i < 4; i++){
        cin >> t;
        arr.push_back(t);
    }
    cout << largestTimeFromDigits(arr);
    return 0;
}