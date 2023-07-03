import java.util.*;
import java.io.*;
import java.math.*;

public class Main{
	static int n, m;
	static ArrayList<double []> arr = new ArrayList<>();
	public static double area(double []cor1, double []cor2, double []cor3)
	{
		double a = cor1[0], b = cor1[1], c = cor2[0], d = cor2[1], e = cor3[0], f = cor3[1];
		return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
	}
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			double []cor = new double [2];
			cor[0] = Integer.parseInt(st.nextToken());
			cor[1] = Integer.parseInt(st.nextToken());
			arr.add(cor);
		}
		double sol = 0;
		for (int i = 1; i < n - 1; i++) {
			sol += area(arr.get(0), arr.get(i), arr.get(i + 1));
		}
		sol = Math.abs(sol);
		sol = Math.round(sol * 10) / 10;
		BigDecimal b = new BigDecimal(Double.parseDouble(Double.toString(sol))); 
		System.out.println(b.toString());
		return ;
	}
}

