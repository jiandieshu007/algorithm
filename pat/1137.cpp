#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using namespace std;

const double expp = 0.5;
const int m = 10010;
struct stu{
    string id;
    int Online, gmid, gfin, G;
    stu(){
        Online = gmid = gfin = -1;
    }
}info[m];


bool cmp(stu a, stu b){
    if( a.G != b.G ) return a.G> b.G;
    else return a.id < b.id;
}
int main(){
    int n, m, k, index = 1, t;
    cin >> n >> m >> k;
    string s;
    unordered_map<string, int> vis;
    while(n--){
        cin>>s >> t;
        if( vis[s] == 0 ){
            vis[s] = index;
            info[index].Online = t;
            info[index].id = s;
            index++;
        }else{
            info[vis[s]].Online = t;
        }
    }
    while(m--){
        cin>>s >> t;
        if( vis[s] == 0 ){
            vis[s] = index;
            info[index].gmid = t;
            info[index].id = s;
            index++;
        }else{
            info [ vis[s] ].gmid = t;
        }
    }
    while(k--){
        cin>>s >> t;
        if( vis[s] == 0 ){
            vis[s] = index;
            info[index].gfin = t;
            info[index].id = s; 
            index++;
        }else{
            info [ vis[s]].gfin = t;
        }
    }
    for(int i=1; i<index; i++){
        if( info[i].Online >=200 ){
            if( info[i].gfin >= info[i].gmid ){
                info[i].G = info[i].gfin;
            }else{
                double x = 0;
                if( info[i].gmid != -1 ) x += 0.4*info[i].gmid;
                if( info[i].gfin != -1 ) x += 0.6*info[i].gfin;
                info[i].G = x+expp;
            }
        }
    }
    sort(info+1, info+index, cmp );
    for (int i = 1; info[i].G >= 60; i++){
        if( i != 1 )
            cout << endl;
        cout<<info[i].id<<" "<<info[i].Online<<' '<<info[i].gmid<<' '<<info[i].gfin<<' '<<info[i].G;
    }

        return 0;
}