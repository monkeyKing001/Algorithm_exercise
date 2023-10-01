import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int T;
	static Stack<String> shirts;
	static Stack<String> pants;
	static Stack<String> socks;
	public static void wear(){
		while (pants.size() != 0 && shirts.size() != 0 && socks.size() != 0){
			System.out.println(shirts.pop() + ", " + pants.pop() + ", " + socks.pop());
		}
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		shirts = new Stack<>();
		pants = new Stack<>();
		socks = new Stack<>();

		//input
		n = Integer.parseInt(st.nextToken());
		T = n;
		for (int t_i = 0; t_i < T; t_i++) {
			st = new StringTokenizer(br.readLine()," ");
			m = Integer.parseInt(st.nextToken());
			for (int m_i = 0; m_i < m; m_i++) {
				st = new StringTokenizer(br.readLine(),"(");
				String item = st.nextToken().toString();
				String category = st.nextToken().toString();
				if (category.charAt(1) == 'h')//shirts
				{
//					System.out.println("shirts : " + item.strip());
					shirts.add(item.strip());
				}
				else if (category.charAt(1) == 'a')//pants
				{
//					System.out.println("pants : " + item.strip());
					pants.add(item.strip());
				}
				else if (category.charAt(1) == 'o')//socks
				{
//					System.out.println("socks : " + item.strip());
					socks.add(item.strip());
				}
			}
			wear();
			shirts.clear();
			pants.clear();
			socks.clear();
			if (t_i == T - 1)
				break;
			System.out.println();
		}

		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


