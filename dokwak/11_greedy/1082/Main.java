import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");

		//input
		n = Integer.parseInt(st.nextToken());
		ArrayList<int[]> arr = new ArrayList<>();
		ArrayList<int[]> arrNotZero = new ArrayList<>();
		int [] priceInfo = new int[10];
		st = new StringTokenizer(br.readLine()," ");
		for (int i = 0; i < n; i++) {
			int price = Integer.parseInt(st.nextToken());
			int num = i;
			int []info = new int[2];
			info[0] = num;
			info[1] = price;
			priceInfo[i] = price;
			arr.add(info);
			if (i != 0){
				arrNotZero.add(info);
			}
		}
		arr.sort(new Comparator<int[]>(){
			@Override
			public int compare(int [] info1, int info2[]){
				if (info1[1] == info2[1]){
					return Integer.compare(info2[0], info1[0]);
				}
				return Integer.compare(info1[1], info2[1]);
			}
		});
		arrNotZero.sort(new Comparator<int[]>(){
			@Override
			public int compare(int [] info1, int info2[]){
				if (info1[1] == info2[1]){
					return Integer.compare(info2[0], info1[0]);
				}
				return Integer.compare(info1[1], info2[1]);
			}
		});
		st = new StringTokenizer(br.readLine()," ");
		int budget = Integer.parseInt(st.nextToken());
		ArrayList<Integer> purchase = new ArrayList<>();
		if (arrNotZero.size() != 0 && budget >= arrNotZero.get(0)[1])
		{
			budget -= arrNotZero.get(0)[1];
			purchase.add(arrNotZero.get(0)[0]);
		}
		while (budget >= arr.get(0)[1] && purchase.size() != 0){
			budget -= arr.get(0)[1];
			purchase.add(arr.get(0)[0]);
		}
		int l = 0;
		while (l < purchase.size() && arrNotZero.size() != 0){
			for (int i = n - 1; i > -1; i--) {
				if (priceInfo[purchase.get(l)] + budget >= priceInfo[i]){
					budget += priceInfo[purchase.get(l)];
					budget -= priceInfo[i];
					purchase.set(l, i);
					l++;
					break;
				}
				if (i == 0){
					budget = 0;
					break;
				}
			}
		}
		if (purchase.size() == 0){
			purchase.add(0);
		}
		purchase.sort(Comparator.reverseOrder());
		for (int i = 0; i < purchase.size(); i++) {
			sb.append(purchase.get(i));
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


