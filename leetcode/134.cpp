#include<iostream>
#include<vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int k = gas.size(), ans ;
    vector<int> remain(k), res;
    for(int i=0; i<k; i++){
        remain[i] = gas[i] -cost[i] ; // 从 i号 加油站 到 i+1的加油站 所需的油 或 剩下的油
    }

    for(int i=0; i<remain.size(); i++){
        int cos = remain[i];
        ans = i;
        while( cos > 0  && i < remain.size() -1 ){
            cos += remain[++i];
        }
        if( i == remain.size() -1&& cos >= 0 ){
            for(int j = 0; j < res.size(); j++){
                cos += res[j];
                if( cos < 0 ) return -1;
            }
            break;
        }else if( i == remain.size() && cos < 0 )
            return -1;
        if( cos < 0) res.push_back(cos);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> gas(n), cost(n);
    for (int i = 0; i < n; i++){
        cin >> gas[i];
    }
    for (int i = 0; i < n;i++){
        cin >> cost[i];
    }
    cout<<canCompleteCircuit(gas,cost);
    return 0;
}