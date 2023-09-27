#include <iostream>
using namespace std;
void swap(int arr[],int j,int k){
    int temp = arr[j];
    arr[j]=arr[k];
    arr[k]=temp;
}
void BubbleSort(int arr[], int n)
{
    bool swapped;
    for (int i = 0; i<n; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr,j,j+1);
                swapped=true;
            }
        }
        if(swapped==false){
            break;
        }
    }
}
void displayArray(int arr[],int n){
    cout<<"Sorted Array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    BubbleSort(arr,n);
    displayArray(arr,n);
    
}