#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void add_keys(vector<int>& keys, vector<int> newKeys) {
        for(int i = 0; i < newKeys.size(); i++) {
            if (!count(keys.begin(), keys.end(), newKeys[i])) {
                keys.push_back(newKeys[i]);
            }
        }
        //sort(keys.begin(), keys.end());
    }

    void print_v(vector<int> v) {
        for(int i=0; i<v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> keys = {0};

        add_keys(keys, rooms[0]);

        if (keys.size() == 1) {
            return false;
        }

        int iVisiting = keys.size()-1;
        while(true) {
            add_keys(keys, rooms[keys[iVisiting]]);
            rotate(keys.begin(), keys.begin() + iVisiting, keys.begin() + iVisiting + 1);

            iVisiting = keys.size()-1;


            if (keys[iVisiting] == 0) {
                if (rooms.size() == keys.size()) {
                    return true;
                }
                return false;
            }
        }
    }
};

int main() {
    Solution s;

    vector<vector<int>> rooms1
    {
        {1},
        {2},
        {3},
        {}
    };

    vector<vector<int>> rooms2
    {
        {1,3},
        {3,0,1},
        {2},
        {0}
    };

    vector<vector<int>> rooms3
    {
        {6,7,8},
        {5,4,9},
        {},
        {8},
        {4},
        {},
        {1,9,2,3},
        {7},
        {6,5},
        {2,3,1}  
    };

    
    cout << s.canVisitAllRooms(rooms2) << endl;
    cout << s.canVisitAllRooms(rooms1) << endl;
    cout << s.canVisitAllRooms(rooms3) << endl;

    return 0;
}