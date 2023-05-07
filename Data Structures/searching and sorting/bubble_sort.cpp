#include<iostream>
using namespace std;

// logic is we compare element with the next element and if it is greater than next element we swap both the elements.
// remember (j< size-i-1);

void bubblesort(int arr[],int size) {

    for(int i= 0;i<size;i++){

        for(int j = 0; j < size-i-1;j++){

            if(arr[j]> arr[j+1]){

                swap(arr[j],arr[j+1]);
            }
        }
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

    bubblesort(array,size);

     for(int i=0;i<size;i++){

        cout<<array[i]<<" ";
    }

    return 0;
}
