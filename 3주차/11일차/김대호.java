import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String X = br.readLine();
        int N = X.length();

        int[][] dp = new int[3][3];

        for (int i = 0; i < N; i++) {
            char c = X.charAt(i);
            int charVal = (c == 'K') ? 0 : (c == 'S' ? 1 : 2);

            for (int p = 0; p < 3; p++) {
                if (charVal == p && dp[p][charVal] == 0) {
                    dp[p][charVal] = 1;
                }
                
                int prevCharVal = (charVal + 2) % 3;
                if (dp[p][prevCharVal] > 0) {
                    dp[p][charVal] = Math.max(dp[p][charVal], dp[p][prevCharVal] + 1);
                }
            }
        }

        int maxL = 0;
        for (int p = 0; p < 3; p++) {
            int startIndexInT = p + 1;
            
            if (startIndexInT <= N) {
                int L = 0;
                for (int v = 0; v < 3; v++) {
                    L = Math.max(L, dp[p][v]);
                }
                L = Math.min(L, N - startIndexInT + 1);
                maxL = Math.max(maxL, L);
            }
        }

        System.out.println(2L * (N - maxL));
    }
}