#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

#define Square(x) x*x
int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    int n = ages.size();
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i] = {scores[i], ages[i]};
    }
    sort(arr.begin(), arr.end());
    vector<int> f(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i].second >= arr[j].second)
            {
                f[i] = max(f[i], f[j]);
            }
        }
        f[i] += arr[i].first;
    }
    return *max_element(f.begin(), f.end());
}

int Y(int x){
    return x;
}


void Cout(int * list){
    for (int *l = list; l != nullptr; l++){
        cout << *l << endl;
    }
}

int Sum( int a[][4], int row){
    int res = 0;
    for (int i = 0; i < row;i++){
        for (int j = 0; j < 4; j++){
            res += a[i][j];
        }
    }
    return res;
}

const string & version(string& s1, const string & s2){
    s1 = s2 + s1 + s2;
    return s1;
}
void reset(int* p){
    *p = 1;
    p = 0;
}

void F(const int & arr);
void f(const int p[], const int & size ){
    for (int i = 0; i < size; ++i)
    {
        cout << p[i] << endl;
    }
}

int Maxer(const int x, const int * p){
    return max(x, *p);
}
int main(){
    int x[] = {0, 1, 2};
    f(x, 3);
    return 0;
}

void F(int &arr)
{

}
