#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeZeroSumSublists(ListNode* head) {
    bool flg = false;
    
    int i = 0;
    vector<int> ps;
    ps.push_back(0);
    unordered_map<int,int> um;
    um[0] = 1;
    for( ListNode* it = head ; it ; ++it ){
        ps.push_back( it->val + ps[i] );
        ++i;
        if( um[ ps[i] ] ){
            for(int j = i-1; j >=0; --j){
                if( ps[j] == ps[i] ){
                    if( j == 0 ){
                        head = it->next;
                    }else{
                        ListNode* k = head;
                        j--;
                        while( j--){
                            ++k;
                        }
                        k->next = it->next;
                    }
                    break;
                }
            }
            flg = true;
            break;
        }
        um[ps[i]] = 1;
    }

    if( flg == false ) return head;
    else return removeZeroSumSublists( head);
}


ListNode* build(int n){
    ListNode *head = new ListNode;
    ListNode *p = head;
    while( n--){
        ListNode *q = new ListNode;
        cin >> q->val;
        q->next = nullptr;
        p->next = q;
        p = q;
    }
    p = head->next;
    delete head;
    return p;
}

int main(){
    int n;
    cin >> n;
    auto k = build(n);
    auto ans = removeZeroSumSublists(k);

    return 0;
}