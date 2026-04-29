#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v1 = {1, 2, 3, 4, 5};
    cout<<"Size of v1: "<<v1.size()<<endl;
    cout<<"Capacity of v1: "<<v1.capacity()<<endl;
    // traversing the vector
    cout<<"Elements of v1: ";

    for(int i=0; i<v1.size(); i++){
        cout<<v1[i]<<" ";

    }
    cout<<endl;

}