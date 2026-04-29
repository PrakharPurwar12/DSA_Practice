#include<iostream>
using namespace std;
void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minValueIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[minValueIndex]){
                minValueIndex =j;
            }

        }
        swap(arr[i], arr[minValueIndex]);
    }
}
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    selectionSort(arr, n);
    printArray(arr, n);
}