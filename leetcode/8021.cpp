#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

int minOperations(vector<int>& nums, int target) {
    unordered_map<int, int> ump;
    string tt;
    int ans = 0, mm= 0, j = 0;
    vector<int> v;
    while( target ){
        v.push_back(target % 2);
        target /= 2;
    } 
    for(int i=0; i<nums.size(); ++i){
        ump[ nums[i] ]++ ;
        mm = max(mm, nums[i] );
    }
    for(int i=tt.size() -1; i>=0 ; --i){
        if( v[i]  ){
            if( !ump[ pow(2,i) ] || v[i] > ump[ pow(2,i)]){
                int j = pow(2,i), k = 0;
                while( j <= mm && pow(2,k) < v[i] ){
                    if(pow(2,k) >= v[i]  && ump[j] ) break;
                    j*=2;
                    ++k;
                }
                if( ump[j] ){
                    ans += k;       
                    if( pow(2,k) >= v[i]){
                        --ump[j];
                        ump[pow(2,i) ] += pow(2,k)-v[i];
                    }else{
                        int k = v[i] - ump[pow(2,i) ] - pow(2,k);
                        ump[ pow(2,i) ] = 0;
                        if( i ) v[i-1] += 2*v[i];
                        else return -1;
                    }
                }else {
                    if( i ) v[i-1] += 2*v[i];
                    else return -1;
                }
            }
        }
    }
    return ans;
}

int main(){
    int n, t;
    cin >> n >> t;
    vector<int>v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << minOperations(v, t);
    return 0;
}