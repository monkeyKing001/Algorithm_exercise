import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int highest_dgr_coef = 0;
	public static long dfs(int max_degree, int cur_degree, int cur_idx, long cur_val){
		long ret = cur_val;
		return (ret);
	}

	public static long[] findCoefficientsFromRoots(ArrayList<Integer> roots) {
        int degree = roots.size() + 1; // Degree of the polynomial
        long[] coefficients = new long[degree];

        // Initialize the coefficients array
        coefficients[0] = highest_dgr_coef;

        for (int i = 0; i < roots.size(); i++) {
            for (int j = degree - 1; j > 0; j--) {
                coefficients[j] -= roots.get(i) * coefficients[j - 1];
            }
        }

        return coefficients;
    }
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//		StringBuilder sb = new StringBuilder();
//		sb.append("");
//		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
//		n = Integer.parseInt(st.nextToken());
//		m = Integer.parseInt(st.nextToken());
//		bw.write(sb.toString());
//		bw.flush();
		String info = br.readLine();
		long sol = 0L;
		long dp[] = new long[10001];
		dp[0] = 1;
		ArrayList<Integer> roots = new ArrayList<>();
		for (int i = 0; i < info.length() - 1; i++) {
			char info_i = info.charAt(i);
			char info_i_pl_1 = info.charAt(i + 1);
			int idx = (i + 1) * 2;
			int next_idx = idx + 2;
			if (info_i != info_i_pl_1)
				roots.add(idx + 1);
		}
		if (roots.size() % 2 == 0){
			if (info.charAt(0) == 'H')
				highest_dgr_coef = 1;
			else
				highest_dgr_coef = -1;
		}
		else{
			if (info.charAt(0) == 'H')
				highest_dgr_coef = -1;
			else
				highest_dgr_coef = 1;
		}
		System.out.println(roots.size());
//		for (int i = 0; i < roots.size(); i++) {
//			System.out.print(roots.get(i) + " ");
//		}
		// Find coefficients
        long[] coefficients = findCoefficientsFromRoots(roots);
		for (int i = 0; i < coefficients.length; i++) {
			System.out.print(coefficients[i] + " ");
		}
		return ;
	}
}
