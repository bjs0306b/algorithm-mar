import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int G = sc.nextInt();

        long low = 1;
        long high = 2;
        boolean found = false;
        StringBuilder sb = new StringBuilder();

        while (true) {
            long diff = high * high - low * low;

            if (high - low == 1 && diff > G) break;

            if (diff == G) {
                sb.append(high).append("\n");
                found = true;
                high++;
            } else if (diff < G) {
                high++;
            } else {
                low++;
            }
        }

        if (!found) {
            System.out.println("-1");
        } else {
            System.out.print(sb.toString());
        }
    }
}