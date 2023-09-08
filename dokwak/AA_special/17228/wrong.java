import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static long target_hash = 1;
	static int target_length = 0;
	static long seed = 927;
	static long mod = 998244353L;
	static int sol = 0;
	static String target;
	static ArrayList<int[]> adj_list[];
	static long max_seed = 1;
	static List<Long> stk = new ArrayList<>();

	public static void dfs(int cur_node){
		if (stk.size() > target.length()){
			long cur_hash = stk.get(stk.size() - 1) - stk.get(stk.size() - target_length - 1) * max_seed;
			cur_hash %= mod;
			if (cur_hash < 0)
				cur_hash += mod;
			if (cur_hash == target_hash)
				sol++;
		}
		for (int i = 0; i < adj_list[cur_node].size(); i++) {
			int info[] = adj_list[cur_node].get(i);
			int next_node = info[1];
			int ascii = info[2];
			stk.add(stk.get(stk.size() - 1) * seed + ascii % mod);
			dfs(next_node);
			stk.remove(stk.size() - 1);
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		adj_list = new ArrayList[n + 1];
		for (int i = 0; i < n + 1; i++) {
			adj_list[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine()," ");
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			char asc_char = st.nextToken().toString().charAt(0);
			int asc = (int)asc_char;
			int []node = new int[3];
			node[0] = u;
			node[1] = v;
			node[2] = asc;
			adj_list[u].add(node);
		}
		target = br.readLine();
		target_hash = 0;
		target_length = target.length();
		//init target hash
		for (int i = 0; i < target_length; i++) {
			target_hash  = ( (target_hash * seed) + target.charAt(i)) % mod;
			max_seed = (max_seed * seed) % mod;
		}
		stk.add(0L);
		dfs(1);
//		System.out.println("target hash : " + target_hash);
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
