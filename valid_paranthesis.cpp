#include <bits/stdc++.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define vll vector<long long>
using namespace std;

bool isValid(string s)
{
    char point = ' ';

    stack<char> check;
    for (auto x : s)
    {
        if (x == '(' || x == '{' || x == '[')
        {
            check.push(x);
            point = x;
            continue;
        }
        else
        {
            if (x == ')' && point == '(')
                check.pop();
            else if (x == '}' && point == '{')
                check.pop();
            else if (x == ']' && point == '[')
                check.pop();
            else
                return false;
            if (check.empty())
                point = ' ';
            else
                point = check.top();
        }
    }
    if (check.empty())
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << isValid("()") << endl;

    return 0;
}