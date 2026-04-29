#include<iostream>
#include<climits>
using namespace std;
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int smallest = INT32_MAX;
    int largest = INT32_MIN;

     for(int i=0; i<n; i++){
        if(arr[i]<smallest){
            smallest = arr[i];

        }
        if(arr[i]>largest){
            largest  = arr[i];
        }
     }
     cout<<"Smallest: "<<smallest<<endl;
     cout<<"Largest: "<<largest<<endl;
     return 0;
     
}