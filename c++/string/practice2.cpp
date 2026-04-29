#include<iostream>
using namespace std;

void checkPalindrome(char arr[], int n){
    int s = 0;
    int e = n-1;
    while(s<e){
        if(arr[s] != arr[e]){
            cout << "Not a Palindrome" << endl;
            return;
        }
        s++;
        e--;
    }
    cout << "Yes, it is a palindrome." << endl;
}

int main(){
    char arr[1000];
    cin >> arr;
    int n = 0;
    while(arr[n] != '\0') 
        n++; // Calculate length
    checkPalindrome(arr, n);
}