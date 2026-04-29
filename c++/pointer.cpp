#include<iostream>
#include<cstring>

using namespace std;

bool isConsonents(char text){
    if(text>='a' && text<='z'){
        if(text!='a' && text!='e' && text!='i' && text!='o' && text!='u') return true;
        return false;
    }
}
int main(){
    string text ="Hi my name is Prakhar";
    int count=0;
    for(char ch:text){
        if(isConsonents(ch)){
            count++;
        }

    }
    cout<<count;
}