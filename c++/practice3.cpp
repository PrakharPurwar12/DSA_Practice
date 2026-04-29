// 5
// 4 2 1 3 1

#include<iostream>
using namespace std;

int findDuplicates(int arr[], int n){
    int ans = 0;
    for( int i = 0; i<n; i++){
        ans = ans^arr[i];
    }
    for( int i = 1; i<n; i++){
        ans = ans^i;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>> arr[i];
    }

    int ans = findDuplicates(arr,n);
    cout<<ans<<endl;    
}