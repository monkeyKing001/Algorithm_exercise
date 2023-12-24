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
		String startStr = st.nextToken();
		String endStr = st.nextToken();
		String quitStr = st.nextToken();
		Set<String> in = new HashSet<String>();
		int sol = 0;
//		st = new StringTokenizer(startStr, ":");
//		int startHour = Integer.parseInt(st.nextToken());
//		int startMinutes = Integer.parseInt(st.nextToken());
//		int startTime  = startHour * 100 + startMinutes;
		String info = br.readLine();
		while (info != null){
			st = new StringTokenizer(info," ");
			String time = st.nextToken();
			String name = st.nextToken();
			info = br.readLine();
			//enter
			if (time.compareTo(startStr) <= 0){
//				System.out.println(name + " in!");
				in.add(name);
			}
			//out
			else if (endStr.compareTo(time) <= 0 && time.compareTo(quitStr) <= 0){
				if (in.contains(name)){
					in.remove(name);
//					System.out.println(name + " has out!");
					sol++;
				}
			}
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


