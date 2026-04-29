#include<iostream>
using namespace std;
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void swapAlternative(int arr[], int size){
    for(int i=0; i<size; i+=2){
        if(i+1 < size){
            swap(arr[i],arr[i+1]);
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    swapAlternative(arr,n);
    cout<<"Array after swapping: "<<endl;
    printArray(arr,n);

    cout<<"Program executed successfully."<<endl;
    return 0;

}