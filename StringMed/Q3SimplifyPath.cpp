/*Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

The canonical path should have the following format:

The path starts with a single slash '/'.
Any two directories are separated by a single slash '/'.
The path does not end with a trailing '/'.
The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
Return the simplified canonical path.*/

#include <bits/stdc++.h>
using namespace std;
string simplifyPath(string path)
{
    stack<string> st;
    string res;
    for (int i = 0; i < path.size(); ++i)
    {
        if (path[i] == '/')
        {
            continue;
        }
        string temp;
        while (i < path.size() && path[i] != '/')
        {
            temp += path[i];
            ++i;
        }
        if (temp == ".")
        {
            continue;
        }
        else if (temp == "..")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(temp);
        }
    }
    while (!st.empty())
    {
        res = '/' + st.top() + res;
        st.pop();
    }
    if (res.size() == 0)
    {
        res = '/';
    }
    return res;
}
int main()
{
    return 0;
}