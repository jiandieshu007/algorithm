#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

bool dfs(int z, string tar, int x, int y, int &sum, bool & flg ){
    if(x == tar.size() &&  sum == z ){
        flg = true;
        return flg;
    }
    if( sum > z ) return false; // 剪枝
    for(int i=x; i<tar.size(); i++){
        for(int j=1; j<=y && i+j <= tar.size() ; j++){
            int k = stoi( tar.substr(i,j) );
            if( k > z ) break; // 剪枝
            sum += k;
            dfs(z,tar,i+j, y, sum, flg);
            sum -= k;
        }
    }
    return flg;
}

int main(){
    int n;
    cin >> n;
    int ans = 0,  s = 0;
    for(int i=1; i<=n ; i++ ){
        bool flg = false;
        int sum = 0;
        if( dfs(i, to_string((int)pow(i,2)), 0, to_string(i).size(), sum, flg)  ) ans += pow(i,2);
    }
    cout << ans;
    return 0;
}