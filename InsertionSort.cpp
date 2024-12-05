#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class InsertionSort
{
public:
    void sort(vector<int> &arr) // time complexity is O(n^2)
    {
        for (size_t i = 1; i < arr.size(); i++)
        {
            int key = arr.at(i);
            int j = i - 1;
            while (j >= 0 && arr.at(j) > key)
            {
                arr.at(j + 1) = arr.at(j);
                j--;
            }
            arr.at(j + 1) = key;
        }
    }
};
int main()
{
    vector<int> arr{5, 8, 2};
    InsertionSort sorting;
    sorting.sort(arr);
    cout << "[";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}
