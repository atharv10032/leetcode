#include <bits/stdc++.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define vll vector<long long>

#include <climits>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
typedef TreeNode node;

// bool bst_validate(node *root, pair<int, int> bound)
// {
//     if (!root)
//         return true;
//     int data = root->val;
//     if (data > bound.first && data < bound.second)
//     {
//         node *right = root->right;
//         node *left = root->left;
//         if (left && right)
//         {
//             pair<int, int> bound_left;
//             bound_left.first = bound.first;
//             bound_left.second = data;
//             pair<int, int> bound_right;
//             bound_right.first = data;
//             bound_right.second = bound.second;
//             if (data < root->right->val && data > root->left->val)
//                 return bst_validate(root->left, bound_left) && bst_validate(root->right, bound_right);
//         }
//         if (left)
//         {
//             pair<int, int> bound_left;
//             bound_left.first = bound.first;
//             bound_left.second = data;
//             if (data > root->left->val)
//                 return bst_validate(root->left, bound_left);
//         }
//         if (right)
//         {
//             pair<int, int> bound_right;
//             bound_right.first = data;
//             bound_right.second = bound.second;
//             if (data < root->right->val)
//                 return bst_validate(root->right, bound_right);
//         }
//         else
//             return true;
//     }
// }

bool validate(node *root, pair<long, long> bound)
{
    if (!root)
        return true;
    long data = (long)root->val;
    if (data < bound.second && data > bound.first)
    {
        pair<long, long> left, right;
        left.first = bound.first;
        left.second = (long)data;
        right.first = (long)data;
        right.second = bound.second;
        return validate(root->left, left) && validate(root->right, right);
    }
}

int main()
{
    node *root = NULL;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pair<long, long> bounds;
    bounds.first = LONG_MIN;
    bounds.second = LONG_MAX;
    return validate(root, bounds);
    return 0;
}