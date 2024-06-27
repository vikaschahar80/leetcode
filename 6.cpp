void merge(vector < int > & arr, int s, int e){
    int mid = s+(e-s)/2;
    int len1 = mid-s+1;
    int len2 = e-mid;
    int* a = new int[len1];
    int* b = new int[len2];
    int arrindex = s;
    for(int i = 0;i<len1;i++){
        a[i] = arr[arrindex++];
    }
    arrindex = mid+1;
    for(int i = 0;i<len2;i++){
        b[i] = arr[arrindex++];
    }
    int i1=0;
    int i2= 0;
    arrindex = s;
    while(i1<len1&&i2<len2){
        if(a[i1]<b[i2]){
            arr[arrindex++] = a[i1++];
        }
        else{
            arr[arrindex++]=b[i2++];
        }
    }
    while(i1<len1){
        arr[arrindex++] = a[i1++];
    }
    while(i2<len2){
        arr[arrindex++] = b[i2++];
    }
}
void mergestart(vector < int > & arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = s+(e-s)/2;
    mergestart(arr,s,mid);
    
    mergestart(arr, mid+1,e);
    merge(arr,s,e);
}
void mergeSort(vector < int > & arr, int n) {
    mergestart(arr,0,n-1);
}
