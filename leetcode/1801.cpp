#include<iostream>
#include<map>
#include<vector>
using namespace std;

void cal(map<int,int> &buy, map<int,int> &sell){
    if( buy.begin() == buy.end() || sell.begin() == sell.end() ) return;
    auto itbuy = buy.rbegin(); // 指向尾部的逆序迭代器
    itbuy++;
    auto itsell = sell.rend(); //指向头部的 正序迭代器
    if(itbuy-> first >= itsell->first ){
        while( itbuy-> first >= itsell->first ){
            itbuy->second --;
            itsell->second --;
            if( itbuy->second == 0 ){
                buy.erase( itbuy->first);
                itbuy++;
            }
            if( itsell->second == 0){
                sell.erase( itsell->first);
                itsell++;
            }
            if( buy.begin() == buy.end() || sell.begin() == sell.end() ) return;
        }
    }
}
int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    long Max =  1e9+7, ans = 0;
    map<int,int>buy; // price, amount;
    map<int,int>sell;
    for(int i=0; i<orders.size(); i++){
        if( orders[i][2] == 0 ){
            if( buy.find( orders[i][0]) != buy.end() ) buy[ orders[i][0] ] += orders[i][1]; // find 返回迭代器
            else buy.insert( pair<int,int>(orders[i][0], orders[i][1]) );
        }else{
            if( sell.find( orders[i][0]) != sell.end() ) sell[ orders[i][0] ] += orders[i][1];
            else sell.insert( pair<int,int>(orders[i][0], orders[i][1] ) ) ;
        }
        cal(buy, sell);
    }
    for( auto it = buy.begin(); it != buy.end(); it++){
        ans += it->second;
        ans %= Max;
    }
    for( auto it = sell.begin(); it != sell.end(); it++){
        ans +=  it->second;
        ans %= Max;
    }
    return ans;
}   

int main(){
    vector<vector<int>> orders;
    int n, a, b, c;
    cin>>n;
    while( n--){
        vector<int> tmp;
        cin >> a >> b >> c;
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        orders.push_back(tmp);
    }
    cout << getNumberOfBacklogOrders(orders);
    return 0;
}