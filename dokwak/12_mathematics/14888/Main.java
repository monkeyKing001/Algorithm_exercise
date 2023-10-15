import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int temp_max = Integer.MIN_VALUE;
	static int temp_min = Integer.MAX_VALUE;
	static int operator[] = new int [4];// + - * /
	static int nums[] = new int[11];
	static int cal_operator[] = new int[11];

	public static void print_operators(){
		for (int i = 0; i < n; i++) {
			System.out.print(nums[i]);
			if (i == n - 1)
				continue;
			else{
				if (cal_operator[i] == 0){
					System.out.print(" + ");
				}
				if (cal_operator[i] == 1){
					System.out.print(" - ");
				}
				if (cal_operator[i] == 2){
					System.out.print(" * ");
				}
				if (cal_operator[i] == 3){
					System.out.print(" / ");
				}
			}
		}
		System.out.println();
	}

	public static void calculate(){
		int result = nums[0];
		for (int i = 0; i < n - 1; i++) {
			int next_number = nums[i + 1];
			if (cal_operator[i] == 0){//operator +
				result += next_number;
			}
			if (cal_operator[i] == 1){//operator -
				result -= next_number;
			}
			if (cal_operator[i] == 2){//operator *
				result *= next_number;
			}
			if (cal_operator[i] == 3){//operator /
				if (result > 0){
					result /= next_number;
				}
				else{
					result *= -1;
					result /= next_number;
					result *= -1;
				}
			}
		}
		temp_max = Integer.max(temp_max, result);
		temp_min = Integer.min(temp_min, result);
	}

	public static void dfs(int idx){
		if (idx == n - 1){
//			System.out.println("made all of operators");
//			print_operators();
			calculate();
			return ;
		}
		for (int i = 0; i < 4; i++) {
			if (operator[i] > 0){
				cal_operator[idx] = i;
				operator[i]--;
				dfs(idx + 1);
				cal_operator[idx] = -1;
				operator[i]++;
			}
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int number = Integer.parseInt(st.nextToken());
			nums[i] = number;
		}
		st = new StringTokenizer(br.readLine()," ");
		//input operator
		for (int i = 0; i < 4; i++) {
			int oper_num = Integer.parseInt(st.nextToken());
			operator[i] = oper_num;
		}
		//init cal operator
		for (int i = 0; i < n - 1; i++) {
			cal_operator[i] = -1;
		}
		dfs(0);
		System.out.println(temp_max);
		System.out.println(temp_min);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
