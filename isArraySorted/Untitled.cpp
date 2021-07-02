#include<iostream>
using namespace std;

bool isArrSorted(int arr[], int size, int startIndex = 0) {
    if(size == 2)
        return arr[startIndex] <=arr[startIndex + 1] ? true : false;
    else
        if (arr[startIndex] > arr[startIndex + 1])
            return false;
        else
            return isArrSorted(arr, size - 1, startIndex + 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout<< (isArrSorted(arr, 5) ? "Sorted" : "Not Sorted");
}
