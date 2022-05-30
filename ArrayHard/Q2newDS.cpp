/*video link :  https://youtu.be/uj-rfY4sHY0
RandomizedCollection is a data structure that contains a collection of numbers, possibly duplicates (i.e., a multiset). It should support inserting and removing specific elements and also removing a random element.

Implement the RandomizedCollection class:

RandomizedCollection() Initializes the empty RandomizedCollection object.
bool insert(int val) Inserts an item val into the multiset, even if the item is already present. Returns true if the item is not present, false otherwise.
bool remove(int val) Removes an item val from the multiset if present. Returns true if the item is present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
int getRandom() Returns a random element from the current multiset of elements. The probability of each element being returned is linearly related to the number of same values the multiset contains.
You must implement the functions of the class such that each function works on average O(1) time complexity.

Note: The test cases are generated such that getRandom will only be called if there is at least one item in the RandomizedCollection.*/

#include <bits/stdc++.h>
using namespace std;
/*Here the Data Structure used is vector<int> of int and unordered_map<int, set<int>>.

    In vector<int>
        we will store the elements inserted and in unordered_map<int, set<int>>,
    key is the number in the array and in set we will store the indices of the vector where the key has been kept.Go Through logic :

    For Insertion we need to insert the element in the
    vector(array) and
        unordered_map[key].And we need to increase the size of the array.For Deletion we need to delete any occurance from the array so here we will delete the last occurance of the number but now as we have an empty place in the array we need to fill it so here we will fill it with the last inserted element of the array.And we will change the Mapping in the unordered map accordingly that is we will remove last occurance of the element to be deleted and we will delete the last occurance of the last inserted element in the array and insert the index where we have deleted the current element.For getRandom we have used the inbuilt function rand() in c++ Implementation : -

 */
class RandomizedCollection
{
public:
    unordered_map<int, set<int>> um;
    vector<int> v;
    int size;
    RandomizedCollection()
    {
        v.resize(100005, -1);
        size = 0;
    }

    bool insert(int val)
    {
        bool flag;
        if (um.count(val))
            flag = false;
        else
            flag = true;
        um[val].insert(size);
        v[size] = val;
        size++;
        return flag;
    }

    bool remove(int val)
    {
        if (um.count(val) == 0)
            return false;
        auto it = um[val].end();
        --it;
        int x = *it;
        um[val].erase(it);
        if (um[val].size() == 0)
            um.erase(val);
        if (size == 1 || x == size - 1)
        {
            size--;
            v[x] = -1;
            return true;
        }
        v[x] = v[size - 1];
        it = um[v[size - 1]].end();
        --it;
        um[v[size - 1]].erase(it);
        um[v[size - 1]].insert(x);
        v[size - 1] = -1;
        size--;
        return true;
    }

    int getRandom()
    {
        return v[rand() % size];
    }
};
int main()
{
    RandomizedCollection r;
    cout << r.insert(1);
    cout << r.insert(2);
    cout << r.insert(2);
    cout << r.getRandom();
    cout << r.remove(1);
    cout << r.getRandom();

    return 0;
}