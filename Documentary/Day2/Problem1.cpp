#include <iostream>
#include <vector>
using namespace std;

// Convert a Sorted Array to a balanced Binary Search Tree 

// Structure of Node
struct Node {
    Node* left = NULL;
    Node* right = NULL;
    int val;

    Node(int value) {
        val = value;
    }
};

typedef struct Node Node;

Node *BTree(vector<int> arr, int l, int r) {
    if (l > r)
        return nullptr;

    // find middle
    int mid = (l+r)/2;

    // make root node
    Node *root = new Node(arr[mid]);

    root->left = BTree(arr, l, mid-1);
    root->right = BTree(arr, mid+1, r);
    return root;
}

void printBTree(Node* root) {
    // preorder of the Binary Tree
    if (root == NULL)
        return;

    printBTree(root->left);
    cout << root->val << " ";
    printBTree(root->right);
}

int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node* tree = BTree(arr, 0, arr.size()-1);

    printBTree(tree);

    return 0;
}
