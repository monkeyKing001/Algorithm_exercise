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
		String start = st.nextToken();
		String end = st.nextToken();
		String streamingEnd = st.nextToken();
		String info = br.readLine();
		int count = 0;
		Set<String> come = new HashSet<>();
		while (info != null){
			st = new StringTokenizer(info," ");
			String time = st.nextToken();
			//come in
			String name = st.nextToken();
			if (start.compareTo(time) >= 0){
				come.add(name);
//				System.out.println("come in : " + name);
			}
			else if (end.compareTo(time) <= 0 && streamingEnd.compareTo(time) >= 0){
				if (come.contains(name)){
					count++;
					come.remove(name);
				}
			}
			info = br.readLine();
			if (info== null || info.length() == 0)
				break;
		}
		System.out.println(count);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


