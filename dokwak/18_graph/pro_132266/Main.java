import java.util.*;
import java.io.*;

class Solution {
    public int[] solution(int n, int[][] roads, int[] sources, int destination) {
        int[] answer = new int[sources.length];
		int inf = 10000000;
		ArrayList<Integer> adj_list[] = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			adj_list[i] = new ArrayList<>();
		}
		for (int i = 0; i < roads.length; i++) {
			int v1, v2;
			v1 = roads[i][0];
			v2 = roads[i][1];
			adj_list[v1].add(v2);
			adj_list[v2].add(v1);
		}
		int []cost_of_dest = new int [n + 1];
		int dest = destination;
		for (int j = 0; j < n + 1; j++) {
			cost_of_dest[j] = inf;
		}
		cost_of_dest[dest] = 0;
		PriorityQueue<int []> pq = new PriorityQueue<>(new Comparator<int[]>()
				{
					@Override
					public int compare(int []e1, int e2[])
					{
						return (Integer.compare(e1[1], e2[1]));
					}
				});
		for (int i = 0; i < adj_list[dest].size(); i++) {
			int connected_v = adj_list[dest].get(i);
			cost_of_dest[connected_v] = 1;
			int [] edge = new int[2];
			edge[0] = connected_v;
			edge[1] = cost_of_dest[connected_v];
			pq.add(edge);
		}
		while (pq.size() != 0)
		{
			int [] edge = pq.poll();
			int connected_v, connected_cost;
			connected_v = edge[0];
			connected_cost = edge[1];
			if (cost_of_dest[connected_v] != connected_cost)
				continue ;
			for (int i = 0; i < adj_list[connected_v].size(); i++) {
				int next_v = adj_list[connected_v].get(i);
				int next_cost = 1;
				if (cost_of_dest[next_v] > next_cost + connected_cost)
				{
					cost_of_dest[next_v] = next_cost + connected_cost;
					int [] new_edge = new int [2];
					new_edge[0]= next_v;
					new_edge[1]= cost_of_dest[next_v];
					pq.add(new_edge);
				}
			}
		}
		for (int i = 0; i < sources.length; i++) {
			if (cost_of_dest[sources[i]] == inf)
				answer[i] = -1;
			else
				answer[i] = cost_of_dest[sources[i]];
		}
        return answer;
    }
}
