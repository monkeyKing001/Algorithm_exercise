import java.util.*;

public class Main{
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, sol;
		sol = 0;
		n = 0;
		int subin, sister;
		int []visited = new int[200100];
		Queue<Integer> q = new LinkedList<Integer>();
		subin = sc.nextInt();
		sister = sc.nextInt();
		visited[subin] = 1;
		q.add(subin);
		while(q.size() != 0)
		{
			int current_subin = q.remove();
			int step = visited[current_subin];
			if (current_subin == sister)
			{
				sol = step;
				break ;
			}
			for (int i = 0; i < 3; i++)
			{
				int next_subin;
				if (i == 0)
					next_subin = current_subin + 1;
				else if (i == 1)
					next_subin = current_subin - 1;
				else
					next_subin = current_subin * 2;
				if (next_subin < 0 || next_subin > 100000 || visited[next_subin] != 0)
					continue ;
				q.add(next_subin);
				visited[next_subin] = step + 1;
			}
		}
//		System.out.println("hello world");
		System.out.println(sol - 1);
		return ;
	}
}
