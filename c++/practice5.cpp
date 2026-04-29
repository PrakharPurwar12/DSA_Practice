#include<iostream>
#include<algorithm>
using namespace std;

void pairSum(int arr[], int n, int s){
    sort(arr, arr+n);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==s){
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int s;
    cin>>s;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    pairSum(arr,n,s);
}