#include <iostream>
#include <vector>
using namespace std;
class CountSort
{
public:
    void sort(vector<int> &arr) //time complexity is O(m+n)
    {
        int max = arr.at(0);
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (arr.at(i) > max)

                max = arr.at(i);
        }
        vector<int> another(max + 1);
        for (size_t i = 0; i < arr.size(); i++)
        {
            another.at(arr.at(i)) = another.at(arr.at(i)) + 1;
        }
        size_t j{0};
        int value;
        for (size_t i = 0; i < another.size(); i++)
        {

            value = another.at(i);
            while (value)
            {
                arr.at(j) = i;
                j++;
                value--;
            }
        }
    }
};
int main()
{
    vector<int> arr{4, 2, 7, 0};
    CountSort sorting;
    sorting.sort(arr);
    cout << "[";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}
