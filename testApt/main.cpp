#include <iostream>

using namespace std;

string reverseString(string str_in){
    string str_out;
    int j = 0;
    for(int i = str_in.length() -1; i >= 0; i--){

        str_out[j] = str_in[i];
    cout<<str_out[j]<<endl;
        j++;
    }
    cout<<str_out<<endl;
    return str_out;
}
int main()
{
    string hello = reverseString("hello");
    cout<<"Well?"<<hello<<endl;
    return 0;
}


