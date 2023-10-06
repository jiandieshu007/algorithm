#include<iostream>
#include<string>
using namespace std;

bool areSentencesSimilar(string sentence1, string sentence2) {
    int k;
    int n1 = sentence1.size()-1 , n2 = sentence2.size() -1 ;
    for( k =0; k < sentence2.size() && k < sentence1.size() ; k++){
        if( sentence1[k] != sentence2[k] ) break;
    }
    while( n1 >= 0 && n2 >= 0){
        if( sentence1[n1] !=  sentence2[n2] ) break;
        n1--;
        n2--;
    }
    if(  ( k == sentence1.size()  && k == sentence2.size() )
        || ( k ==sentence1.size() && k < sentence2.size() && sentence2[k] == ' ')
        || ( k == sentence2.size() && k < sentence1.size() && sentence1[k] ==' ')
        || ( k && n1 && n1 == k -2 ) || ( k && n2 && n2 == k -2  ) || 
        ( n1 == -1 && n2 >= 0  && sentence2[n2] == ' ') 
        || ( n2 == -1 && n1 >= 0  && sentence1[n1] ==' ' )  ) return true;
    return false;
}

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << areSentencesSimilar(s1, s2);
    return 0;
}