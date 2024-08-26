#include	<vector>

using namespace std;

vector<pair<int, int>>	adj[20005];			// {비용, 간선 번호}
const int				INF = 0x3f3f3f3f;
bool					fix[20005];			// 거리가 확정된 곳인지
int						distance[20005];	// 시작점으로부터 거리
int						V = 10;				// 정점 개수

// O(V^2 + E) -> 느림
void	dijkstra_naive(int start)
{
	fill(distance, d + V + 1, INF);	// 최단 거리 테이블 초기화
	distance[start] = 0;
	whlie (true)
	{
		int	idx = -1;

		for (int i = 1; i <= V; i++)
		{
			if (fix[i])
				continue;
			else
			{
				if (idx == -1)
					idx = i;
				else if (distance[i] < distance[idx])	// 거리가 최소인 곳 저장
					idx = i;
			}
		}
		if (idx == -1 || distance[idx] == INF)	// 더 이상 선택할 정점이 없으면
			break ;
		fix[idx] = 1;	// 거리 확정
		for (auto nxt : adj[idx])
			distance[nxt.Y] = min(distance[nxt.Y], distance[idx] + nxt.X);
	}
}

// 효율적인 구현 -> 우선순위 큐, 힙 사용