#include<iostream>
using namespace std;

void insertionsort(int arr[],int size) {

    for(int i= 1;i<size;i++){

        int pivot = arr[i];
        int j = i-1;

        while(j>=0 && arr[j] > pivot){

            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = pivot ;
    }
}

int main(){

    int size;
    cout<<"Enter the size of array:"<<endl;
    cin>>size;

    int array[size];

    cout<<"Enter the elements of the array:"<<endl;

    for(int i=0;i<size;i++){

        cin>>array[i];
    }

    insertionsort(array,size);

     for(int i=0;i<size;i++){

        cout<<array[i]<<" ";
    }

    return 0;
}
