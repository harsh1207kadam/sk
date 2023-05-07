#include<iostream>
#include<array>
using namespace std;

int n;

void DispArray(int arr[], int n)              //Function to display array
{
  
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}

void QuickSort(int arr[], int l , int h){
   
   int down=l+1;
   int up= h;
   int pivot = arr[l];
   int temp;

   while(down<=up)
   {
     while(arr[down]<=pivot && down<=h)
     down++;

     while(arr[up]>pivot)
     up--;

     if(down<=up)
     {
        temp=arr[down];
        arr[down] = arr[up];
        arr[up]= temp;
        up--, down++;
     }

   }
   arr[l]=arr[up];
   arr[up]=pivot;
   if(up>l+1)
   QuickSort(arr,l,up-1);
   if(down<h)
   QuickSort(arr,down,h);


}

int main()
{
    //Array input
    cout<<"input array size"<<endl;;
    cin>>n;
    int arr[n];
    cout<<"Input array elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];

  

    //Calling the search function
    QuickSort(arr, 0 ,n-1);
    cout<<"Sorted array-> ";
   DispArray(arr,n);

}
