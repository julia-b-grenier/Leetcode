#include <iostream>
#include <vector>

using namespace std;


void reverseString(vector<char>& s) {
    for (int i=0; i < s.size()/2; i++) {
        int temp = s[i];
        s[i] = s[s.size()-i-1];
        s[s.size()-1-i] = temp;
    }
}


int main() {
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    for (int i=0; i<s.size(); i++) {
        cout << s[i];
    }
    cout << endl;
}

