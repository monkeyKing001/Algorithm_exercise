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
     * Complete the 'calculateScore' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING text
     *  2. STRING prefixString
     *  3. STRING suffixString
     */

    public static String calculateScore(String text, String prefixString, String suffixString) {
    // Write your code here
        int [][]dp1 = new int [text.length() + 1][prefixString.length() + 1];
        int [][]dp2 = new int [text.length() + 1][suffixString.length() + 1];
        StringBuilder ret = new StringBuilder();
        StringBuilder pre = new StringBuilder();
        StringBuilder sub = new StringBuilder();
        for (int i = 0; i < dp1.length; i++) {
            for (int j = 0; j < dp1[i].length; j++) {
                dp1[i][j] = 0;
            }
        }
        for (int i = 0; i < dp2.length; i++) {
            for (int j = 0; j < dp2[i].length; j++) {
                dp2[i][j] = 0;
            }
        }
        //System.out.println("text : " + text);
        //System.out.println("prefix : " + prefixString);
        //System.out.println("suffix : " + suffixString);
        
        
        //substring index
        int sub_start_pre = 0;
        int sub_end_pre = 0;
        //prefix
        int preSco = 0;
        int start_pre = 0;
        String temp_pre = ret.toString();
        while (start_pre < text.length())
        {
            //System.out.println("checking : " + start_pre + " : " + text.charAt(start_pre));
            if (text.charAt(start_pre) == prefixString.charAt(prefixString.length() - 1))
            {
                //System.out.println("subchecking start");
                int offset = 0;
                while (start_pre - offset > - 1 && offset < prefixString.length())
                {
                    if (text.charAt(start_pre - offset) == prefixString.charAt(prefixString.length() - 1 - offset))
                        offset++;
                    else
                        break ;
                }
                if (offset > preSco)
                {
                    preSco = offset;
                    sub_start_pre = start_pre - offset + 1;
                    sub_end_pre = start_pre;
                    //System.out.println("start, end : " + sub_start_pre + ", " + sub_end_pre);
                    temp_pre = text.substring(sub_start_pre, sub_end_pre + 1);
                }
            }
            start_pre++;
        }
        //System.out.println("pre: " + temp_pre);
        //substring index
        int sub_start_suf = 0;
        int sub_end_suf = 0;
        //prefix
        int sufSco = 0;
        int start_suf = 0;
        String temp_suf = ret.toString();
        while (start_suf < text.length())
        {
            if (text.charAt(start_suf) == suffixString.charAt(0))
            {
                int offset = 0;
                while (start_suf + offset < text.length() && offset < suffixString.length())
                {
                    if (text.charAt(start_suf + offset) == suffixString.charAt(offset))
                        offset++;
                    else
                        break ;
                }
                if (offset >= sufSco)
                {
                    sufSco = offset;
                    sub_start_suf = start_suf;
                    sub_end_suf = start_suf + offset - 1;
                    //System.out.println("start, end : " + sub_start_suf + ", " + sub_end_suf);
                    temp_suf = text.substring(sub_start_suf, sub_end_suf + 1);
                }
            }
            start_suf++;
        }
        //System.out.println("suf : " + temp_suf);
        //normal case
        int start = 0;
        int end = Integer.max(sub_end_pre, sub_end_suf);
        if (sub_start_pre <= sub_start_suf)
        {
            if (preSco == 0)
            {
                start = sub_start_suf;
                end = sub_end_suf;
            }
            else
            {
                start = sub_start_pre;
                end = Integer.max(sub_end_pre, sub_end_suf);
            }
        }
        else if (sub_start_pre > sub_start_suf)
        {
            if (sufSco > preSco)
            {
                start = sub_start_suf;
                end  = sub_start_suf;
            }
            else if (sufSco < preSco)
            {
                start = sub_start_pre;
                end  = sub_end_pre;
            }
            else
            {
                String pre_temp = text.substring(sub_start_pre, sub_end_pre + 1);
                String suf_temp = text.substring(sub_start_suf, sub_end_suf + 1);
                //System.out.println("pre_temp : " + pre_temp);
                //System.out.println("suf_temp : " + suf_temp);
                if (pre_temp.compareTo(suf_temp) < 0)
                    return (pre_temp);
                else
                    return (suf_temp);
            }
        }
            
        //no overlap
        return(text.substring(start, end + 1));
        //overlap
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String text = bufferedReader.readLine();

        String prefixString = bufferedReader.readLine();

        String suffixString = bufferedReader.readLine();

        String result = Result.calculateScore(text, prefixString, suffixString);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}

