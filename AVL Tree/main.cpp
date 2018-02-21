#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;

class binaryTree{
protected:
    node* root;

    node* __newNode (int value)
    {
        node* temp = new node;

        temp->val   = value;
        temp->left  = nullptr;
        temp->right = nullptr;
        temp->ht    = 0;

        return temp;
    }

    int max(int a, int b)
    {
        return (a > b)? a : b;
    }

    node* __addNode( node *root, int val) {
        int balance;

        if (root == nullptr) {
            root = __newNode(val);
            return root;
        }

        if (val < root->val)
            root->left  = __addNode(root->left, val);
        else if ( val > root->val)
            root->right = __addNode(root->right, val);
        else
            return root;

        root->ht = max(__getHeight(root->left), __getHeight(root->right))+1;

        balance = __getBalanceFactor(root);

        //Left Left
        if (balance > 1 && val < root->left->val)
            return rightRotate(root);

        // Right Right
        if (balance < -1 && val > root->right->val)
            return leftRotate(root);

        // Left Right
        if (balance > 1 && val > root->left->val)
        {
            root->left =  leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left
        if (balance < -1 && val < root->right->val)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    node* rightRotate(node *y)
    {
        node *x  = y->left;
        node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->ht = max(__getHeight(y->left), __getHeight(y->right))+1;
        x->ht = max(__getHeight(x->left), __getHeight(x->right))+1;

        return x;
    }

    node* leftRotate(node *x)
    {
        node *y  = x->right;
        node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->ht = max(__getHeight(x->left), __getHeight(x->right))+1;
        y->ht = max(__getHeight(y->left), __getHeight(y->right))+1;

        return y;
    }

    int __getHeight(node *root) {
        if(root == nullptr) {
            return -1;
        }

        return root->ht;
    }

    int __getBalanceFactor(node* root) {

        if (root == nullptr)
            return 0;

        return __getHeight(root->left) - __getHeight(root->right) ;
    }

    void __printInOrder (node* node)
    {
        if (node == NULL)
            return ;
        __printInOrder(node->left);
        cout << node->val << "(BF=" <<__getBalanceFactor(node) << ") ";
        __printInOrder(node->right);
    }

public:
    binaryTree (node* extRoot) {
        root = extRoot;
    }
    binaryTree (vector<int> initVect)
    {
        int id = 0;
        root = __newNode( initVect[id] );


        for (int i = 1;i<initVect.size();i++)
            __addNode(root, initVect[i]);
    }

    void print(){
        __printInOrder(root);
    };

    void addNode(int value) {
        root = __addNode(root, value);
    }
};

int main(){

    int N;
    int val;
    string output;

    vector<int> init;
    binaryTree *bst;

    ifstream tstFile;
    tstFile.open("test_data.txt");
    if (tstFile.is_open());
    else return 0;

    tstFile >> N;
    for (int i=0;i<N;i++) {
        tstFile >> val;
        init.push_back(val);
    }

    tstFile >> val;

    bst = new binaryTree(init);
    bst->addNode( val);
    bst->print();

    tstFile.close();
    return 0;
}

