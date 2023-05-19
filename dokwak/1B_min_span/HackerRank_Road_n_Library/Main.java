import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'roadsAndLibraries' function below.
     *
     * The function is expected to return a LONG_INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. INTEGER c_lib
     *  3. INTEGER c_road
     *  4. 2D_INTEGER_ARRAY cities
     */
	static int []parent;

	public static int find(int v)
	{
		if (parent[v] == 0)
			return (v);
		parent[v] = find(parent[v]);
		return (parent[v]);
	}

	public static void union(int v1, int v2)
	{
		int v1_g = find(v1); 
		int v2_g = find(v2); 
		if (v1_g > v2_g)
		{
			int temp = v1_g;
			v1_g = v2_g;
			v2_g = temp;
		}
		parent[v2_g] = v1_g;
	}
    public static long roadsAndLibraries(int n, int c_lib, int c_road, List<List<Integer>> cities) {
    // Write your code here
		
		long sol = Long.MAX_VALUE;
		int cur_n = n;
		parent = new int[n  + 1];
		long []dp = new long [n + 1];
		for (int i = 0; i < n + 1; i++) {
			parent[i] = 0;	
			dp[i] = Long.MAX_VALUE;
		}
		dp[cur_n] = c_lib * n;
//		System.out.println("dp[" + cur_n + "] : "+ dp[cur_n]);
		for (int i = 0; i < cities.size(); i++) {
			List<Integer> edge = cities.get(i);
			int v1 = edge.get(0);
			int v2 = edge.get(1);
			if (find(v1) != find(v2))
			{
				union(v1, v2);
				dp[cur_n - 1] = dp[cur_n] + c_road - c_lib;
//				System.out.println("dp[" + (cur_n - 1) + "] : "+ dp[cur_n - 1]);
				cur_n--;
			}
		}
		for (int i = 1; i < n + 1; i++) {
			if (sol > dp[i])
				sol = dp[i];
		}
//		System.out.println("sol : " + sol);
		return (sol);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = Integer.parseInt(bufferedReader.readLine().trim());

        IntStream.range(0, q).forEach(qItr -> {
            try {
                String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

                int n = Integer.parseInt(firstMultipleInput[0]);

                int m = Integer.parseInt(firstMultipleInput[1]);

                int c_lib = Integer.parseInt(firstMultipleInput[2]);

                int c_road = Integer.parseInt(firstMultipleInput[3]);

                List<List<Integer>> cities = new ArrayList<>();

                IntStream.range(0, m).forEach(i -> {
                    try {
                        cities.add(
                            Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                                .map(Integer::parseInt)
                                .collect(toList())
                        );
//						System.out.println("cities.size() =  " + cities.size());
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                });

                long result = Result.roadsAndLibraries(n, c_lib, c_road, cities);

                bufferedWriter.write(String.valueOf(result));
                bufferedWriter.newLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
