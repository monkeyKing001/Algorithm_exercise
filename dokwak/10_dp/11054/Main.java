import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static ArrayList<Integer> inc = new ArrayList<>();
	static ArrayList<Integer> dec = new ArrayList<>();
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
		ArrayList<Integer> inOrder = new ArrayList<>();
		ArrayList<Integer> revOrder = new ArrayList<>();
		ArrayList<Integer> arr = new ArrayList<>();
		int inorderDp [] = new int[n];
		int revOrderDp [] = new int[n];
		//inorder
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			arr.add(num);
		}
		for (int i = 0; i < arr.size(); i++) {
			int num = arr.get(i);
			int idx = bstLowerBound(inOrder, num);
			if (inOrder.size() == 0 || idx == -1){
				inOrder.add(num);
			}
			else{
				inOrder.set(idx, num);
			}
			inorderDp[i] = inOrder.size();
		}
		for (int i = 0; i < arr.size(); i++) {
			int numIdx = arr.size() - 1 - i;
			int num = arr.get(numIdx);
			int idx = bstLowerBound(revOrder, num);
			if (revOrder.size() == 0 || idx == -1){
				revOrder.add(num);
			}
			else{
				revOrder.set(idx, num);
			}
			revOrderDp[numIdx] = revOrder.size();
		}
		int sol = 1;
		for (int i = 0; i < n; i++) {
			sol = Math.max(inorderDp[i] + revOrderDp[i] - 1, sol);
		}
		System.out.println(sol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
