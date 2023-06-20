#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string>v1(n);
	vector<string>result;
	for (int i = 0; i < n; i++) cin >> v1[i];

	sort(v1.begin(), v1.end());

	string mm;
	int count = 0;
	for (int i = 0; i < m; i++) {
		cin >> mm;
		if (binary_search(v1.begin(), v1.end(), mm)) count++;
	}

	cout << count << '\n';
}
