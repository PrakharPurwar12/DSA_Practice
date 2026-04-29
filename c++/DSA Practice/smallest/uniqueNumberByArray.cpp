#include<iostream>
using namespace std;
int uniqueValue(int arr[], int n){
    int unique=0;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--){
            if(arr[i]==arr[j] && i!=j){
                break;
            }
            else{
                unique=arr[i];
                return 0;
            }
        }
    }
    return unique;
}
int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<" Unique Elements are: "<< uniqueValue(arr,n)<<endl;
    return 0;

}