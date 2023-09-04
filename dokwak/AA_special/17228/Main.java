import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static long target_hash = 0;
	static int target_length = 0;
	static long seed = 197;
	static long mod = 998244353L;
	static long max_seed = 1;
	static int sol = 0;
	static String target;
	static ArrayList<int[]> adj_list[];

	public static void printBuffer(ArrayList<Integer> buffer){
		for (int i = 0; i < buffer.size(); i++) {
			int asci = buffer.get(i);
			char chr = (char)asci;
			System.out.print(chr);
		}
		System.out.println();
	}

	public static void rec(int []edge, int len, long hash, ArrayList<Integer> buffer)
	{
		int cur_len = len;
		long cur_hash = hash;
		int cur_node = edge[0];
		int to_node = edge[1];
		int ascii = edge[2];
		//full hash length
//		System.out.print("current buffer : ");
//		printBuffer(buffer);
//		System.out.println("current hash : " + cur_hash);
		if (cur_len >= target_length)
		{
			if (cur_hash == target_hash)
			{
				sol++;
//				System.out.print("found string! buf : ");
//				printBuffer(buffer);
			}
			//roll out
			cur_hash -= (buffer.get(buffer.size() - target_length) * max_seed) % mod;
			if(cur_hash < 0)
				cur_hash += mod;
			//diverge
			for (int i = 0; i < adj_list[to_node].size(); i++) {
				int next_edge[] = adj_list[to_node].get(i);
				int next_node = next_edge[1];
				int next_ascii = next_edge[2];
				buffer.add(next_ascii);
				long next_hash = (cur_hash * seed) + next_ascii;
				next_hash %= mod;
//				System.out.println("next hash : " + next_hash);
				rec(next_edge, len, next_hash, buffer);
//				System.out.println("poping : " + buffer.get(buffer.size() - 1));
				buffer.remove(buffer.size() - 1);
			}
		}
		//in case hash length is short
		else if (cur_len < target_length)
		{
			//diverge
			for (int i = 0; i < adj_list[to_node].size(); i++) {
				int next_edge[] = adj_list[to_node].get(i);
				int next_node = next_edge[1];
				int next_ascii = next_edge[2];
				buffer.add(next_ascii);
				long next_hash = (cur_hash * seed) + next_ascii;
				next_hash %= mod;
//				System.out.println("fiiling buffer. next hash : " + next_hash);
				rec(next_edge, len + 1, next_hash, buffer);
				buffer.remove(buffer.size() - 1);
			}
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
			target_hash = (target_hash * seed) + target.charAt(i);
			target_hash %= mod;
			if (i == 0)
				continue;
			max_seed *= seed;
			max_seed %= mod;
		}
//		System.out.println("target hash : " + target_hash);
		for (int i = 0; i < adj_list[1].size(); i++) {
			int ascii = adj_list[1].get(i)[2];
			ArrayList<Integer> buf = new ArrayList<>();
			buf.add(ascii);
			rec(adj_list[1].get(i), 1, ascii * 1, buf);//edge, len, hash, buf
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
