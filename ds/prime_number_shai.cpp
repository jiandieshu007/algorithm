#include<iostream>
#include<vector>
using namespace std;

vector<int> ans;
void shai( int n){
    vector<int> vis(n + 1, 0);

    for (int i = 2; i <= n; i++){
        if( vis[i] == 0){
            ans.push_back(i);
            for (int j = i + i; j <= n; j+=i)
                vis[j] = 1;
        }
    }
}

int main(){
    int n;
    cin >> n;
    shai(n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}