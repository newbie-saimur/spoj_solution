#include <bits/stdc++.h>
using namespace std;
#define int   long long
int _;

const int INF = 1e9 + 10;
bool visited[8][8];
int dist[8][8];

vector<pair<int, int>> moves = {{1, 2}, {1, -2}, { -1, 2}, { -1, -2}, {2, 1}, {2, -1}, { -2, -1}, { -2, 1}};

int getX(string s) {
	return s[0] - 'a';
}

int getY(string s) {
	return s[1] - '1';
}

bool isValid(int x, int y) {
	return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int bfs(string source, string destination) {
	int sourceX = getX(source);
	int sourceY = getY(source);
	int destX = getX(destination);
	int destY = getY(destination);
	queue<pair<int, int>> q;
	q.emplace(sourceX, sourceY);
	visited[sourceX][sourceY] = true;
	dist[sourceX][sourceY] = 0;
	while (q.size()) {
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (auto &[x, y] : moves) {
			if (!isValid(curX + x, curY + y)) continue;
			if (!visited[curX + x][curY + y]) {
				q.emplace(curX + x, curY + y);
				visited[curX + x][curY + y] = true;
				dist[curX + x][curY + y] = dist[curX][curY] + 1;
			}
			if (dist[destX][destY] != INF) return dist[destX][destY];
		}
	}
	return dist[destX][destY];
}

void reset() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			dist[i][j] = INF;
			visited[i][j] = false;
		}
	}
}

void solve()
{
	reset();
	string source, destination; cin >> source >> destination;
	cout << bfs(source, destination) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int test = 1;
	cin >> test;
	for (_ = 1; _ <= test; _++)
	{
		solve();
	}
	return 0;
}
