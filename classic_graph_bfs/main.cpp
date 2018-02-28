#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <list>


using namespace std;


class undirectedGraph{

protected:
    set<int> *adj;
    int V;

public:
    undirectedGraph(int N) {
        V = N;
        adj = new set<int>[N+1];
    }

    void addEdge(int p, int q ) {
        adj[p].insert(q);
        adj[q].insert(p);
    }

    void print() {
        for (int i=0;i<V;i++)
            for(int item : adj[i])
                cout << i << "-" << item << " ";
    }

    int BFS(int s, int t)
    {

        bool *visited = new bool[V];
        int cnt=0;
        int tmp;

        for(int i = 0; i < V; i++)
            visited[i] = false;

        list<int> queue;

        visited[s] = true;
        queue.push_back(s);

        set<int>::iterator i;

        while(!queue.empty())
        {
            tmp = queue.front();
            //cout << s << " ";
            queue.pop_front();

            for (i = adj[tmp].begin(); i != adj[tmp].end(); ++i)
            {
                if (*i==t)
                    return cnt;
                if (!visited[*i])
                {
                    visited[*i] = true;
                    queue.push_back(*i);
                    cnt++;
                }
            }
        }
        return cnt;
    }

};


int main(){

    int n,m, k, a;
    int p,q;
    int *_p;
    int *_q;

    undirectedGraph *gr;
    vector<int> *sets;
    int S=0;

    ifstream tstFile;
    tstFile.open("test_data.txt");
    if (tstFile.is_open());
    else return 0;

    tstFile >> n >> m;
    gr = new undirectedGraph(n);

    for (int i=0;i<n-1;i++) {
        tstFile >> p >> q;


        gr->addEdge(p, q);
    }

    sets = new vector<int>[m];
    for (int i=0;i<m;i++) {
        tstFile >> k;
        for (int j=0;j<k;j++) {
            tstFile >> a;
            sets[i].push_back(a);
        }
    }

    for (int i=0;i<m;i++) {
        S=0;
        if (sets[i].size()>1)
        for (int j = 0; j <= sets[i].size() - 2; j++) {
            for (int l = j + 1; l <= sets[i].size()-1; l++) {
                //cout << sets[i][j] << "-" << sets[i][l] << " ";
                S += (sets[i][j] * sets[i][l] * gr->BFS(sets[i][j], sets[i][l]));
            }

        }
        cout << S % 1000000007  << endl;
    }



    tstFile.close();
    return 0;
}

