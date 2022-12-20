#include <vector>
#include <iostream>
#include <algorithm>

auto print = [](auto const& remark, auto const& v) {
    std::cout << remark;
    for (int n: v)
        std::cout << n << ' ';
    std::cout << '\n';
};

int main()
{
    std::vector<int> v{1,0,2,3};
 
    // simple rotation to the right
    std::rotate(v.begin(), v.begin() + 2, v.begin() + 3);
 
    print("simple rotate right:\t", v);
}