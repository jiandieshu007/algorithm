#include <iostream>
#include<cmath>
using namespace std;

int main(){
    int n, max=0, len=0 ,t=0;
    cin>>n;
    int k = sqrt(n);
    for(int i=13; i>0; i--){
        int m = n;
        for(int j=i; j>0 ; j--){
            if( m % j == 0){
                m -= j*(m/j);
                t++;
            }else{
                if( t> len ){
                    len = t;
                    max = i;                    t = 0;
                }
                t = 0;
                break;
            }
        }
    }
    cout<<len<<endl;
    for(int i= max-len+1; i<=max; i++){
        if( i != max-len+1 ) cout<<'*';
        cout<<i;
    }
    return 0;
}