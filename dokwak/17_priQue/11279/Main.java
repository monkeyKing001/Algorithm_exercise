import java.util.*;
import java.io.*;

public class Main{
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int n = 0;

		//input
		n = Integer.parseInt(st.nextToken());
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		for (int i = 0; i < n; i++) {
			int cmd;
			cmd  = Integer.parseInt(br.readLine());
			if (cmd == 0)
			{
				if (pq.size() == 0)
					System.out.println(cmd);
				else
					System.out.println(pq.poll());
			}
			else
				pq.add(cmd);
		}
		return ;
	}
}

