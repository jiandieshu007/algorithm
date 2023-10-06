#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
};
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // return l1
        ListNode *p = l1, *q=l2;
        while( q && p ){
            p->val += q->val;
            if( p->val > 9 ){
                p->val -= 10;
                if( p->next ){
                    p = p->next;
                    p->val += 1;
                }else{
                    ListNode* k = (ListNode*) new ListNode; 
                    k->val = 1;
                    k->next = nullptr;
                    p->next = k;
                    p = p->next;
                }
            }else if(  !p->next ){
                q = q->next;
                break;
            }else p = p->next;
            q = q->next;
        }
        if( q ) p->next = q;
        while( p && p->val > 9){
            p->val -=10;
            if( !p->next ){
                ListNode* k = (ListNode*) new ListNode;
                k->val = 1;
                k->next = nullptr;
                p->next = k;
                break;
            }else{
                p=p->next;
                p->val+=1;
            }
        }
        return l1;
    }
ListNode* createlist(int n){
    ListNode *L = (ListNode*) new ListNode;
    L->next = nullptr;
    while( n--){
        ListNode *k = (ListNode *)new ListNode;
        cin >> k->val;
        k->next = L->next;
        L->next = k;
    }
    return L->next;
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;
    ListNode *l1, *l2;
    l1 = createlist(n1);
    l2 = createlist(n2);
    addTwoNumbers(l1, l2);
    return 0;
}