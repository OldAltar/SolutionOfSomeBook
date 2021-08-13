#include <iostream>
#include <vector>
#include <algorithm>
#include "LessThan.h"

using namespace std;

int count_less_than(const vector<int>&, int);
void print_less_than(const vector<int>&, int, ostream&);

int main()
{
    int ia[16] = {17, 12,44,9,18,45,6,14,23,67,9,0,27,55,8,16};
    vector<int> vec(ia, ia+16);
    int comp_val = 20;

    cout << "Number of elements less than " << comp_val << " are " << count_less_than(vec, comp_val) << endl;
    print_less_than(vec, comp_val, cout);

    return 0;
}

int count_less_than(const vector<int>& vec, int comp)
{
    LessThan lt(comp);

    int count = 0;
    for(int ix = 0; ix < vec.size(); ++ix)
    {
        if(lt(vec[ix]))
        {
            ++count;
        }
    }

    return count;
}

void print_less_than(const vector<int>& vec, int comp, ostream& os = cout)
{
    LessThan lt(comp);
//    注意对于const vector要用const_iterator
//    vector<int>::iterator iter = vec.begin();
//    vector<int>::iterator it_end = vec.end();
    vector<int>::const_iterator iter = vec.begin();
    vector<int>::const_iterator it_end = vec.end();

    os << "elements less than " << comp << endl;
    while((iter = find_if(iter, it_end, lt)) != it_end)
    {
        os << *iter << ' ';
        ++iter;
    }

}
