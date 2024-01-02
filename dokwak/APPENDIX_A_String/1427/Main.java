import java.util.*;
import java.io.*;

public class Main{


public class BeehiveSnail {

    public static int[] fillBeehive(int n) {
        int size = 1 + 6 * (n * (n - 1) / 2); // Total number of hexagons
        int[] result = new int[size];

        int value = 1; // Starting value
        int layer = 0; // Current layer

        while (value <= size) {
            // Fill the hexagons in the current layer
            for (int i = 0; i < 6 * layer && value <= size; i++) {
                result[value - 1] = value++;
            }

            layer++;
        }

        return result;
    }

    public static void main(String[] args) {
        int n = 2;
        int[] result = fillBeehive(n);

        // Print the result
        System.out.println(Arrays.toString(result));
    }
}
}



