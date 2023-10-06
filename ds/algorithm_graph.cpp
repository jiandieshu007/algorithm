#include<iostream>
#include<vector>
using namespace std;

void dijkstra(vector<vector<int>> &graph, int k, vector<int> & ans){
    // 初始化距离矩阵
    for (int i = 0; i < graph[k].size(); i++){
        ans[i] = graph[k][i];
    }
    for (int i = 0; i < graph.size(); i++){
        if( i != k ){
            for (int j = 0; j < graph.size(); j++){
                if( i == j )
                    continue;
                if(   ans[i] > graph[i][j] + graph[j][k]  )
                    ans[i] = graph[i][j] + graph[j][k];
            }
        }
    }
}

