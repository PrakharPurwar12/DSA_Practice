#include<iostream>
using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void SortedOne(int arr[], int n){
    int left = 0, right = n-1;
    while (left < right){
        while(arr[left] == 0 && left < right){
            left++;
        }
        while(arr[right] == 1 && left < right){
            right--;
        }
        if(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
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

    SortedOne(arr, n);
    printArray(arr, n);
}