#include<iostream>
using namespace std;
#include<string.h>
string reverseWords(string s) {
    int sizeString = s.length();
    int i = sizeString - 1;
    int j = sizeString - 1;
    for (int current = sizeString - 1; current >= 0; current--) {
        if (s[current] == ' ') {
            i = current + 1;
        } else if (current == 0) {
            i = 0;
        }
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        j = current - 1;
    }
    return s;
}
int main(){
    string s = "hello world";
    cout<<reverseWords(s);
}
