#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BSTree {
public:
    BSTree() : root(nullptr) {}
    BSTree(TreeNode* rootNode) : root(rootNode) {}

    void Print();
    void Insert(int val);
    bool Contains(int val);
    void Remove(int val);
private:
    TreeNode* root;
    string SubTreeAsString(TreeNode* node);
    void Insert(int val, TreeNode*& node);
    bool Contains(int val, TreeNode*& node);
    void Remove(int val, TreeNode*& node);
    TreeNode*& FindMin(TreeNode*& node);
};

// 1:
void BSTree::Print()
{
    if (this->root == nullptr) {
        cout << "{}" << endl;
    }
    else {
        cout << this->SubTreeAsString(this->root) << endl;
    }
}

string BSTree::SubTreeAsString(TreeNode* node)
{
    string leftStr = (node->left == nullptr) ? "{}" : SubTreeAsString(node->left);
    string rightStr = (node->right == nullptr) ? "{}" : SubTreeAsString(node->right);
    string result = "{" + to_string(node->data) + ", " + leftStr + ", " + rightStr + "}";
    return result;
}

// 2:
void BSTree::Insert(int val)
{
    if (root == nullptr) {
        this->root = new TreeNode(val);
    }
    else {
        Insert(val, this->root);
    }
}

void BSTree::Insert(int val, TreeNode*& node)
{
    if (node == nullptr) {
        node = new TreeNode(val);
    }
    else {
        if (val < node->data) {
            this->Insert(val, node->left);
        }
        else if (val > node->data) {
            this->Insert(val, node->right);
        }
        else {
            cout << "Значение уже существует!" << endl;
        }
    }
}

// 3:
bool BSTree::Contains(int val) 
{
    return Contains(val, this->root);
}

bool BSTree::Contains(int val, TreeNode*& node)
{
    if (node == nullptr)
        return false;
    else if (node->data == val)
        return true;
    else if (val < node->data)
        return this->Contains(val, node->left);
    else
        return this->Contains(val, node->right);
}

// 4:
void BSTree::Remove(int val)
{
    this->Remove(val, this->root);
}

void BSTree::Remove(int val, TreeNode*& node)
{
    if (node == nullptr)
        cout << "Такого значения нет!" << endl;
    else if (val == node->data)
    {
        TreeNode* trash = nullptr;
        if (node->left == nullptr && node->right == nullptr) {
            trash = node;
            node = nullptr;
        }
        else if (node->left != nullptr && node->right == nullptr) {
            trash = node;
            node = node->left;
        }
        else if (node->left == nullptr && node->right != nullptr) {
            trash = node;
            node = node->right;
        }
        else {
            TreeNode*& minNode = this->FindMin(node->right);
            node->data = minNode->data;
            this->Remove(minNode->data, minNode);
        }

        if (trash != nullptr) delete trash;
    }
    else if (val < node->data)
        this->Remove(val, node->left);
    else 
        this->Remove(val, node->right);
}

TreeNode*& BSTree::FindMin(TreeNode*& node)
{
    if (node == nullptr)
        throw "Min value not found";
    else if (node->left == nullptr)
        return node;
    else
        return this->FindMin(node->left);
}


int main()
{
    
}
