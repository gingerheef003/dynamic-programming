#include <chrono>
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

int main() {
	int n, ans1, ans2;

	cin >> n;
	cout << "---" << endl;

	vector<int> dp(n,-1);

	auto start = high_resolution_clock::now();
	ans1 = f1(n);
	auto stop = high_resolution_clock::now();
	cout << "Time taken for f1 = " << duration_cast<microseconds>(stop - start).count() << endl;
	cout << "f1(" << n << ") = " << ans1 << endl << endl;

	start = high_resolution_clock::now();
	ans2 = f2(n, dp);
	stop = high_resolution_clock::now();
	cout << "Time taken for f1 = " << duration_cast<microseconds>(stop - start).count() << endl;
	cout << "f2(" << n << ") = " << ans2 << endl << endl;



	return 0;
}
