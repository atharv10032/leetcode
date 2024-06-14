#include <bits/stdc++.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define vll vector<long long>
using namespace std;

int c = 0;

void backtrack(int n, vector<vector<string>> &res, vector<string> &sol, set<int> &col, set<int> &pos_diag, set<int> &neg_diag)
{
    if (sol.size() == n)
    {
        res.push_back(sol);
        // sol.pop_back();
        return;
    }

    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        int pos_ele = sol.size() + i;
        int neg_ele = sol.size() - i;
        if (col.find(i) == col.end() && pos_diag.find(sol.size() + i + 1) == pos_diag.end() && neg_diag.find(sol.size() - i + 1) == neg_diag.end())
        {
            flag = 1;
            // cout << "Got in the if statement " << sol.size() - i << endl;
            string row_needed = "";
            for (int j = 0; j < n; j++)
                if (j == i)
                    row_needed.push_back('Q');
                else
                    row_needed.push_back('.');
            sol.push_back(row_needed);
            // int pos_ele = sol.size() + i;
            // int neg_ele = sol.size() - i;

            col.insert(i);
            pos_diag.insert(sol.size() + i);
            neg_diag.insert(sol.size() - i);
            cout << "positive diagonal " << sol.size() + i << endl;
            cout << "Negative diagonal " << sol.size() - i << endl;
            // auto iter1 = col.find(i), iter2 = pos_diag.find(pos_ele), iter3 = neg_diag.find(neg_ele);
            backtrack(n, res, sol, col, pos_diag, neg_diag);
            col.erase(i);
            pos_diag.erase(sol.size() + i);
            neg_diag.erase(sol.size() - i);
            sol.pop_back();
            // if (pos_diag.find(pos_ele) == pos_diag.end())
            cout << "First back tracking done \n";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<string>> res;
    vector<string> sol;
    set<int> col;
    set<int> pos;
    set<int> nig;
    backtrack(n, res, sol, col, pos, nig);

    for (auto r : res)
    {
        for (auto x : r)
        {
            for (auto s : x)
                cout << s << ' ';
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}