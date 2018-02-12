#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;



int main() {
    int N, Q;
    string item;

    multimap<string,size_t>    Nset;
    hash<string>            hasher;



    ifstream tstFile;
    tstFile.open("test_data.txt");

    if (tstFile.is_open());
    else return 0;

    tstFile >> N;

    for (int i=0;i<N;i++) {
        tstFile >> item;

        Nset.insert(pair<string, size_t>(item, hasher(item)));

    }
    tstFile >> Q;

    for (int i=0;i<Q;i++){
        tstFile >> item;
        cout << Nset.count(item) << endl;
    }
    tstFile.close();


    return 0;

}
