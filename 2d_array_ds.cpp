
#include <vector>
#include <iostream>

using namespace std;

typedef vector<int> Vec;
typedef vector<Vec> Mat;


Mat operator*(const Mat &a, const Mat &b){
    int tmp;
  
    int m = a.size();
    int n = b.size();
    
    if (m!=n) exit ;

  Mat prod(m,Vec(m));

  for(int i = 0; i < m; i++) {
      for (int j=0; j < m; j++) {
        tmp = (a[i][j] * b[j][i]);
        prod[i][j] = prod[i][j]+tmp;                  
      }
  }
  return prod;
}

Vec operator*(const Mat &a, const Vec &x){
  
    int m = a.size();
    int n = x.size();
    
    if (m!=n) exit ;

  Vec prod(m);

  for(int i = 0; i < m; i++) {
      prod[i]=0;
      for (int j=0; j < n; j++) {
        //cout<<endl<< a[i][j] << " " << x[j];
        prod[i] += a[i][j] * x[j];                  
      }
  }
  return prod;
}

int vElementsSum( const Vec& x ) {
  int n, sum;
  n = x.size();
  sum = 0;

  for(int i=0;i<n;i++){
    sum += x[i];
  }

  return sum;

}

Mat create_eigen(int n) {
  int tmp_0 = 0;
  int tmp_1 = 1;
  Mat I;
  Vec vTmp;

    for (int i=0;i<n;i++){
      vTmp.clear(); 
      for (int j=0;j<n;j++) {
        if (i == j)   vTmp.push_back(tmp_1);
        else          vTmp.push_back(tmp_0);        
      }
      I.push_back(vTmp);
    }
  return I;

}

Mat create_eigen_bis(int n) {
  int tmp_0 = 0;
  int tmp_1 = 1;
  Mat I;
  Vec vTmp(n);

      for (int j= n-1;j>=0;j--) {
        vTmp[j] = tmp_1;
        I.push_back(vTmp);
        vTmp[j] = tmp_0;
      }
    
  return I;

}

ostream& operator<<(ostream& os, const Mat& A)  
{  
  int n=0;
  n = A.size();

    for (int i=0;i<n;i++) {
      os << endl;
        for (int j=0;j<n;j++) {
            os << A[i][j] << " ";        
        }
    }


    return os;  
}  

ostream& operator<<(ostream& os, const Vec& x)  
{  
  int n=0;
  n = x.size();

    for (int i=0;i<n;i++) {
      os << endl;
      os << x[i] << " ";        
      
    }


    return os;  
}  


int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }
    return 0;
}
