#include <iostream>
#include <vector>

using namespace std;

void insertDoubleValue(vector<int> &iv, int some_val)
{
    auto iter = iv.begin(), mid = iv.begin() + iv.size()/2;
    while (iter != mid) {
        if (*iter == some_val) {
            iter = iv.insert(iter, 2 * some_val);
            ++iter;
            mid = iv.begin() + iv.size()/2;
        }
        ++iter;
    }
}

void print(const vector<int> &iv)
{
    for (auto i : iv)
        cout << i << " ";
    cout << endl;
}

int main()
{
    vector<int> iv = {1, 2, 1, 3, 1, 4, 1, 5};
    insertDoubleValue(iv, 1);
    print(iv);
}
