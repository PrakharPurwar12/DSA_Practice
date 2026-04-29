#include<iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> v;
    int size = v.size();
    cout << "Size of vector: " << size << endl;
    v.push_back(10);
    cout << "Size of vector after adding an element: " << v.size() << endl;
    cout << "capacity of vector: " << v.capacity() << endl;
    v.push_back(20);
    cout << "Size of vector after adding another element: " << v.size() << endl;
    cout << "capacity of vector after adding another element: " << v.capacity() << endl;
    v.push_back(30);
    cout << "Size of vector after adding third element: " << v.size() << endl;
    cout << "capacity of vector after adding third element: " << v.capacity() << endl;

    cout<<"element in 2nd index: "<< v.at(2) << endl;
    cout <<"element at 1st positon: " <<v.front() << endl;
    cout <<"element at last position: " <<v.back() << endl;  
}