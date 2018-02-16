#include <cmath>
#include <vector>
#include <iostream>
#include <istream>
#include <fstream>

using namespace std;

class treeNode{
public:
    int value;
    int level;

    treeNode *left;
    treeNode *right;

    treeNode( ){
        value = 0;
        level = 0;
        left  = nullptr;
        right = nullptr;
    }

    treeNode(int v, treeNode *l = nullptr, treeNode *r = nullptr) {
        value = v;
        left  = l;
        right = r;
    }
    void swap() {
        treeNode *tmp;
        tmp = this->left;
        this->left = this->right;
        this->right = tmp;
    }
};


class Tree {
private:
    vector<treeNode*> c;
    treeNode          *root;
    int               cnt       = 0;
    int               maxlevel  = 0;


public:
    Tree(int n) {

        c.push_back( new treeNode(1));
        c[0]->level = 1;
        root = c[0];
        cnt++;

    }

    void add_node_left(int parent_idx, int value) {
        if (value == -1) return;
        c.push_back(new treeNode(value));
        cnt++;
        c[parent_idx-1]->left = c[c.size()-1];
        c[c.size()-1]->level = c[parent_idx-1]->level + 1;

        if (maxlevel < c[c.size()-1]->level) maxlevel = c[c.size()-1]->level;
    }

    void add_node_right(int parent_idx, int value) {
        if (value == -1) return;
        c.push_back(new treeNode(value));
        cnt++;
        c[parent_idx-1]->right = c[c.size()-1];
        c[c.size()-1]->level = c[parent_idx-1]->level + 1;

        if (maxlevel < c[c.size()-1]->level) maxlevel = c[c.size()-1]->level;
    }

    void print_inorder_trav(treeNode* item ) {
        if (item == nullptr ) return;

        print_inorder_trav(item->left);
        cout << item->value << " ";
        print_inorder_trav(item->right);

    }
    treeNode* get_root() {
        return root;
    }
    int get_max_level(){
        return this->maxlevel;
    }

    void swap_k_level(int k, treeNode* item) {
        if (item == nullptr ) return;

        if (item->level % k == 0) {
            item->swap();
        }

        swap_k_level( k, item->left);
        swap_k_level( k, item->right);

    }
};


int main() {
    int N, T, K;
    int l,r, a;
    Tree *tree;

    ifstream tstFile;
    tstFile.open("test_data.txt");

    if (tstFile.is_open());
    else return 0;

    tstFile >> N;
    tree = new Tree(N);
    for (int i=1;i<=N;i++) {
        tstFile >> l;
        tstFile >> r;
        tree->add_node_left(i, l);
        tree->add_node_right(i, r);

    }
    //tree->print_inorder_trav( tree->get_root() ); cout <<endl;

    tstFile >> T;

    for (int i=0;i<T;i++){

        tstFile >> K;
        tree->swap_k_level(K, tree->get_root());
        tree->print_inorder_trav(tree->get_root());
        cout << endl;
    }

    tstFile.close();

    return 0;

}
