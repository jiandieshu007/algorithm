#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> check(n);
    for(int i=0; i<n; i++) cin>>check[i];

    int x = 0, y = 0, ans = 0;
    for(int i=0; i<n; i++){
        if( x ==0 && check[i] == 1){
            int j = i;
            while( check[j] == 1){
                j++;
            }
            x += j-i;
            i = j-1;
            continue;
        }else if( x && check[i] == 0 ){
            int y = 0, z = 0;
            int j = i;
            while( check[j] == 0 ){
                j ++;
            }
            y = j-i;
            int k = j;
            while( check[k] == 1){
                k++;
            }
            z = k-j;
            ans += min( min(x, y),min(y, z) );
            i = k-1;
        } 
    }
    cout<<ans;
    return 0;
}