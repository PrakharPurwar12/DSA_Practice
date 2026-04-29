#include<iostream>
using namespace std;

void intersection(int arr1[], int arr2[], int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
            }
        }
    }
}
int main(){
    int n;
    int m;
     cin>>n;
     cin>>m;
     int arr1[n];
     int arr2[m];

     for(int i=0; i<n; i++){
        cin>>arr1[i];

     }
     for(int i=0; i<m; i++){
        cin>>arr2[i];
     }
    intersection(arr1,arr2,n,m);
     

}