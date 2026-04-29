#include<iostream>
using namespace std;

void print(int arr[], int n){
    cout<< "size: "<<n << endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
bool search(int arr[], int n, int k){
    print(arr,n);
    if(n==0) return false;
    if(arr[0] == k)
        return true;
    else
        return search(arr+1,n-1,k);



}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k;
    cin >>k;
    bool ans = search(arr,n,k);
    if(ans){
        cout<<"Found"<<endl;
    }
    else{
        cout <<"Not Found"<<endl;
    }
}