#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    double sum= 0;
    cin>>n;
    vector<double> k(n,0);
    vector<double> s(n,0);
    for(int i=0; i<n; i++){
        cin>> k[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if( j == i ) s[j] = k[j];
            else s[j] = s[j-1] + k[j];
            sum += s[j];
        }
    }
    printf("%.2lf", sum);
    return 0;
}