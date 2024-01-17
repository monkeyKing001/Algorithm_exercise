import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");

		//input
		Map<Integer, String> map = new HashMap<>();
		String str = br.readLine();
		map.put(2, "BB");
		map.put(4, "AAAA");
		for (int i = 3; i <= 25; i++) {
			int len = i * 2;
			String newStr = "";
			if ((len - 4) % 4 == 0){
				newStr = map.get(4) + map.get(len - 4);
			}
			else if ((len - 4) % 4 != 0 && (len - 2) % 2 == 0){
				newStr  = map.get(len - 2) + map.get(2);
			}
			map.put(len, newStr);
//			System.out.println("len, str : " + len + ", " + newStr);
		}
		StringTokenizer st = new StringTokenizer(str,".");
		ArrayList<String> target = new ArrayList<>();
		while (st.hasMoreTokens()) {
			String tango = st.nextToken();
			target.add(tango);
		}
		for (int i = 0; i < target.size(); i++) {
			String t = target.get(i);
			if (!map.containsKey(t.length())){
				System.out.println("-1");
				return;
			}
			str = str.replaceFirst(target.get(i), map.get(target.get(i).length()));
//			System.out.println("replcace from, to : " +target.get(i)+ ", "+ map.get(target.get(i).length()));
		}
		System.out.println(str);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
