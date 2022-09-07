//check weather the tree is identical or not
#include <bits/stdc++.h>
using namespace std;
template <typename T> // we can use any datatype weather it is int,string,char etc etc...
class TreeNode
{
public:
    T data;                         // data lenge
    vector<TreeNode<T> *> children; // data ke jo child honge unke pointer

    TreeNode(T data) // constructor of tree
    {
        this->data = data;
    }
    // we use deconstructor to delete the node of the tree
    // and by loop it also delete the children of the particular node if they have children
    ~TreeNode() // deconstructor
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};


TreeNode<int> *takeInputLevelWise()
{
    queue<TreeNode<int> *> pendingNode; // taken a queue

    cout << "enter the root data " << endl;

    int rootdata; // taken root data from user

    cin >> rootdata;

    TreeNode<int> *root = new TreeNode<int>(rootdata); // new queue me root data element insert

    pendingNode.push(root); // push the data

    while (pendingNode.size() != 0)
    { // loop run until the queue is empty

        TreeNode<int> *currentNode = pendingNode.front(); // front data store in current data

        pendingNode.pop(); // pop front data

        cout << "Enter the number of children " << currentNode->data << endl; // taken total number of child
        int n;
        cin >> n; // child le liya element me
        for (int i = 1; i <= n; i++)
        {
            // saare child insert kr diya
            int currentchilddata;

            cout << i << " th child data" << currentNode->data << endl;

            cin >> currentchilddata;

            TreeNode<int> *childNode = new TreeNode<int>(currentchilddata);

            currentNode->children.push_back(childNode); // children me childnode ko dal do

            pendingNode.push(childNode); // childnode ko queue me dal do taki woo aage process kr sake
        }
    }
    return root;
}


// check weather the tree 1 is equal to tree 2
bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1->data == root2->data && root1->children.size() == root2->children.size())
    {
        for (int i = 0; i < root1->children.size(); i++)
        {
            if (isIdentical(root1->children[i],root2->children[i]) == false)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    cout<<"enter the data for tree 1"<<endl;
    TreeNode<int> *root1 = takeInputLevelWise();
    cout<<"enter the data for tree 2"<<endl;
    TreeNode<int> *root2 = takeInputLevelWise();
    cout<<"output is"<<isIdentical(root1,root2)<<endl;
    
}
// 1 2 2 3 2 4 5 2 6 7 0 0 0 0
















