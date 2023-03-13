//给定n个闭区间，在数轴上选择尽可能少的点，使得每个区间内至少包含一个选出的点。
//依次输入闭区间个数n和左右边界，输出选择点的个数。

//思路：
//首先将所有区间按照右端点从小到大排序。
//初始化选择的点的数量为 0，以及最近一个被选择的点的位置为一个很小的负数（初始值为 -2e9），表示还没有选择任何一个点。
//接下来从左到右依次扫描每个区间，如果当前区间的左端点大于最近一个被选择的点的位置，则在该区间右端点选择一个点，将该点作为被选择的点，并将选择的点数量加 1。
//最后输出选择的点数量即可。
//算法时间复杂度是nlogn，主要耗时在排序上
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n;
struct Range {
	int l, r;
	bool operator < (const Range &w)const {//当一个区间的右端点小于另一个区间的右端点时，该区间被认为是“小于”另一个区间。
		return r < w.r;
	}
} range[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		range[i] = {l, r};
	}
	sort(range, range + n);//因为要排序所以对小于号进行了运算符重载
	int res = 0, ed = -2e9; //-2e9表示一个很小的负数，这里是选择一个比左端点小的值作为初始值（选一个非常小的负数）
	for (int i = 0; i < n; i++) {
		if (range[i].l > ed) {
			res++;
			ed = range[i].r;
		}

	}
	printf("%d\n", res);
	return 0;
}
