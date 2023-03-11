#include <iostream>
#include <vector>
using namespace std;
const int N = 1e6+10;

vector<int> add(vector<int> &A,vector<int>&B){
  vector<int> C;
  int t=0;
  for(int i=0;i<A.size()||i<B.size();i++){
    if(i<A.size()) t+=A[i];
    if(i<B.size()) t+=B[i];
    C.push_back(t%10);
    t/=10;
    if(t) C.push_back(1);
    return C;
  }
}

int main(){
  string a,b;
  vector<int> A,B;
  cin>>a>>b;
  //读入的时候是个位先读入A[0]
  for(int i=a.size()-1;i>=0;i--) //size()方法是vector的方法类
    A.push_back(a[i]-'0'); //a[i]是字符型，通过与'0'的ascii码（48）相减得到数字型
  
  for(int i=b.size()-1;i>=0;i--)
    B.push_back(b[i]-'0'); //a[i]是字符型，通过与'0'的ascii码（48）相减得到数字型
  auto C = add(A,B); //auto就是自动判断返回值，相当于vector<int>，这里就是为了少些一点
  for(int i=C.size()-1;i>=0;i--)
    printf("%d",C[i]);
  return 0;
}
