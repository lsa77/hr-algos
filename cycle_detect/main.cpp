#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;


int main(){

    int N, S, P, Q, n;
    int a, t, h;
    unsigned int m = 1 << 31;


    ifstream tstFile;
    tstFile.open("test_data.txt");
    if (tstFile.is_open());
    else return 0;

    tstFile >> N >> S >> P >> Q;

    n = N;
    a=S%m;
    t = (a * P + Q) % m;
    h = (t * P + Q) % m;


    while((t!=h) && n>0) {
        t = (t * P + Q) % m;
        h = (h * P + Q) % m;
        h = (h * P + Q) % m;
        n--;

    }
    if (n==0){
        cout << N;
        return 0;
    }


    int mu = 0;
    t = a;

    while (t!=h) {
        t = (t * P + Q) % m;
        h = (h * P + Q) % m;
        mu++;
    }

    int lam = 1;
    h = (t * P + Q) % m;
    while (t != h) {
        h = (h * P + Q) % m;
        lam++;
    }

    cout << mu + lam;

    //for(long it: unq)
    //cout << it << " ";
    tstFile.close();
    return 0;
}

