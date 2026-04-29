/* 
Binary Search: -> works on sorted arrays or monotonic sequences
-> O(log n) time complexity
steps:
1. Find the middle element of the array.
2. If the middle element is equal to the target, return the index.
3. If the middle element is less than the target, search in the right half of the array.
4. If the middle element is greater than the target, search in the left half of the array.
5. Repeat steps 1-4 until the target is found or the search space is empty.
-> Binary search can be implemented using recursion or iteration.
*/

#include<iostream>
using namespace std;

void binarySearch(int arr[], int n, int k){
    int start = 0, end = n-1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] == k ){
            cout << "Element found at index: " << mid << endl;
            return;
        }
        else if(arr[mid] < k){
            start = mid + 1;
        }
        else if(arr[mid] > k){
            end = mid - 1;
        }
        else{
            cout << "Element not found" << endl;
            return;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    binarySearch(arr, n, k);
    return 0;
}