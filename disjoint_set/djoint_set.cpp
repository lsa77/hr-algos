//
// Created by lsa on 11.02.18.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

#include <fstream>
#include <set>
using namespace std;

int lookupSet( vector<set<int>> &sets, vector<int> &ref , const int &v){
    set<int> *s;
    int      *item;

    if (ref[v] != -1)
        return ref[v];

        s    = new set<int>;
        item = new int(v);
        s->insert(*item);
        sets.push_back(*s);
        ref[v] = sets.size()-1;

        return ref[v];


}

int fMax( vector<set<int>> &sets){
    int _tmp=0;

    for (set<int> st:sets)
        if (st.size() > _tmp)
            _tmp = st.size();
    return _tmp;
}

int fMin( vector<set<int>> &sets){
    int _tmp=15000;

    for (set<int> st:sets)
        if ((st.size() < _tmp)&&st.size()!=0)
            _tmp = st.size();
    return _tmp;
}

int main() {
    int n;
    int sp, sq;
    int src, trg;

    vector<set<int>>  sets;


    ifstream tstFile;
    tstFile.open("heap_tst.txt");

    if (tstFile.is_open());
    else return 0;

    tstFile >> n;

    vector<int>ref(2*n+1, -1);

    // init

    for (int i=0;i<n;i++) {
        int p, q;
        tstFile >> p >> q;

        sp = lookupSet(sets, ref, p);
        sq = lookupSet(sets, ref, q);

        if (sp != sq) {
            if(sets[sp].size()>=sets[sq].size()) {
                trg = sp;
                src = sq;
            } else{
                trg = sq;
                src = sp;
            }

            for(int i:sets[src]) {


                sets[trg].insert(i);
                ref[i] = trg;
            }
           sets[src].clear();

        }

    }
    // find min and max
    cout << fMin(sets) << " " << fMax(sets);

    tstFile.close();
    return 0;
}