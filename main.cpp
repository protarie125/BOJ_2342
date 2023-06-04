#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

constexpr auto Inf = int{ 987'654'321 };
constexpr auto MaxInput = int{ 100'000 };

vi input(MaxInput + 1, 0);
int len;
vector<vvi> dp;
vvi cost{
	{1,2,2,2,2},
	{0,1,3,4,3},
	{0,3,1,3,4},
	{0,4,3,1,3},
	{0,3,4,3,1}
};

int solve(int b, int l, int r) {
	if (len - 1 == b) {
		return 0;
	}

	if (0 < l * r && l == r) {
		return Inf;
	}

	if (dp[b][l][r] < 0) {
		const auto& next = input[b + 1];
		dp[b][l][r] = std::min(
			solve(b + 1, next, r) + cost[l][next],
			solve(b + 1, l, next) + cost[r][next]);
	}

	return dp[b][l][r];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	len = 1;
	do {
		cin >> input[len];
		++len;
	} while (0 < input[len - 1]);

	dp = vector<vvi>(len + 1, vvi(5, vi(5, -1)));

	auto ans = solve(0, 0, 0);
	cout << ans;

	return 0;
}