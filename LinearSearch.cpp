// input: Asequence of 'n' numbers A={a1,a2,...an} and a value 'V'
// output: An index  'i' such that V=A[i] or the special value 'NIL' if v does not appear in A
#include <iostream>
using namespace std;
int LinearSearch(int arr[], int n, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == k)
        {
            return i;
        }
        i++;
    }
   return -1;
}
int main()
{   int n,k;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the numbers: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched: ";
    cin>>k;
    int result = LinearSearch(arr,n,k);
    if (result==-1)
    {
        cout<<"Element not found";
    }
    else
    {
        cout<<"Element found at position: "<<result+1;
    }

}