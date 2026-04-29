#include<iostream>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key){
    if(s>e){
        return false;
    }
    int mid = s + (e - s)/2;

    if(arr[mid] < key){
        return binarySearch(arr,mid+1,e, key);

    }
    else if(arr[mid]>key){
        return binarySearch(arr,s,mid-1,key);

    }
    else{
        return true;
    }
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int key;
    cin >>key;

    bool ans = binarySearch(arr,0,n,key);
    if(ans)
        cout<<"found"<<endl;
    else{
        cout<<"Not found"<<endl;
    }

}