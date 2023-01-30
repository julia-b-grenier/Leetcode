#include <string>
#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    string str = "";
    
    bool canContine = true;
    int index = 0;
    while (canContine && index < strs[0].size()) {
        char c = strs[0][index];
        for (int i=0; i<strs.size(); i++) {
            if (index < strs[i].size()) {
                if (strs[i][index] != c) {
                    canContine = false;
                    break;
                }
                else if (i == strs.size()-1)
                    str += c;
            }
            else {
                canContine = false;
                break;
            }
        }
        index++;
    }

    return str;
}

int main() {
    vector<string> s = {"dog","racecar","car"};
    cout << longestCommonPrefix(s);
}