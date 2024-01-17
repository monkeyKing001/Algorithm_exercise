import java.util.*;
import java.io.*;

public class Main{
	static int n, m;

	public static void rec(ArrayList<Integer> nums){
		if (nums.size() == 2){
			System.out.print(nums.get(0) + "" + nums.get(1));
		}
		else{
//			System.out.println(nums.toString());
			ArrayList<Integer> nextArr = new ArrayList<>();
			for (int i = 0; i < nums.size() - 1; i++) {
				int num1 = nums.get(i);
				int num2 = nums.get(i + 1);
				nextArr.add((num1 + num2) % 10);
			}
			rec(nextArr);
		}
	}

	static int strokes[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");

		//input
		String name1 = br.readLine();
		String name2 = br.readLine();
		ArrayList<Integer> arr = new ArrayList<>();
		for (int i = 0; i < name1.length(); i++) {
			char chr = name1.charAt(i);
			int idx = chr - 'A';
			int num = strokes[idx];
			char chr2 = name2.charAt(i);
			int idx2 = chr2 - 'A';
			int num2 = strokes[idx2];
			arr.add(num);
			arr.add(num2);
		}
		rec(arr);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


