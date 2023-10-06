#include<iostream>
#include<cstdlib>
#include<unordered_map>
using namespace std;

void judge( char c, bool &flg){
    if( c >= '0' && c <= '9') flg = true;
    else flg = false;
}
unordered_map<int,string> e_m1{
    {0,"tret"},{1,"jan"},{ 2,"feb"}, {3,"mar"}, {4,"apr"}, {5,"may"}, {6,"jun"}, 
    {7,"jly"}, {8,"aug"}, {9,"sep"}, {10,"oct"}, {11,"nov"}, {12,"dec"}
};

unordered_map<int,string> e_m2{
    {1,"tam"}, {2,"hel"}, {3,"maa"}, {4,"huh"}, {5,"tou"}, {6,"kes"}, 
    {7,"hei"}, {8,"elo"}, {9,"syy"}, {10,"lok"}, {11,"mer"}, {12,"jou"}
};

unordered_map<string,int> m_e1{
    {"tret",0},{"jan",1},{ "feb",2}, {"mar",3}, {"apr",4}, {"may",5}, {"jun",6}, 
    {"jly",7}, {"aug",8}, {"sep",9}, {"oct",10}, {"nov",11}, {"dec",12}
};

unordered_map<string,int> m_e2{
    {"tam",1}, {"hel",2}, {"maa",3}, {"huh",4}, {"tou",5}, {"kes",6}, 
    {"hei",7}, {"elo",8}, {"syy",9}, {"lok",10}, {"mer",11}, {"jou",12}
};

int main(){
    int n;
    string s;
    bool flg;
    cin>>n;
    cin.get();
    for(int i=0; i<n; i++){
        if( i ) cout<<endl;
        getline(cin, s);
        judge(s[0], flg);
        if( flg ){
            int t = stoi(s);
            if( t >=13 ){
                cout<< e_m2[ t/13 ]<<' ';
                t %= 13;
            }
            if( t ) cout<<e_m1[t];
        }else{
            int t=0;
            for(int j=0; j<s.size(); j+=4){
                if( m_e2[ s.substr(j,3) ] ) t = 13 *m_e2[ s.substr(j,3) ];
                if( m_e1[ s.substr(j,3) ] ) t += m_e1[s.substr(j,3)] ;
            }
            cout<<t;
        }
    }
    return 0;
}