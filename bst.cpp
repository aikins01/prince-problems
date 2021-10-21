#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    Node();
    Node(int val);
    ~Node();
    Node *left;
    Node *right;
    int value;
};

Node::Node(int val)
{
    value = val;
    left = NULL;
    right = NULL;
}
Node::Node()
{
    left = NULL;
    right = NULL;
}
Node::~Node()
{
    delete left;
    delete right;
}

class BST
{
public:
    BST();
    ~BST();
    void insertKey(int newKey);
    bool hasKey(int searchKey);
    vector<int> inOrder();
    int getHeight();

private:
    void addKey(Node *&root, int newKey);
    bool findKey(Node *root, int searchKey);
    vector<int> orderHelper(Node *root, vector<int> &sorted);
    Node *root;
    int getTreeHeight(Node *root);
};

BST::BST()
{
    root = NULL;
}
BST::~BST()
{
    delete root;
}
void BST::insertKey(int newKey) { addKey(root, newKey); }
void BST::addKey(Node *&root, int newKey)
{
    if (root == NULL)
    {
        root = new Node(newKey);
        return;
    }
    else if (newKey < root->value)
    {
        addKey(root->left, newKey);
    }
    else
    {
        addKey(root->right, newKey);
    }
}

bool BST::hasKey(int searchKey) { return findKey(root, searchKey); }
bool BST::findKey(Node *root, int searchKey)
{
    if (root == NULL)
    {
        return false;
    }
    else if (searchKey == root->value)
    {
        return true;
    }
    else if (searchKey < root->value)
    {
        return findKey(root->left, searchKey);
    }
    else
    {
        return findKey(root->right, searchKey);
    }
}

vector<int> BST::inOrder()
{
    vector<int> sorted;
    orderHelper(root, sorted);
    return sorted;
}
vector<int> BST::orderHelper(Node *root, vector<int> &sorted)
{
    if (root != NULL)
    {
        orderHelper(root->left, sorted);
        sorted.push_back(root->value);
        orderHelper(root->right, sorted);
        return sorted;
    }
    else
    {
        return sorted;
    }
}
int BST::getHeight() { return getTreeHeight(root); }
int BST::getTreeHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    else
    {
        return rightHeight + 1;
    }
}

int main()
{
    int newKey;
    vector<int> numbers;
    BST bst;
    cout << "Enter the numbers to be stored (end with a letter): ";
    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            break;
        }
        cin >> newKey;
        numbers.push_back(newKey);
    }
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        bst.insertKey(numbers.at(i));
    }
    cin.ignore(1000, '\n');
    cout << "Which number do you want to look up? ";
    cin >> newKey;
    cout << newKey << " is in the tree: ";
    if (bst.hasKey(newKey))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
    cout << "The numbers in sorted order: ";
    for (int i = 0; i < bst.inOrder().size(); i++)
    {
        cout << bst.inOrder().at(i) << " ";
    }
    cout << endl
         << "Height of the tree: " << bst.getHeight() << endl;
    return 0;
}
