#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int num;
    string str = "", num_str;
    cout << "Enter a number: ";
    cin >> num;
    num_str = std :: to_string(num);
    for (int i = num_str.length() - 1; i >= 0; i--){   
        str += num_str[i];}
    if (str == num_str){
        cout << "Number is a palindrome!";}
    else{
        cout << "Number is NOT a palindrome";}
    return 0;
}

