import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static class Node{

		public
			int h;
			String str;
			ArrayList<Node> child = new ArrayList<>();
			Node(int h, String str){
				this.h = h;
				this.str = str;
			}

			Node getChild(int i){
				return (this.child.get(i));
			}

			Node find(String str){
				for (int i = 0; i < child.size(); i++) {
					if (this.child.get(i).str == str)
						return (this.child.get(i));
				}
				return (null);
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
		Node root = new Node(0, "");
		for (int i = 0; i < n; i++) {
		}
		m = Integer.parseInt(st.nextToken());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


