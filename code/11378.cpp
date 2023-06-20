#include <queue>
#include <iostream>
#include <vector>

using namespace std;

const int S = 0, E = 2001;
int capacity[2022][2022], flow[2022][2022], d[2022];
vector<int> v[2022];

void initialize(int N, int M, int K)
{
	int i;

	for (i = 1; i <= N; i++) {
		v[S].push_back(i), v[i].push_back(S);
		capacity[S][i] = 1;
		v[E + 1].push_back(i), v[i].push_back(E + 1);
		capacity[E + 1][i] = K;
	}
	v[S].push_back(E + 1), v[E + 1].push_back(S);
	capacity[S][E + 1] = K;

	// from job to dummy(end)
	// dummy(end) : 2001
	for (i = 1001; i <= 1000 + M; i++) {
		v[i].push_back(E), v[E].push_back(i);
		capacity[i][E] = 1;
	}
}

void fill_d(int d[], int size)
{
	int i;
	for (i = 0; i <= size; i++)
		d[i] = -1;
}

int maxFlow(int start, int end)
{
	int i, cur, max_flow, min_flow;

	max_flow = 0;
	while (1) {
		fill_d(d, end + 1);
		queue<int> Q;
		Q.push(start);

		while (!Q.empty()) {
			cur = Q.front(), Q.pop();
			for (int next : v[cur]) {
				if (d[next] == -1 && capacity[cur][next] - flow[cur][next] > 0) {
					Q.push(next), d[next] = cur;
					if (next == end)
						break;
				}
			}
		}

		if (d[end] == -1) return max_flow;

		min_flow = 1000000000;
		for (i = end; i != start; i = d[i]) {
			min_flow = min(min_flow, capacity[d[i]][i] - flow[d[i]][i]);
		}

		max_flow += min_flow;
		for (i = end; i != start; i = d[i]) {
			flow[d[i]][i] += min_flow;
			flow[i][d[i]] -= min_flow;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, M, K, job_cnt, job;
	cin >> N >> M >> K;
	initialize(N, M, K);
	for (int i = 1; i <= N; i++) {
		cin >> job_cnt;
		for (int j = 0; j < job_cnt; j++) {
			cin >> job;
			v[i].push_back(1000 + job), v[1000 + job].push_back(i);
			capacity[i][1000 + job] = 1;
		}
	}
	cout << maxFlow(S, E);

	return 0;
}
