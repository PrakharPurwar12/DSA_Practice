#include<iostream>
using namespace std;

int sumOfElement(int arr[], int n){
    int sum = 0;
    if(n==0) return 0;
 
    sum = arr[0]+sumOfElement(arr+1,n-1);
    return sum;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >>arr[i];
    }
    int  sum = sumOfElement(arr,n);
    cout <<sum <<endl;
}