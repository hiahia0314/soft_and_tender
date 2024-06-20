import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    boolean isSubsetSum(int[] set, int target) {
        if (set.length == 1) {
            return target == set[0];
        } else {
            int[] subset = new int[set.length - 1];
            for (int i = 1; i < set.length; i++) {
                subset[i - 1] = set[i];
            }
            return isSubsetSum(subset, target) || isSubsetSum(subset, target - set[0]);
        }
    }

    public static void main(String[] args) {
        int[] set = {3, 34, 2, 12, 5, 2};
        int target = 9;
        System.out.println(new Main().isSubsetSum(set, target));
    }

}



