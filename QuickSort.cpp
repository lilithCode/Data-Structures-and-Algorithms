#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Disadvantages:
// 1. It's non adaptive, and it's the worse case, with time complexity O(n^2)
// 2. It's not stable , means it don't maintain the order of output as it was in input
class QuickSort
{
public:
    size_t partition(vector<int> &arr, size_t low, size_t high)
    {
        int pivot{arr.at(high)};
        size_t i{low - 1};
        for (size_t j = low; j < high; j++)
        {
            if (arr.at(j) <= pivot)
            {
                i++;
                swap(arr.at(i), arr.at(j));
            }
        }
        swap(arr.at(high), arr.at(i + 1));
        return i + 1;
    }
    void sort(vector<int> &arr, size_t low, size_t high) // time complexity is O(nlog n)
    {
        if (low < high)
        {
            size_t partitionIndex = partition(arr, low, high);
            sort(arr, low, partitionIndex - 1);  // sorting left side
            sort(arr, partitionIndex + 1, high); // sorting right side
        }
    }
};
int main()
{
    vector<int> arr{5, 0, 9, 4, 8, 4, 3};
    QuickSort sorting;
    sorting.sort(arr, 0, arr.size() - 1);
    cout << "[";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}
