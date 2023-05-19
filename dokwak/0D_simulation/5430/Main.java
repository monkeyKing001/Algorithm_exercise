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
		int T = Integer.parseInt(st.nextToken());
		for (int t_i = 0; t_i < T; t_i++) {
			String cmd = br.readLine();	
			int arr_len = Integer.parseInt(br.readLine());
			ArrayList<Integer> arr = new ArrayList<>();
			String arr_str = br.readLine();
			int index = 1;
			while (index < arr_str.length() - 1)
			{
				int num = 0;
				while (arr_str.charAt(index) != ',' && arr_str.charAt(index) != ']')
				{
					num *= 10;
					num += arr_str.charAt(index) - '0';
					index++;
				}
				arr.add(num);
				index++;
			}
			int head = 1;
			for (int i = 0; i < cmd.length(); i++) {
				if (cmd.charAt(i) == 'R')
					head *= -1;
				else if (cmd.charAt(i) == 'D')
				{
					int arr_index = 0;
					if (arr.size() == 0)
					{
						head = -5;
						break ;
					}
					if (head < 0)
						arr_index = arr.size() - 1;
					arr.remove(arr_index);
				}
			}
			if (head == -5)
			{
				sb.append("error\n");
				continue ;//next test case
			}
			sb.append("[");
			if (head == -1)
			{
				for (int i = arr.size() - 1; i > -1; i--) {
					sb.append(arr.get(i).toString());
					if (i != 0)
						sb.append(",");
				}
			}
			else if (head == 1)
			{
				for (int i = 0; i < arr.size(); i++) {
					sb.append(arr.get(i).toString());
					if (i != arr.size() - 1)
						sb.append(",");
				}
			}
			sb.append("]\n");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
