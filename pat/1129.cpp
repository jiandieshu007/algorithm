#include<iostream>
#include<vector>
using namespace std;

const int M = 50010;
struct node{
    int id, cnt;
    node(){
        id = cnt = 0;
    };
};

int main(){
    int n, k, tmp;
    cin>>n>>k;
    vector<node> ans;
    vector<int> vis(M,-1); // 定位存放在ans中的下标
    for(int i=0; i<n; i++){
        if( i > 1 ) cout<<endl;
        if( ans.size() == 0 ){
            node t;
            cin>>t.id;
            t.cnt = 1;
            ans.push_back(t);
            vis[t.id] = 0;
            continue;
        }else{
            cin>>tmp;
            cout<<tmp<<':';
            for(int i=0; i<k && i<ans.size(); i++) cout<<' '<<ans[i].id;
            if( vis[tmp] == -1 ){
                node t;
                t.id = tmp;
                t.cnt = 1;
                ans.push_back(t);
                vis[tmp] = ans.size() - 1;
                for(int j = ans.size()-1; j >0; j--){
                    if( ans[j].cnt > ans[j-1].cnt || ( ans[j].cnt == ans[j-1].cnt && ans[j].id<ans[j-1].id) ){
                        vis[ ans[j-1].id ] = j;
                        swap( ans[j], ans[j-1]);
                        vis[ t.id ] = j-1;
                    }else break;
                }
            }else{
                ans[ vis[tmp] ].cnt++;
                for(int j = vis[tmp]; j >0; j--){
                    if( ans[j].cnt > ans[j-1].cnt || ( ans[j].cnt == ans[j-1].cnt && ans[j].id<ans[j-1].id) ){
                        vis[ ans[j-1].id ] = j;
                        swap( ans[j], ans[j-1]);
                        vis[ tmp ] = j-1;
                    }else break;
                }
            }
        }
    }
    return 0;
}