#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;  
}
int main()
{
    int size;
    cout << "Enter array size:";
    cin >> size;

    int arr[size];
    cout << "Enter sorted elements of array:";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter element to search:";
    cin >> target;

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result + 1 << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}