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
int main()
{
    int arr[5]={5,4,8,2,4};
    BubbleSort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<",";
    }
    
}