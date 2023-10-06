#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

bool judge( string s ){
    int i=0;
    bool flg = false; //记录小数点的位置
    if( s[0] == '-' ) i = 1;
    while( i<s.size() ){
        if( s[i] >='0' && s[i] <='9' || (s[i] =='.' ) ){
            if(s[i] == '.' && flg == true){
                return false;
            }
            if( s[i] == '.' && flg == false){
                flg = true;
            }
       }else return false;
       i++;
    }
    if( stoi(s) > 1000 || stoi(s) < -1000) return false;
    for(i=0; i<s.size(); i++){
        if( s[i] =='.'){
            if(s.size() - i - 1 > 2 ) return false;
            break;
        }
    }
   return true;
}

double string_double( string s){
    double  ans = 0;
    int  i = 0, t=0;
    bool flg = false;
    if(s[0] == '-'){
        i = 1;
        flg = true;
    }
    while( i<s.size( )){
        if(s[i] !='.'){
            ans *= 10;
            ans += s[i]-'0';
        }else t = i;
        i++;
    }
    ans /= pow(10, s.size() - t - 1);
    if (flg == true)
        ans *= -1;
    return ans;
}
int main(){
    int n;
    double ans = 0, num = 0;
    string s;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>> s;
        if( judge(s) ){
            ans += string_double(s);
            num++;
        }else{
            cout<<"ERROR: "<<s<<" is not a legal number"<<endl;
        }
    }
    printf("The average of %d number is %.2f", num, ans/num);
    return 0;
}

