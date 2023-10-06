#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int m = 6;
struct node{
    int id, sum, t;
    vector<int> grade(m, -1);
    bool to_complie;
};

void print(int r, int i){
    printf("%d %5d %d", r, dic[i].id, dic[i].sum);
    for(int j=1; j<=k; j++){
        cout<<' ';
        if( dic[i].grade[j] != -1 )cout<< dic[i].grade[j];
        else cout<<'-';
    }
}
bool cmp( node a, node b){
    if( a.sum == b.sum ){
        if( a.t == b.t ) return a.id< b.id;
        else return a.t>b.t;
    }else return a.sum > b.sum;
}
int main(){
    int n, k, m, rank = 1;
    cin >> n>> k >> m;
    vector<node> dic(n);
    for(int i=0; i<n; i++ ){
        dic[i].sum = 0;
        dic[i].id = i+1;
        dic[i].to_complie = false;
    }
    vector<int> full(k+1, -1);
    for(int i=1; i<= k; i++ ) cin>>full[i];
    
    while( m -- ){
        int id_, a, b;
        cin>> id_>> a>> b;
        if( b >= 0 ){
            dic[id_ -1].grade[a] = b;
            dic[id_ -1 ].to_complie = true;
        }
    }
    for(int i=0; i< n; i++){
        for(int j=1; j<=k; j++ ){
            if( dic[i].grade[j] > -1 ) dic[i].sum += dic[i].grade[j];
            if( dic[i].grade[j] == full[j] ) dic[i].t++;
        }
    }
    
    sort(dic.begin(), dic.end()+n, cmp );
    print(rank, 0);
    for(int i=1; i<n; i++){
        if( dic[i].to_complie == false ) break;
        if( dic[i].sum == dic[i-1].sum ){
            cout<<endl;
            print(rank,1);
        }else{
            rank = i+1;
            cout<<endl;
            print(rank, i);
        }
    }
    return 0;
}