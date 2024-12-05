#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Selection sort has minimum swaps (n-1)
class SelectionSort
{
public:
    void sort(vector<int> &arr) // time complexity is O(n^2)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            size_t minIndex = i;
            for (size_t j = i + 1; j < arr.size(); j++)
            {
                if (arr.at(j) < arr.at(minIndex))
                    minIndex = j;
            }
            swap(arr.at(minIndex), arr.at(i));
        }
    }
};
// Disadvantages:
// 1. It's non adaptive, means it don't give any advantage when array is already sorted, would still takes O(n^2)
// 2. It's not stable , means it don't maintain the order of output as it was in input
int main()
{
    vector<int> arr{5, 6, 8, 8, 8, 2};
    SelectionSort sorting;
    sorting.sort(arr);
    cout << "[";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}
