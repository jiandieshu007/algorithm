#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
 

int main(){
    int n, t, s, pre, num = 0;
    bool flg= false ;
    cin>>n;
    vector<int> ans(1002,-1);
    vector<int> res(1002,0);
    for(int i=0; i<n; i++){
        vector<int> v;
        cin>>t;
        cin.get();
        for(int j=0; j<t; j++){
            cin>>s;
            v.push_back(s);
        }
        if( i == 0){
            for(int j =0; j<t; j++){
                ans[ v[j] ] = i;
            }
            res[i]++;
        }else{
            for(int j=0; j<t; j++){
                if( ans[ v[j] ] != -1 ){
                    flg = true;
                    if( pre == -1){
                        pre = ans[v[j]];
                    }else if( pre != -1 && pre != ans[v[j]]){
                        res[pre] += res[ ans[v[j]] ];
                        res[ ans[v[j]] ] = 0;
                        int tmp = res[v[j]];
                        for (int k = 1; k < 1001; k++){
                            if( ans[k] == tmp )
                                ans[k] = pre;
                        }
                        break;
                    }
                }
                ans[ v[j] ] = i;
            }
            if( flg == true ){
                for(int j=0; j<t; j++){
                    ans[ v[j] ] = pre;
                }
                res[pre] ++;
            }else
                res[i]++;
        }
        flg = false;
        pre = -1;
    }
    sort(res.begin(), res.end(), greater<int>());
    for (int i = 0; i < n;i++){
        if( res[i] )
            num++;
        else
            break;
    }
    cout << num << endl;
    for (int i = 0; i < num; i++){
        if( i )
            cout << ' ';
        cout << res[i];
    }
    return 0;
}