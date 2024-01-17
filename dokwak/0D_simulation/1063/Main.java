import java.util.*;
import java.io.*;

public class Main{
	static int n, m;
	static int dc[] = {1, -1, 0, 0}; //RLBT
	static int dr[] = {0, 0, -1, 1}; //RLBT
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		sb.append("");
		StringTokenizer st = new StringTokenizer(br.readLine()," ");
		Map<Character, Integer> direction = new HashMap<>(); 
		direction.put('R' , 0);
		direction.put('L' , 1);
		direction.put('B' , 2);
		direction.put('T' , 3);
		//input
		String kingPos = st.nextToken();
		String stonePos = st.nextToken();
		int cmd = Integer.parseInt(st.nextToken());
		char[] king = kingPos.toCharArray(); //c, r
		char[] stone = stonePos.toCharArray();//c, r
		for (int i = 0; i < cmd; i++) {
			String cmdStr = br.readLine();
			int dc_ = 0;
			int dr_ = 0;
			for (int c_i = 0; c_i < cmdStr.length(); c_i++) {
				char chr = cmdStr.charAt(c_i);
				dc_ += dc[direction.get(chr)];
				dr_ += dr[direction.get(chr)];
			}
//			System.out.println("MOVE dc, dr : " + cmdStr +" "+ dc_+ ", "+dr_);
			char nextKingC = (char)((int)king[0] + dc_);
			char nextKingR = (char)((int)king[1] + dr_);
			//movable
			if (nextKingC >= 'A' && nextKingC <= 'H' && nextKingR >= '1' && nextKingR <= '8'){
				//if stone move, move both
				if (nextKingC == stone[0] && nextKingR == stone[1]){
					char nextStoneC = (char)((int)stone[0] + dc_);
					char nextStoneR = (char)((int)stone[1] + dr_);
					//if stone movable
					if (nextStoneC >= 'A' && nextStoneC <= 'H' && nextStoneR >= '1' && nextStoneR <= '8'){
						stone[0] = nextStoneC;
						stone[1] = nextStoneR;
						king[0] = nextKingC;
						king[1] = nextKingR;
//						System.out.println("king : " + king[0]+king[1]);
//						System.out.println("stone : " + stone[0]+stone[1]);
					}
					else 
						continue;
				}
				//else move King
				else{
						king[0] = nextKingC;
						king[1] = nextKingR;
//						System.out.println("king : " + king[0]+king[1]);
				}
			}
		}
		kingPos = new String(king);
		stonePos = new String(stone);
		System.out.println(kingPos);
		System.out.println(stonePos);
		bw.write(sb.toString());
		bw.flush();
		return ;
	}
}


