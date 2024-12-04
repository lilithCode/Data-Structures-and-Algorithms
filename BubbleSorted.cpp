#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class BubbleSort
{
public:
    void sort(vector<int>& arr)  // time complexity is O(n^2)
    {
        bool check = false;
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            for (size_t j = 0; j < arr.size() - i-1; j++)
            {
                if (arr.at(j) > arr.at(j + 1))
                {
                    swap(arr[j], arr[j + 1]);
                    check = true;
                }
            }
            if (!check) // making this algoriithm adaptive by checking the conditon in 1st pass. In adaptive case, time complexity will be O(n)
                break;   
        }
    }
};
int main()
{
    vector<int> arr{2, 36, 1, 0, 2};
    BubbleSort sorting;
    sorting.sort(arr);
    cout << "[";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}