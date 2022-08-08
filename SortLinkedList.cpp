#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode* next):val(x),next(next){}
};

ListNode* getMiddle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head->next;

    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }

    return slow;
}

ListNode* merge(ListNode* l1,ListNode* l2){
    ListNode* head;
    ListNode* ptr;

    if(l1->val > l2->val)
    {
        head=new ListNode(l2->val);
        ptr=head;
        l2=l2->next;
    }
    else
    {
        head=new ListNode(l1->val);
        ptr=head;
        l1=l1->next;
    }

    while(l1 && l2)
    {
        if(l1->val > l2->val)
        {
            ptr->next=new ListNode(l2->val);
            ptr=ptr->next;
            l2=l2->next;
        }
        else
        {
            ptr->next=new ListNode(l1->val);
            ptr=ptr->next;
            l1=l1->next;
        }
    }

    while(l1)
    {
        ptr->next=new ListNode(l1->val);
        ptr=ptr->next;  l1=l1->next;
    }

    while(l2)
    {
        ptr->next=new ListNode(l2->val);
        ptr=ptr->next;  l2=l2->next;
    }

    return head;
}

ListNode* mergeSort(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    ListNode* mid=getMiddle(head);

    ListNode* init=head;
    ListNode* fin=mid->next;

    mid->next=NULL;

    ListNode* arr1=mergeSort(init);
    ListNode* arr2=mergeSort(fin);

    return merge(arr1,arr2);
}

int main()
{
    int n;   cin>>n;
    int arr[n];  

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ListNode* head=new ListNode(arr[0]);
    ListNode* ptr=head;

    for(int i=1;i<n;i++)
    {
        ptr->next=new ListNode(arr[i]);
        ptr=ptr->next;
    }

    head=mergeSort(head);

    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}