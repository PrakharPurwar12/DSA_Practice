//Brute force Approach

#include<iostream>
using namespace std;
int main(){
    int n = 7;
    int arr[n] = {3, -4, 5, 4, -1, 7, -8};
    int maxSum = INT32_MIN;

    for(int st=0; st<n; st++){
        int currSum = 0;
        for(int end=st; end<n; end++){
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    cout<<"Maximum SubArray Sum is: "<<maxSum<<endl;
    return 0;
}