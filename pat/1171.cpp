#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int n, m, index_ans=0, index_fu;
    cin>>n>>m;
    vector<int> full(n);
    for(int i=0; i<n; i++) cin>>full[i];
    
    vector<vector<int>> ans(n);
    
    vector<int> que(m);
    
    int min= 0x80000000;
    for(index_fu=0; index_fu < m; index_fu++) que[index_fu] = full[ index_fu];
    vector<int> remain;
    while( index_fu < n){
        int min_index, min_que= 0x7fffffff;
        for(int i=0; i<m; i++){
            if( que[i] < min_que && que[i] > min ){
                min_index = i;
                min_que = que[i];
            }
        }
        if( min_que == 0x7fffffff ){
            min = 0x80000000;
            index_ans++;
            continue;
        }
        ans[index_ans].push_back(min_que);
        min = min_que;
        que[min_index] = full[index_fu++];
        if( index_fu == n){
            for(int i=0; i<m; i++) remain.push_back( que[i] );
        }
    }

    sort(remain.begin(), remain.end());
    int k;
    for ( k = 0; k < remain.size(); k++){
        if( remain[k] > min){
            for (int i = k; i < remain.size(); i++)
                ans[index_ans].push_back(remain[i]);
            break;
        }
    }
    if( k ){
        index_ans++;
        for (int i = 0; i < k; i++ )
            ans[index_ans].push_back(remain[i]);
    }

        for (int i = 0; i <= index_ans; i++)
        {
            if (i)
                cout << endl;
            for (int j = 0; j < ans[i].size(); j++)
            {
                if (j)
                    cout << ' ';
                cout << ans[i][j];
            }
        }
    return 0;
}