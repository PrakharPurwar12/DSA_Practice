#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string& str,int i,int j){
    if(i>j)
         return true;

    if(str[i]!=str[j]){
        return false;
    }
    else{
        return isPalindrome(str,i+1,j-1);
    }

}

int main(){
    string name = "abbac";
    bool ans = isPalindrome(name,0,name.length()-1);
    if(ans){
        cout<<"Palindrome hai....";
    }
    else{
        cout<<"Palindrome nhi h ...";
    }
}