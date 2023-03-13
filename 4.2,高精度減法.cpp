#include <iostream>
#include <vector>
using namespace std;

//判断是否A>=B
bool cmp(vector<int>&A, vector<int>&B) {
	if (A.size() != B.size()) return A.size() > B.size(); //A和B位数不同，则直接比较位数
	for (int i = A.size() - 1; i >= 0; i--) //如果A和B位数相同，那么就从最高位开始比较A和B的值，如果不相同则返回比较的大小值结果
		if (A[i] != B[i])
			return A[i] > B[i];
	return true;//A和B相同，也返回true
}

//C = A - B
vector<int> sub(vector<int>&A, vector<int>&B) {
	vector<int> C;
	for (int i = 0, t = 0; i < A.size(); i++) {
		t = A[i] - t; //t用来暂时存储结果和借位数
		if (i < B.size()) t -= B[i]; //当B的位数还没减完则减去B[i],此时t暂时存储的是A和B同位相减的结果，可能是负的也可能是正的
		C.push_back((t + 10) % 10); //处理并加入这一位减的结果
		if (t < 0) t = 1; //当t<0说明借位，此时要向高位借1
		else t = 0;
	}
	while (C.size() > 1 && C.back() == 0) {//处理前导0，比如003，我们要处理成3
		C.pop_back();
	}
	return C;
}

int main() {
	string a, b;
	vector<int> A, B;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)
		A.push_back(a[i] - '0');

	for (int i = b.size() - 1; i >= 0; i--)
		B.push_back(b[i] - '0');
	if (cmp(A, B)) {//都转换为大减小
		auto C = sub(A, B);
		for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	} else {
		auto C = sub(B, A);
		printf("-");
		for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
	}
	return 0;
}
