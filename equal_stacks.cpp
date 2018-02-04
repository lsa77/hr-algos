#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

void cinLineToVector(vector<int> &vLine, int &sum,  const char mode = 'S') { //S - stack V - vector
    string line;
    int nbr;
    
    getline(cin, line);
    stringstream iss(line);
    
    while(iss>>nbr) { 
        if      (mode == 'S') { vLine.insert(vLine.begin(), nbr); sum += nbr; }
        else if (mode == 'V') { vLine.push_back(nbr);             sum += nbr; }
    }
    //return vLine;
}


int main() {
    int     *line;
    int     sum[] = {0,0,0};
    int     **lines;
    int     sizes[3];
    
    
    
    int item;
    int idx;
    
    lines = new int*[3];
    
    //cinLineToVector(sizes, item, 'V');
    cin >> sizes[0];
    cin >> sizes[1];
    cin >> sizes[2];
    
    //cout << sizes[0] << sizes[1] << sizes[2];
    
    
    for(int i=0;i<3;i++) {
        line = new int[sizes[i]];
        idx = sizes[i]-1;
        
        //cinLineToVector(*line, sum[i]);
        for (int j=0;j<sizes[i];j++) {
            cin >> item;
            
            line[idx--]=item;
            sum[i] += item;
        }
        lines[i]=line;

        //sum[i] = sumElements(line);
    }
    
    while(true){
        
        if (sum[0]>sum[1]){
            sum[0]  -= lines[0][sizes[0]-1];               
            sizes[0]--;
        } else if (sum[1]>sum[2]){
            sum[1]  -= lines[1][sizes[1]-1];               
            sizes[1]--;
        } else if (sum[2]>sum[0]){
            sum[2]  -= lines[2][sizes[2]-1];               
            sizes[2]--;
        } else{
            break;
        }

        
    }
    
    cout <<sum[0];
    return 0;
}