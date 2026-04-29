#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int tar){
    int s=0, e=n-1;

    while(s<=e){
        int mid = (s+e)/2; //or s+(e-s)/2 to avoid overflow

        if(tar>arr[mid]){
            s=mid+1;
        }
        else if(tar<arr[mid]){
            e=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1; //element not found
}
int main(){
    int arr[] = {2,3,4,6,7,8,9};
    int target = 7;

    int result = binarySearch(arr, sizeof(arr)/sizeof(arr[0]), target);
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
    return 0;
}