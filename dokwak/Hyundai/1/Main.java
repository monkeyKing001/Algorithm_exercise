import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int size;
	static ArrayList<String> driver = new ArrayList<>();
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st;
		String input = br.readLine();
		ArrayList<String> arr = new ArrayList<>();
		Map<String, Integer> map = new HashMap<String, Integer>();
		Set<String> set = new HashSet<String>();

		//input
		
		while(input != null){
			st = new StringTokenizer(input," ");
			n = Integer.parseInt(st.nextToken());
			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine()," ");
				int num = Integer.parseInt(st.nextToken());
				for (int j = 0; j < num; j++) {
					String input_str = st.nextToken();
				}
			}
			input = br.readLine();
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
