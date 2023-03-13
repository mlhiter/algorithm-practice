#include <iostream>
#include <vector>
using namespace std;

//C = A*b 大整数A和小整数b相乘
vector<int> mul(vector<int> &A, int b){
  vector<int> C;
  int t=0; //保存进位
  for(int i=0;i<A.size()||t;i++){ //遍历A中每一位，或者是存在进位时
    if(i<A.size()) t+=A[i]*b; 
    C.push_back(t%10); //t的个位数就是这一位乘积的值
    t/=10;//t的十位（或者可能还有百位）的值，进位值
  }
  return C;
  //处理前导零
  while (C.size() > 1 && C.back() == 0) {//处理前导0，比如003，我们要处理成3
    C.pop_back();
  }
}

int main() {
  string a;
  int b;
  vector<int> A;
  cin >> a >> b;
  for (int i = a.size() - 1; i >= 0; i--)
    A.push_back(a[i] - '0');
  auto C = mul(A,b);
  for(int i=C.size()-1;i>=0;i--)
    printf("%d",C[i]);
  return 0;
}
