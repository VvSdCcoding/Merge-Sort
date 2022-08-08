#include <bits/stdc++.h>
using namespace std;

void merge(int* arr,int lo,int hi){
    int mid=(lo+hi)/2;

    //Size of first array
    int lsize=mid-lo+1;
    //Size of second array
    int rsize=hi-mid;

    int* f=new int[lsize];
    int* s=new int[rsize];

    int st=lo;

    for(int i=0;i<lsize;i++){
        f[i]=arr[st++];
    }

    st=mid+1;

    for(int i=0;i<rsize;i++){
        s[i]=arr[st++];
    }

    //Merge two sorted arrays
    int ff=0,ss=0,curr=lo;

    while(ff<lsize && ss<rsize){
        if(f[ff]<=s[ss]){
            arr[curr++]=f[ff++];
        }else{
            arr[curr++]=s[ss++];
        }
    }

    while(ff<lsize){
        arr[curr++]=f[ff++];
    }

    while(ss<rsize){
        arr[curr++]=s[ss++];
    }
}

void mergeSort(int* arr,int lo,int hi){
    if(lo>=hi){
        return;
    }

    int mid=(lo+hi)/2;

    //Divide array into half
    mergeSort(arr,lo,mid);
    mergeSort(arr,mid+1,hi);

    //Merge two sorted arrays
    merge(arr,lo,hi);
}

int main()
{
    int n;    cin>>n;
    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}