import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static Map<String, Integer> romeToInt = new HashMap<>();
	static Map<Integer, String> intToRome = new HashMap<>();

	public static String integerToRome(int num){
		String str = "";
		int temp = num;
		while (temp != 0){
			int length = Integer.toString(temp).length();
			int maxBase = (int)Math.pow(10, length - 1);
			int extractNum = maxBase * (temp / maxBase);
//			System.out.println("extract : " + extractNum);
			str += intToRome.get(extractNum);
			temp -= extractNum;
		}
		return (str);
	}

	public static int romeToInteger(String str){
		int num = 0;
		int l = 0;
		while (l < str.length()){
			int r = l + 1;
			while (r <= str.length()){
				String temp = str.substring(l, r);
				if (!romeToInt.containsKey(temp))
					break;
				r++;
			}
			String romeToken = str.substring(l, r - 1);
//			System.out.println("Token : " +  romeToken);
			num += romeToInt.get(romeToken);
			l = r - 1;
		}
		return (num);
	}

	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");

		//input
		String rome1 = br.readLine();
		String rome2 = br.readLine();

		romeToInt.put("I", 1); romeToInt.put("II", 2); romeToInt.put("III", 3);romeToInt.put("IV", 4);
		romeToInt.put("V", 5); romeToInt.put("VI", 6); romeToInt.put("VII", 7);romeToInt.put("VIII", 8);
		romeToInt.put("IX", 9); 

		romeToInt.put("X", 10); romeToInt.put("XX", 20); romeToInt.put("XXX", 30);romeToInt.put("XL", 40);
		romeToInt.put("L", 50); romeToInt.put("LX", 60); romeToInt.put("LXX", 70);romeToInt.put("LXXX", 80);
		romeToInt.put("XC", 90); 

		romeToInt.put("C", 100); romeToInt.put("CC", 200); romeToInt.put("CCC", 300);romeToInt.put("CD", 400);
		romeToInt.put("D", 500); romeToInt.put("DC", 600); romeToInt.put("DCC", 700);romeToInt.put("DCCC", 800);
		romeToInt.put("CM", 900); 

		romeToInt.put("M", 1000);romeToInt.put("MM", 2000);romeToInt.put("MMM", 3000);
		ArrayList<Map.Entry<String, Integer>> ent = new ArrayList<>(romeToInt.entrySet());
		ent.sort(Map.Entry.comparingByValue());
		for (int i = 0; i < ent.size(); i++) {
			String rome = ent.get(i).getKey();
			int num = ent.get(i).getValue();
			intToRome.put(num, rome);
		}
		int num1 = 0, num2 = 0;
		num1 = romeToInteger(rome1);
		num2 = romeToInteger(rome2);
//		System.out.println("num 1 : " + num1);
//		System.out.println("num 2 : " + num2);
		int sum = num1 + num2;
		String romeSol = integerToRome(sum);
		System.out.println(sum);
		System.out.println(romeSol);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}
