import java.util.*;
import java.io.*;

public class Main{
	public static class node{
		public 
			char chr;
			PriorityQueue<node> child;
			boolean visited;

		node(char _chr){
			this.chr = _chr;
			this.child = new PriorityQueue<>(new Comparator<node>(){
				@Override
				public int compare(node n1, node n2){
					return (Integer.compare(n1.get_chr(), n2.get_chr()));
				}
			});
			this.visited = false;
		}

		public int get_chr(){
			return this.chr;
		}

		public node get_child(char target){
			Iterator<node> it = this.child.iterator();
			while (it.hasNext()){
				node temp = it.next();
				if (temp.get_chr() == target)
					return (temp);
				if (temp.get_chr() > target)
					break;
			}
			return (null);
		}

		public void add(node child){
			this.child.add(child);
		}

		public int get_child_num(){
			return (this.child.size());
		}

		public boolean get_visited(){
			return (this.visited);
		}

		public void check_visited(){
			this.visited = true;
		}
		
	}
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine(), " ");
			n = Integer.parseInt(st.nextToken());
			ArrayList<String> book = new ArrayList<>();
			for (int n_i = 0; n_i < n; n_i++) {
				book.add(br.readLine());
			}
			book.sort(Comparator.naturalOrder());
			node root = new node('x');
			boolean sol = true;
			for (int n_i = 0; n_i < n && sol == true; n_i++) {
				sol = true;
				String str = book.get(n_i);
//				System.out.println("str : " + str);
				node cur = root;
				for (int s_i = 0; s_i < str.length() && sol == true; s_i++) {
					char target = str.charAt(s_i);
					node find = cur.get_child(target);
					if (find == null)
					{
//						System.out.println("new node! target: " + target);
//						System.out.println("cur node : " + (char)cur.get_chr());
						//cur node has been visited
						if (cur.get_visited() == true && cur.get_child_num() == 0)
						{
							sol = false;
						}
						//cur node is new one
						else
						{
							node child = new node(target);
							cur.add(child);
							cur = child;
						}
					}
					else{
						if (s_i == str.length() - 1)
							sol = false;
						find.check_visited();
						cur = find;
					}
				}
			}
			if (sol == true)
				sb.append("YES\n");
			else
				sb.append("NO\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


