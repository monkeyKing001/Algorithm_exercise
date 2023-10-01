import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int know_truth_num;
	static int party_num;
	static ArrayList<Integer> party_info[];
	static ArrayList<Integer> truth_member;
	static Set<Integer> unsafe_party;
	static int p[];
	public static int find_p(int u){
		if (p[u] == -1)
			return (u);
		p[u] = find_p(p[u]);
		return (p[u]);
	}

	public static boolean same_p(int u, int v){
		if (find_p(u) == find_p(v))
			return true;
		return false;
	}

	public static void merge_p(int u, int v){
//		System.out.println("merging u, v : " + u + ", " + v);
		int u_p = find_p(u);
		int v_p = find_p(v);
		if (u_p > v_p){
			int temp = u_p;
			u_p = v_p;
			v_p = temp;
		}
		p[v_p] = u_p;
//		System.out.println("now same p member u, v :" + u +", "+ v);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		party_num = m;
		p = new int[n + 1];
		unsafe_party = new HashSet<>();
		party_info = new ArrayList[party_num];
		for (int i = 0; i < n + 1; i++) {
			p[i] = -1;
		}
		st = new StringTokenizer(br.readLine()," ");
		know_truth_num = Integer.parseInt(st.nextToken());
		truth_member = new ArrayList<>();
		for (int i = 0; i < know_truth_num; i++) {
			int member = Integer.parseInt(st.nextToken());
			truth_member.add(member);
		}
		for (int p_i = 0; p_i < party_num; p_i++) {
			party_info[p_i] = new ArrayList<>();
			st = new StringTokenizer(br.readLine()," ");
			int party_mem_num = Integer.parseInt(st.nextToken());
			int u = Integer.parseInt(st.nextToken());
			party_info[p_i].add(u);
			for (int i = 0; i < party_mem_num - 1; i++) {
				int v = Integer.parseInt(st.nextToken());
				party_info[p_i].add(v);
				if (same_p(u, v) == false)
					merge_p(u, v);
			}
		}
		for (int i = 0; i < truth_member.size(); i++) {
			int i_know_the_truth = truth_member.get(i);
			int his_root = find_p(i_know_the_truth);
			unsafe_party.add(his_root);
		}
		int sol = 0;
		for (int i = 0; i < m; i++) {
			int party_i = i;
			boolean safe = true;
			for (int party_mem_i = 0; party_mem_i < party_info[party_i].size(); party_mem_i++) {
				int mem = party_info[party_i].get(party_mem_i);
				if (unsafe_party.contains(find_p(mem)) == true)
				{
					safe = false;
					break;
				}
			}
			if (safe == true)
				sol++;
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
