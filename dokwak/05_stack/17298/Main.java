import java.util.*;
import java.io.*;
import java.lang.*;

public class Main{
	public static void main (String[] args) throws IOException {
		String buf = "";
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		int n = 0;

		//input
		//n = Integer.parseInt(st.nextToken());
//		System.out.println(n);
		int []arr = new int[1000001];
		int []okun = new int[1000001];
		n = Integer.parseInt(br.readLine());
		Stack <Integer> s = new Stack<>();
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			int temp = Integer.parseInt(st.nextToken());
			arr[i] = temp;
			okun[i] = -1;
			if (i != 0 && arr[i - 1] < temp)
				okun[i - 1] = temp;
			while (s.size() != 0 && arr[s.peek()] < temp)
			{
				okun[s.peek()] = temp;
				s.pop();
			}
			s.push(i);
		}
		for (int i = 0; i < n; i++) {
			sb.append(okun[i] + " ");
		}
		System.out.println(sb);
		return ;
	}
}

