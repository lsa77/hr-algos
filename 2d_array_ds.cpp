
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

typedef vector<int> Vec;
typedef vector<Vec> Mat;

Mat extract_sub_matrix(const Mat &src, const tuple<int,int> &adr, const int &size) {
  
  Mat prod;
  Vec vTmp;

  for(int i=get<0>(adr); i< get<0>(adr) + size; i++){ 
    vTmp.clear(); 
    for(int j=get<1>(adr); j< get<1>(adr) + size; j++) {
      //cout << endl << i << " , " << j; 
      vTmp.push_back(src[i][j]);
    }
    prod.push_back(vTmp);
  }

  return prod;

}



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

int hourGlassValue3x3( const Mat& A){

  int sum = 0;
  for(int i=0;i<3;i++)
    for(int j=0;j<3;j++){
      if  (((i==1) &&(j==0)) ||
           ((i==1) &&(j==2)) ) ;else
          sum += A[i][j];

    }

  return sum;
}

int main(){
    Mat arr(6, Vec(6) );
    Mat sub1;
    
    tuple<int, int>   adr;
    
    int  maxHourglass  = 0;
    int  _tmpHGL       = 0;
    bool _first        = false;

    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }

    //cout <<endl<<"arr:"<< arr;

    for(int i=0; i<4;i++)
      for(int j=0;j<4;j++) {
        
        adr = make_tuple(i,j);
        
        sub1 = extract_sub_matrix(arr, adr, 3);
        _tmpHGL = hourGlassValue3x3(sub1);
        
          if ((_tmpHGL > maxHourglass) || (_first == false)) {
              _first = true;
              maxHourglass = _tmpHGL;
              //cout <<endl<<"sub1:"<< sub1;
              cout << endl <<  _tmpHGL;
          }
      }
    cout << maxHourglass;
    

    return 0;
}
