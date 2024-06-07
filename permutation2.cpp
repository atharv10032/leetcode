#include <bits/stdc++.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define vll vector<long long>
using namespace std;
void backtrack(vector<int> &permute, vector<bool> &useIndex, vector<vector<int>> &res, vector<int> &nums)
{
    if (permute.size() == nums.size())
    {
        res.push_back(permute);
        return;
    }
    set<int> s;
    // map<pair<int, int>, int> used;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!useIndex[i])
        {
            if (s.find(nums[i]) != s.end())
                continue;
            useIndex[i] = 1;
            permute.push_back(nums[i]);
            s.insert(nums[i]);
            backtrack(permute, useIndex, res, nums);
            permute.pop_back();
            useIndex[i] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums = {2, 1, 1};
    vector<vector<int>> res;
    vector<int> permutation;
    vector<bool> used(nums.size(), 0);
    backtrack(permutation, used, res, nums);
    cout << "Program running...\n";
    for (auto x : res)
    {
        for (auto i : x)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}