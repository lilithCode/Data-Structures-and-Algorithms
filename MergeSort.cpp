#include <iostream>
#include <vector>
using namespace std;
class MergeSort
{
public:
    void merge(vector<int> &arr, size_t low, size_t mid, size_t high)
    {
        size_t i{low};
        size_t j{mid + 1};
        size_t size1{mid};
        size_t size2{high};
        vector<int> ans;   //new vector which size hasn't yet declared
        while (i <= size1 && j <= size2)
        {
            if (arr.at(i) <= arr.at(j))
            {
                ans.push_back(arr.at(i));  //add elements to new vector
                i++;
            }
            else
            {
                ans.push_back(arr.at(j));
                j++;
            }
        }
        while (i <= size1)  //copying the rest of the elements from left side
        {
            ans.push_back(arr.at(i));
            i++;
        }
        while (j <= size2)  //copying the rest of the elements from right side
        {
            ans.push_back(arr.at(j));
            j++;
        }

        //copying all the elements of new vector to original vector
        size_t b{0}; 
        for (size_t a = low; a <= high; a++)
        {
            arr.at(a) = ans.at(b);
            b++;
        }
    }
    void sort(vector<int> &arr, size_t low, size_t high) // time complexity is O(n log n)
    {
        if (low < high)
        {
            int mid = (low + high) / 2;
            sort(arr, low, mid);  //dividing left side
            sort(arr, mid + 1, high);  //dividing right side
            merge(arr, low, mid, high); //merging both sides
        }
    }
};
int main()
{
    vector<int> arr{4, 2, 8,9,32,7, 0};
    MergeSort sorting;
    sorting.sort(arr, 0, arr.size() - 1);
    cout << "[";
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << "]" << endl;

    return 0;
}
