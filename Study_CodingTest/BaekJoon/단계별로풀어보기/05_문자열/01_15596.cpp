//01. 15596번 문제 (정수 N개의 합)

#include <vector>
long long sum(std::vector<int>& a) {
	long long ans = 0;
	for (int i : a)
		ans += i;
	return ans;
}