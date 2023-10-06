#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    int k = ( m+n-1 )/ 2;
    int i1 = 0, i2 = 0;
    while( k ){
        if( i1 < m && i2 < n && nums1[i1] < nums2[i2] ) i1++;
        else if( i1 < m && i2 < n ) i2++;
        else break;
        k--;
    }
    if( k ){
        if( i1 < m ){
            while( k-- ){
                i1++;
            }
            return (m+n)%2 == 0? 1.0*(nums1[i1] + nums1[i1+1]) /2 : 1.0*nums1[i1];
        }else if( i2 < n ){
            while( k-- ){
                i2++;
            }
            return (m+n)%2 == 0? 1.0*(nums2[i2] + nums2[i2+1]) /2 : 1.0*nums2[i2];
        }
    }else{
        if( i1 < m && i2 < n ){
            double ans = 0;
            int k = (m+n)%2 == 0 ? 2: 1;
            int t = k;
            while( i1 < m && i2 < n && k ){
                if( nums1[i1] < nums2[i2 ] ){
                    ans +=  nums1[i1];
                    i1++;
                }else{
                    ans += nums2[i2];
                    i2++;
                }
                k--;
            }
            if( k && i1 < m ) ans += nums1[i1];
            else if( k && i2 < n ) ans +=nums2[i2];

            return ans/t;
        } else if ( i1 == m ) return (m+n)%2 == 0? 1.0*(nums2[i2] + nums2[i2+1]) /2 : 1.0*nums2[i2];
        else return (m+n)%2 == 0? 1.0*(nums1[i1] + nums1[i1+1]) /2 : 1.0*nums1[i1];
    }
    return 0;
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<int> v1(m), v2(n);
    for(int i=0; i<m; i++) cin>>v1[i];
    for(int i=0; i<n; i++) cin>>v2[i];

    cout<<findMedianSortedArrays(v1,v2);
    return 0;
}