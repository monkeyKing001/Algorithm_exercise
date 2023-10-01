import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> lis;
	public static int findSmallestBiggerIndex(int num){
		//bst
		int l = 0;
		int r = lis.size() - 1;
		int mid = (l + r) / 2;
		int findIndex = -1;
		while (l <= r){
			mid = (l + r) / 2;
			if (lis.get(mid) >= num){
				findIndex = mid;
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
		return (findIndex);
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		int arr[] = new int[n + 1]; 
		st = new StringTokenizer(br.readLine()," ");
		lis = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());;
		}
		for (int i = 0; i < n; i++) {
			int num = arr[i];
			int smallestBiggerIndex = findSmallestBiggerIndex(num);
			if (smallestBiggerIndex == -1)
				lis.add(num);
			else
				lis.set(smallestBiggerIndex, num);
		}
		sb.append(lis.size());
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
