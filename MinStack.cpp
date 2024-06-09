#include <bits/stdc++.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define vll vector<long long>
#include <climits>
using namespace std;
class MinStack
{
public:
    stack<int> s;
    stack<int> min;
    MinStack()
    {
        min.push(INT_MAX);
    }

    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);
            min.push(val);
            return;
        }

        if (min.top() >= val)
        {
            min.push(val);
        }
        s.push(val);
    }

    void pop()
    {
        if (s.top() == min.top())
        {
            s.pop();
            min.pop();
            return;
        }
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

        return 0;
}