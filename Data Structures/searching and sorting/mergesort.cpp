#include<iostream>
using namespace std;


void merge(int arr[], int s, int m, int e){
    int n1 = m-s+1;
    int n2 = e-m;
    int a[n1], b[n2]; //Temporary Arrays
    for(int i=0; i<n1; i++){
        a[i]=arr[s+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[m+1+i];
    }
    int i=0;
    int j=0;
    int k=s;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++;
            i++;
        }else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1){
         arr[k]=a[i];
            k++;
            i++;
    }
    while(j<n2){
        arr[k]=b[j];
            k++;
            j++;
    }
}


void mergeSort(int arr[], int s, int e){
    if(s<e){
        int m = (s+e)/2;
        mergeSort(arr, s, m);
        mergeSort(arr, m+1, e);
        merge(arr, s, m, e);
    }
}


int main(){
    int n;
    cout<<"Input array size: ";
    cin>>n;
    int arr[n];
    cout<<"Input array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int s=0;
    int e=n-1;
    mergeSort(arr, s, e);
    cout<<"Sorted Array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
