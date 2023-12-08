import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static int bstLowerBound(ArrayList<Integer>arr, int key){
		int idx = -1;
		int left = 0;
		int right = arr.size() - 1;
		while (left <= right){
			int mid = (left + right) / 2;
			if (arr.get(mid) < key)
				left = mid + 1;
			else{
				idx = mid;
				right = mid - 1;
			}
		}
		return idx;
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		ArrayList<Integer> arr = new ArrayList<>();
		int [] dp = new int[n];
		int [] nums = new int[n];
		st = new StringTokenizer(br.readLine()," ");
		int lastIdx = -1;
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			nums[i] = num;
			int idx = bstLowerBound(arr, num);
			if (idx == -1){
				arr.add(num);
				dp[i] = arr.size() - 1;
				lastIdx = i;
			}
			else{
				arr.set(idx, num);
				dp[i] = idx;
			}
		}
		ArrayList<Integer> lis = new ArrayList<>();
		int curIdx = lastIdx;
		while (curIdx > -1){
			lis.add(nums[curIdx]);
			int nextIdx = curIdx - 1;
			while (nextIdx > - 1 && dp[nextIdx] != dp[curIdx] - 1){
				nextIdx--;
			}
			curIdx = nextIdx;
		}
		System.out.println(lis.size());
		for (int i = 0; i < lis.size(); i++) {
			System.out.print(lis.get(lis.size() - 1 - i) + " ");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


