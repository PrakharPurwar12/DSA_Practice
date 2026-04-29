#include<iostream>
using namespace std;

void reverseCharArray(char arr[], int n){
    int s = 0;
    int e = n-1;
    while(s < e){
        swap(arr[s++], arr[e--]);
    }
}

void printArray(char arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }
    cout << endl;
}

int main(){
    char arr[1000];
    cin >> arr;
    int n = 0;
    while(arr[n] != '\0') n++; // Calculate length

    reverseCharArray(arr, n);
    printArray(arr, n);

    return 0;
}