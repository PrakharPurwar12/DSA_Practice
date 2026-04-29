#include<iostream>
using namespace std;

void findTriplates(int arr[], int n, int k){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int l=j+1; l<n; l++){
                if(arr[i]+arr[j]+arr[l]==k){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[l]<<endl;
                    return;
                }
                else{
                    cout<<"No such triplet found"<<endl;
                    return;
                }
            }
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
    int k;
    cin>>k;
    findTriplates(arr, n, k);
    return 0;
}