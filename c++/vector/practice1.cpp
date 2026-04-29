#include<bits/stdc++.h>
using namespace std;
void printVector(vector<int>&v){
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
}
int main(){
vector<int> v1 = {1, 2, 3, 4, 5};
vector<int> v2(5, 9); // vector of size 5 initialized with 9
printVector(v1);
printVector(v2);

return 0;
}