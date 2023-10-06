#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    string id;
    int height;
};

bool cmp( node a, node b){
    if( a.height != b.height) return a.height>b.height;
    else return a.id<b.id;
}

int main(){
    int n, m, k1, k2;
    cin>> n>> m;
    vector<node> info(n);
    vector<string> ans(n);
    for(int i=0; i<n;i++){
        cin>>info[i].id>>info[i].height;
    }
    
    sort( info.begin(), info.end() , cmp);
    
    k1 = n/m;
    k2 = n - k1 *( m-1) ;
    for(int i=0; i<n; ){
        if( i == 0){
            int t = k2/2, index = i;
            for (int j = i+ t; j >= i; j--){
                if( j == i + t ){
                    ans[j] = info[index++].id;
                }else{
                    ans[j] = info[index++].id;
                    if( 2*t - j < k2 )
                        ans[ 2 * t - j] = info[index++].id;
                }
            }
            i += k2;
        }else{
            int t = k1 /2, index = i;
            for (int j = i+ t; j >= i; j--){
                if( j == i + t ){
                    ans[j] = info[index++].id;
                }else{
                    ans[j] = info[index++].id;
                    if(  2*t - j < k1 )
                        ans[2*i + 2 * t - j] = info[index++].id;
                }
            }
            i += k1;
        }
    }
    for (int i = 0; i < n; ){
        if( i == 0 ){
            for (int j = i; j < i + k2; j++){
                if( j != i) cout << ' ';
                cout << ans[j];
            }
            i += k2;
            if( i != n ) cout << endl;   
        }else{
            for(int j=i; j< i+k1; j++){
                if( j != i ) cout<<' ';
                cout<<ans[j];
            }
            i += k1;
            if( i !=n ) cout<<endl;
        }
    }
    return 0;
}