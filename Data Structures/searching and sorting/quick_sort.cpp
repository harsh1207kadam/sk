#include<iostream>
using namespace std;


int partition(int arr[],int s, int e){

    int pivot = arr[s];
    int cnt  = 0;
    for(int i=0;i<=e;i++){

        if(arr[i]< pivot){
            cnt++;
        }
    }

    int pivotposition = s + cnt;

    swap(arr[pivotposition],arr[s]);

    int i = s;
    int j = e;

    while(i<= pivotposition && j> pivotposition){

        if(arr[i]<= pivot){

            i++;
        }
        if(arr[j] > pivot){

            j--;
        }
        if(i<= pivotposition && j> pivotposition){

            swap(arr[i++],arr[j--]);
        }
    }

    return pivotposition;
}

void quicksort(int arr[],int s , int e) {

    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);

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

    quicksort(array,0,size-1);

     for(int i=0;i<size;i++){

        cout<<array[i]<<" ";
    }

    return 0;
}
