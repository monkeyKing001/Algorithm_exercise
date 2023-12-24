import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		//StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		String S = br.readLine();
		String T = br.readLine();
		Queue<String> q = new LinkedList<>();
		int sol = 0;
		q.add(S);
		Set<String> set = new HashSet<>();
		while (q.size() != 0){
			String str = q.poll();
//			System.out.println("str : " + str);
			if (str.length() == T.length() && str.compareTo(T) == 0)
			{
				sol = 1;
				break;
			}
			if (set.contains(str))
				continue;
			set.add(str);
			String strA = str + "A";
			String strB = "B" + (sb = new StringBuilder(str)).reverse();
			String revT = (sb = new StringBuilder(T)).reverse().toString();
			for (int i = 0; i <= T.length() - strA.length(); i++) {
				if (T.startsWith(strA, i)) {
//					System.out.println("A : " + strA);
					q.add(strA);
					break;
				}
				else if (revT.startsWith(strA, i)){
//					System.out.println("A : " + strA);
					q.add(strA);
					break;
				}
			}
			for (int i = 0; i <= T.length() - strB.length(); i++) {
				if (T.startsWith(strB, i)) {
//					System.out.println("B : " + strB);
					q.add(strB);
					break;
				}
				else if (revT.startsWith(strB, i)) {
//					System.out.println("B : " + strB);
					q.add(strB);
					break;
				}
			}
		}
		System.out.println(sol);
		//bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


