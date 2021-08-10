#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
  The generic function filter() can be used to filter array, list, vector, etc.
*/
template <typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator
filter(InputIterator first, InputIterator last, OutputIterator pos, const ElemType &val, Comp pred)
{
    while((first =
                find_if(first, last, bind2nd(pred, val))) != last)
    {
        cout << "found value: " << *first << endl;

        *pos++ = *first++;
    }
    return pos;
}

int main()
{
    const int elem_size = 8;
    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia + elem_size);

    int ia2[elem_size];
    vector<int> ivec2;

    cout << "filtering integer array for values less than 8\n";
    filter(ia, ia + elem_size, ia2, elem_size, less<int>());

    for(size_t i = 0; i < elem_size; i++)
    {
        cout << ia2[i] << ' ';
    }

    cout << '\n';

    cout << "filtering integer vector for values greater than 8\n";
    filter(ivec.begin(), ivec.end(), back_inserter(ivec2), elem_size, greater<int>());

    for(size_t i = 0; i < elem_size; i++)
    {
        cout << ivec2[i] << ' ';
    }
    cout << '\n';
    return 0;
}
