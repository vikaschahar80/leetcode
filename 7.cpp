#include <bits/stdc++.h> 
int partition(vector<int>& arr, int s,int e){
    int pivot = arr[s];
    int count = 0;
    for(int i =s+1;i<=e;i++){
        if(arr[i]<=pivot){
            count++;
        }
    }
    swap(arr[s+count],arr[s]);
    int i = s;
    int j = e;
    while(i<s+count&&j>s+count){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<s+count&&j>s+count){
            swap(arr[i++],arr[j--]);
        }

    }
    return s+count;
}
void quick(vector<int>& arr,int s,int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);
    quick(arr,s,p-1);
    quick(arr,p+1,e);
}
vector<int> quickSort(vector<int> arr)
{
    quick(arr,0,arr.size()-1);
    return arr;
}
