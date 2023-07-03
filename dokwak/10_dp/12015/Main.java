import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine(), " ");
		TreeSet<Integer> s = new TreeSet<>();
		int biggest = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++) {
			int temp = Integer.parseInt(st.nextToken());
			if (temp > biggest)
			{
				s.add(temp);
				biggest = temp;
			}
			else if (s.contains(temp) == false){
				Integer find = s.higher(temp);
				if (find != null)
				{
//					System.out.println("removing " + find);
					if (find == biggest)
						biggest = temp;
					s.remove(find);
					s.add(temp);
//					System.out.println("added " + temp);
				}
			}
		}
		System.out.println(s.size());
		return ;
	}
}
