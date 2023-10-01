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
		int wib[] = new int[52];
		int girl[] = new int[52];

		int T = n;
		for (int t_i = 0; t_i < T; t_i++) {
			int total_score = 0;
			for (int i = 0; i < 52; i++) {
				wib[i] = 0;
				girl[i] = 1;
			}
			String cards = br.readLine().toString();
			st = new StringTokenizer(cards," ");
			for (int i = 0 ; i < 26; i++){
				//read_car_num;
				int card_num = 0;
				String card = st.nextToken();
				char num = card.charAt(0);
				//read_num
				if (num <= '9' && num >= '2'){
					card_num += num - '0' - 2;
				}
				else if(num == 'T'){
					card_num += 8;
				}
				else if(num == 'J'){
					card_num += 9;
				}
				else if(num == 'Q'){
					card_num += 10;
				}
				else if(num == 'K'){
					card_num += 11;
				}
				else if(num == 'A'){
					card_num += 12;
				}
				card_num *= 4;
				//read_suit D C H S
				char suit = card.charAt(1);
				if (suit == 'D')
					card_num += 0;
				else if (suit == 'C')
					card_num += 1;
				else if (suit == 'H')
					card_num += 2;
				else if (suit == 'S')
					card_num += 3;
//				System.out.print(card_num + " ");
				girl[card_num] = 0;
				wib[card_num] = 1;
			}
			//game
			for (int i = 0; i < 52; i++) {
				if (girl[i] == 1)
				{
					//find if wib has smallest bigger
					int win = -1;
					for (int j = i + 1; j < 52; j++) {
						if (wib[j] == 1)
						{
							win = j;
							break;
						}
					}
					//lose with smallest smaller
					if (win == -1)
					{
						for (int j = 0; j < i; j++) {
							if (wib[j] == 1)
								wib[j] = 0;
						}
					}
					//win
					else{
//						System.out.println("can win when fight with : " + i);
//						System.out.println("win num : " + win);
						wib[win] = 0;
						total_score++;
					}
				}
			}
			System.out.println(total_score);
		}
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


