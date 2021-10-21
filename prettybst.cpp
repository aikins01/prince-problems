#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
using namespace std;

class Node
{
public:
    Node();
    Node(int val, int branch);
    ~Node();
    Node *left;
    Node *right;
    int branch;
    int value;
};

Node::Node(int val, int lvl)
{
    value = val;
    left = NULL;
    right = NULL;
    branch = lvl;
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

class Table{
    public:
        Table(const unsigned int rows, const unsigned int columns);
        Table(const unsigned int rows, const unsigned int columns, int initValue);
        int& at(const unsigned int row, const unsigned int column);
        int rows() const;
        int columns() const;
    private:
        std::vector< std::vector<int> > data;
};

Table::Table(const unsigned int rows, const unsigned int columns){
    data.resize(rows);
    for (int r=0; r<rows; r++){
        data.at(r).resize(columns);
    }
}

Table::Table(const unsigned int rows, const unsigned int columns, int initValue){
    data.resize(rows);
    for (int r=0; r<rows; r++){
        data.at(r).resize(columns, initValue);
    }
}

int Table::rows() const { return data.size(); }

int Table::columns() const { return data.at(0).size(); }

int& Table::at(const unsigned int row, const unsigned int column){
    return data.at(row).at(column);
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
    void prettyPrint();

private:
    void addKey(Node *&root, int newKey, int &branch);
    bool findKey(Node *root, int searchKey);
    vector<int> orderHelper(Node *root, vector<int> &sorted);
    Node *root;
    int getTreeHeight(Node *root);
    int countNodes(Node *root);
    vector<int> branches;
    vector<int> treeBranches(Node *root, vector<int> &branches);
};

BST::BST()
{
    root = NULL;
}
BST::~BST()
{
    delete root;
}
void BST::insertKey(int newKey) { 
    int branch;
    addKey(root, newKey, branch); 
    }
void BST::addKey(Node *&root, int newKey, int &branch)
{
    if (root == NULL)
    {
        root = new Node(newKey, branch);
        return;
    }
    else if (newKey < root->value)
    {   branch++;
        addKey(root->left, newKey, branch);
    }
    else
    {   branch++;
        addKey(root->right, newKey, branch);
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

int BST::countNodes(Node *root) {
    if(root == NULL) {
        return 0;
    }
    int count = 1;
    count += countNodes(root->left);
    count += countNodes(root->right);
    return count;
}

vector<int> BST::treeBranches(Node *root, std::vector<int> &branches) {
    if(root != NULL) {
        treeBranches(root->left,branches);
        branches.push_back(root->branch);
        treeBranches(root->right, branches);
        return branches;
    }
    else {
        return branches;
    }
}

void BST::prettyPrint() {
    if(getHeight() == 0) {
        return;
    }
    Table table(getHeight(), countNodes(root), INT_MAX);
    treeBranches(root, branches);
    for(int i = 0; i < countNodes(root); i++) {
        table.at(branches.at(i),i) = inOrder().at(i);
    }
    
    for(int i = 0; i < table.rows(); i++) {
        for(int j = 0; j < table.columns(); j++) {
            cout << "-----"; 
        }
        cout << "-" << endl << "|";
        for(int j = 0; j < table.columns(); j++) {
            if(table.at(i,j) != INT_MAX) {
                cout << setw(4) << table.at(i,j) << "|";
            }
            else {
                cout << "    " << "|";
            }
        }
        cout << endl;
    }
    for(int j = 0; j < table.columns(); j++) {
            cout << "-----"; 
    }
    cout << "-" << endl;
}

int main()
{
    int newKey;
    vector<int> numbers;
    BST bst;
    cout << "Enter the numbers to be stored: ";
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
    cout << "The numbers in sorted order: ";
    for (int i = 0; i < bst.inOrder().size(); i++)
    {
        cout << bst.inOrder().at(i) << " ";
    }
    cout << endl;
    bst.prettyPrint();
    return 0;
}
