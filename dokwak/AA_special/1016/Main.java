import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int max = 1000001;
	static boolean sol[];
	public static boolean isNonSqr(ArrayList<Integer> p, long target){
		boolean ret = true;
		for (int i = 0; i < p.size(); i++) {
			if (p.get(i) > target)
				break;
			long sqr = p.get(i) * p.get(i);
			if (target % sqr == 0) {
				ret = false;
				break;
			}
		}
		return (ret);
	}

	public static void eratos(ArrayList<Integer> p, long minNum, long maxNum){
		for (int i = 0; i < p.size(); i++) {
			int pNum = p.get(i);
			long pNumSqr = (long)pNum * (long)pNum;
			if (pNumSqr > maxNum)
				break;
			long div = minNum / pNumSqr;
			long startNum = pNumSqr * div;
//			System.out.println("pNum : " + pNum);
//			System.out.println("pNumSqr : " + pNumSqr);
//			System.out.println("div : " + div);
//			System.out.println("startNum : " + startNum);
			while (startNum <= maxNum){
				if (startNum - minNum >= 0 && sol[(int)(startNum - minNum)] != false && startNum <= maxNum)
					sol[(int)(startNum - minNum)] = false;
				startNum += pNumSqr;
			}
		}
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		boolean primeNumber[] = new boolean[max];
		ArrayList<Integer> everyPrimeNumber = new ArrayList<>();
		for (int i = 2; i < max; i++) {
			primeNumber[i] = true;
		}

		for (int i = 0; i < max; i++) {
			if (primeNumber[i] == true) {
				for (int j = 2; j < max; j++) {
					long limit = i * j;
					if (limit >= max)
						break;
					primeNumber[i * j] = false;
				}
			}
		}
		for (int i = 0; i < max; i++) {
			if (primeNumber[i] == true)
				everyPrimeNumber.add(i);
		}
		long start = Long.parseLong(st.nextToken());
		long end = Long.parseLong(st.nextToken());
		sol = new boolean[(int)(end - start + 1)];
		for (int i = 0; i < end - start + 1; i++) {
			sol[i] = true;
		}
		eratos(everyPrimeNumber, start, end);
		int totalCount = 0;
		for (int i = 0; i < sol.length; i++) {
			if (sol[i] == true)
				totalCount++;
		}
		System.out.println(totalCount);

		//input
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


