#include "paradox.h"
#include <iostream>
#include <vector>

using namespace std::chrono;
using namespace std;

int f1(int n) {
	if (n <= 1) return n;
	return f1(n-1) + f1(n-2);
}

int f2(int n, vector<int> &dp) {
	if (n <= 1) return n;
	if (dp[n] != -1) return dp[n];
	return dp[n] = f2(n-1, dp) + f2(n-2, dp);
}

int f3(int n) {
	int curr, prev0 = 0, prev1 = 1;
	for(int i = 2; i <= n; i++) {
		curr = prev1 + prev0;
		prev0 = prev1;
		prev1 = curr;
	}
	return curr;
}

int main() {
	int n, ans1, ans2;

	cin >> n;
	cout << "---" << endl;

	vector<int> dp(n+1,-1);

	ans1 = f1(n);
	cout << "f1(" << n << ") = " << ans1 << endl << endl;
	
	ans2 = f2(n,dp);
	cout << "f2(" << n << ") = " << ans2 << endl << endl;

	ans2 = f3(n);
	cout << "f3(" << n << ") = " << ans2 << endl << endl;

	return 0;
}
