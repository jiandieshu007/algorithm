#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int n, sum=0, t = 0;
    cin>>n;
    vector<int> seq(n);
    for(int i=0; i<n; i++){
        cin>>seq[i];
    }
    sort(seq.begin(), seq.end() );
    for(int i=0; i<n; i++){
        sum += seq[i];
        if( i < n/2 ) t += seq[i];
    }
    if( n % 2 == 0 ) cout<<"0 ";
    else cout<<"1 ";
    cout<< sum - t;
    return 0;
}