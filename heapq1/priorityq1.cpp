#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;


template<typename T>
class cpq : public std::priority_queue<T, std::vector<T>, std::greater<int> >{
protected:
    void swap(const int p, const int q){
        T _tmp;
        _tmp = this->c[q];
        this->c[q] = this->c[p];
        this->c[p] = _tmp;
    }

    void swim(const int p) {
        int parent;
        if (p!=0) {
            parent = (p-1)/2;
            if (this->comp(this->c[parent], this->c[p])) {
                swap(p, parent);
                swim(parent);
            }
        }
    }

public:

    bool remove(const T& value) {

        if (this->top() == value) {
            this->pop();
            return true;
        }

        int idx = lookup(value, 0);
        if (idx != -1) {
            this->c[idx] = this->c[0]-1;
            swim(idx);
            this->pop();
            return true;
        } return false;
    }


    int lookup(const T& value, const int root = 0) {
        int nRL;
        int nRR;

        if (this->c[root] == value) return root;

        nRL = 2 * root + 1;
        nRR = 2 * root + 2;

        if (nRL <= this->c.size())
            nRL = lookup(value, nRL);
        else
            return -1;

        if (nRL != -1)
            return nRL;

        if (nRR <= this->c.size())
            nRR = lookup(value, nRR);
        else
            return -1;

        if (nRR != -1)
            return nRR;

        return -1;

    }

    void print() {
        cout << endl << "Heap: ";
        for (T item : this->c)
            cout << item << " ";

    };
};


int main() {
    int Q;
    int q, v;
    cpq<int> heap;

    ifstream tstFile;
    tstFile.open("heap_tst.txt");
    int item;

    if (tstFile.is_open());
    else return 0;

        tstFile >> Q;

        for (int i = 0;i<Q;i++) {
            tstFile >> q;
            switch(q) {
                case 1:
                    tstFile >> v;

                    heap.push(v);
                    break;

                case 2:
                    tstFile >> v;
                    //cout << endl << heap.lookup(v);
                    heap.remove( v );
                    heap.print();
                    break;
                case 3:
                    //cout << heap.top();
                    heap.print();
                    break;
            }
        }

    tstFile.close();

    return 0;
}