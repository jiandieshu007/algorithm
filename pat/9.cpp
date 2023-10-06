#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, ans = 0x7fffffff;
    cin>>n;
    vector<int> info;
    while( n ){
        int b = n % 10;
        info.push_back(b);
        n/=10;
    }
    n = info.size();
    for(int i=n-1; i; i--){
        for(int j = i-1; j>=0; j--){
            int tmp = 0;
            for(int k=n-1; k >=0; k--){
                if( k != i && k != j ){
                    tmp *=10;
                    tmp += info[k];
                }
            }
            if( tmp < ans ) ans = tmp;
        }
    }
    cout<<ans;
    return 0;
}