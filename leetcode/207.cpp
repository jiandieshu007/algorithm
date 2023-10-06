#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    sort(prerequisites.begin(), prerequisites.end(), [](vector<int> & a, vector<int>& b) {
        return a[0] != b[0] ? a<b : a[1] < b[1]; 
    });
    vector<set<int>> lis(10010);

    size_t idx = 0;
    while( idx < prerequisites.size()){
        if( lis[ prerequisites[idx][1] ].find( prerequisites[idx][0] ) != lis[prerequisites[idx][1]].end() ){
            return false;
        }
        lis[ prerequisites[idx][0] ].insert( prerequisites[idx][1] );
        idx++;
    }
    return true;
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pre(m, vector<int>(2));
    for (int i = 0; i < m; ++i){
        cin >> pre[i][0] >> pre[i][1];
    }
    cout << canFinish(n, pre);
    return 0;
}