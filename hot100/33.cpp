#include<iostream>
#include<vector>
using namespace std;

int f( const vector<int> & x, int  l, int  r, const int & t){
    while( l <= r){
        int mid = ( l + r) / 2;
        if( x[mid] > t){
            r = mid - 1;
        }else if( x [mid] < t ){
            l = mid+1;
        }else return mid;
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
    int t, res, m = nums[0];
    int l = 0, r = nums.size() - 1;
    while (l < r)
    {
        int mid = (l + r + 1)/ 2;
        if (nums[mid] < m )
        {
            r = mid -1 ;
        }
        else if ( nums[mid] > m )
        {
            
            m = nums[mid];
            t = mid;
        }
    }
    if( target >= nums[0] && target <= nums[t] ){
        res = f(  nums, 0 , t, target);
    }else{
        res  = f( nums, t+1, nums.size()-1, target);
    }
    return res;
}






int main(){
    int n;
    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++ )
        cin >> num[i];
    cout << search(num, 0);
    return 0;
}