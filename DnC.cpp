#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int s,int e)
{
    //TODO
    
}

void mergeSort(int arr[],int s,int e)
{
    if(s<=e)
    {
        return;
    }
    int mid =(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e)
}

int main()
{
    return 0;
}