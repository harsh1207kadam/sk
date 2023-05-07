#include<iostream>
using namespace std;

// we assume first element at lowest then we find the minimum element from remaining array then swap

void selectionsort(int arr[],int size) {

    for(int i=0;i<size-1;i++){

        int minindex  = i;

        for(int j = i+1;j<size;j++){

            if(arr[j]< arr[minindex]){

                minindex = j;
            }
        }

        swap(arr[minindex],arr[i]);
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

    selectionsort(array,size);

     for(int i=0;i<size;i++){

        cout<<array[i]<<" ";
    }

    return 0;
}
