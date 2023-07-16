import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static int find_lower_bound(ArrayList<Integer> arr, int target){
		int index = -1;
		int l = 0;
		int r = arr.size() - 1;
		int mid = (l + r) / 2;
		while (l <= r){
			if (arr.get(mid) < target){
				l = mid + 1;
			}
			else if (arr.get(mid) >= target){
				index = mid;
				r = mid - 1; 
			}
			mid = (l + r) / 2;
		}
		return (index);
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		ArrayList<Integer> lis = new ArrayList<>();
		ArrayList<Integer> input = new ArrayList<>();

		n = Integer.parseInt(st.nextToken());
		int []sol = new int [n + 1];
		int max_index = -1;

		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int num = Integer.parseInt(st.nextToken());
			input.add(num);
		}

		for (int i = 0; i < n; i++) {
			int num = input.get(i);
			int index_for_num = find_lower_bound(lis, num);
			//max num
			if (lis.size() == 0 || index_for_num == -1)
			{
				lis.add(num);
				sol[i] = lis.size() - 1;
				max_index = i;
//				System.out.println("max num : " + num);
			}
			else{
				lis.set(index_for_num, num);
				sol[i] = index_for_num;
			}
		}
		int lis_index = lis.size() - 1;
//		System.out.println("lis_index : "+ lis_index);
		int index = max_index;
//		System.out.println("max_index : " + index);
//		for (int i = 0; i < n; i++) {
//			System.out.println("sol[" + i + "] : " + sol[i]);
//		}
		sb.append(lis.size() + "\n");
		Stack <Integer> s = new Stack<>();
		while (index > -1){
			if (sol[index] == lis_index)
			{
				s.add(input.get(index));
				lis_index--;
			}
			if (lis_index == -1)
				break;
			index--;
		}
		while (s.empty() != true){
			sb.append(s.pop() +  " ");
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
