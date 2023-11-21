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
     * Complete the 'getMergedLineSegments' function below.
     *
     * The function is expected to return a 2D_INTEGER_ARRAY.
     * The function accepts 2D_INTEGER_ARRAY lineSegments as parameter.
     */
    static int p[];
    static int visited[];
    public static int find(int u){
        if (p[u] == 0 || p[u] == u)
            return u;
        p[u] = find(p[u]);
        return (p[u]);
    } 
    
    public static void union(int u, int v){
        int p_u = find(u);
        int p_v = find(v);
        if (p_u == p_v)
            return;
        if (p_u > p_v){
            int temp = p_u;
            p_u = p_v;
            p_v = p_u;
        }
        p[p_v] = p_u;
    }

    public static List<List<Integer>> getMergedLineSegments(List<List<Integer>> lineSegments) {
    // Write your code here
        List<List<Integer>> ret = new ArrayList<>();
        p = new int [100001];
        visited = new int [100001];
        for (int i = 0; i < 1000001; i++) {
            p[i] = 0;
            visited[i] = 0;
        }
		Set<Integer> s = new TreeSet();
		s.add(1);
        int max_end_point = -1;
        int min_start_point = Integer.MAX_VALUE;
        for (int i = 0; i < lineSegments.size(); i++) {
            List<Integer> line = lineSegments.get(i);
            int start_point = line.get(0);
            int end_point = line.get(1);
            max_end_point = Integer.max(max_end_point, end_point);
            min_start_point = Integer.max(min_start_point, start_point);
            for (int j = start_point; j < end_point + 1; j++) {
                union(start_point, j);
                visited[j] = 1;
            }
        }
        int line_start = min_start_point;
        while (line_start < max_end_point){
            int next_line_start = line_start + 1;
            if (line_start != next_line_start){
                ArrayList<Integer> new_line = new ArrayList<>();
                new_line.add(line_start);
                new_line.add(next_line_start);
            }
        }
        return (ret);
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int lineSegmentsRows = Integer.parseInt(bufferedReader.readLine().trim());
        int lineSegmentsColumns = Integer.parseInt(bufferedReader.readLine().trim());

        List<List<Integer>> lineSegments = new ArrayList<>();

        IntStream.range(0, lineSegmentsRows).forEach(i -> {
            try {
                lineSegments.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        List<List<Integer>> result = Result.getMergedLineSegments(lineSegments);

        result.stream()
            .map(
                r -> r.stream()
                    .map(Object::toString)
                    .collect(joining(" "))
            )
            .map(r -> r + "\n")
            .collect(toList())
            .forEach(e -> {
                try {
                    bufferedWriter.write(e);
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }
            });

        bufferedReader.close();
        bufferedWriter.close();
    }
}
