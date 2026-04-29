#include <iostream>
using namespace std;

bool isSorted(int n, int arr[]){
    if(n==0 || n==1){
        return true;
    }
    if(arr[0]>arr[1])
        return false;
    bool ans = isSorted(n-1,arr+1);
    return ans;
}

int main(){

    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int sa = isSorted(n, arr);
    if(sa){
        cout<<"yes";
    }
    else{
        cout<<"No";
    }
}