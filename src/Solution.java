import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {
    public static List<String> parseIPHeader() {
        Scanner sc = new Scanner(System.in);

        // Input number of lines
        int n = sc.nextInt();
        sc.nextLine();

        String[] arr = new String[n];
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLine();
        }
        if (arr[0].length() >= 32) {
            String version = arr[0].substring(0, 4);
            String protocol = arr[0].substring(4, 12);
            String ttl = arr[0].substring(12, 20); // TTL (bits 13 to 20)
            String packetLength = arr[0].substring(20, 32); // Packet length (bits 21 to 31

            String line1 = Integer.parseInt(version, 2) + "," +
                    (Integer.parseInt(protocol, 2) == 6 ? "TCP" : "UDP") + "," +
                    Integer.parseInt(ttl, 2) + "," +
                    Integer.parseInt(packetLength, 2);

            ans.add(line1);
        } else {
            ans.add("Invalid input");
            return ans;
        }
        if (arr[1].length() == 32) {
            String s2p1 = arr[1].substring(0, 8); // First octet (bits 0 to 7)
            String s2p2 = arr[1].substring(8, 16); // Second octet (bits 8 to 15)
            String s2p3 = arr[1].substring(16, 24); // Third octet (bits 16 to 23)
            String s2p4 = arr[1].substring(24, 32); // Fourth octet (bits 24 to 31)

            String line2 = Integer.parseInt(s2p1, 2) + "." +
                    Integer.parseInt(s2p2, 2) + "." +
                    Integer.parseInt(s2p3, 2) + "." +
                    Integer.parseInt(s2p4, 2);

            ans.add(line2); // Add to the result list
        } else {
            ans.add("Invalid input");
            return ans;
        }
        if (arr[2].length() == 32) {
            String s3p1 = arr[2].substring(0, 8); // First octet (bits 0 to 7)
            String s3p2 = arr[2].substring(8, 16); // Second octet (bits 8 to 15)
            String s3p3 = arr[2].substring(16, 24); // Third octet (bits 16 to 23)
            String s3p4 = arr[2].substring(24, 32); // Fourth octet (bits 24 to 31)

            String line3 = Integer.parseInt(s3p1, 2) + "." +
                    Integer.parseInt(s3p2, 2) + "." +
                    Integer.parseInt(s3p3, 2) + "." +
                    Integer.parseInt(s3p4, 2);

            ans.add(line3); // Add to the result list
        } else {
            ans.add("Invalid input");
        }
        return ans; // Return the result list
    }

    public static void main(String[] args) {
        List<String> result = parseIPHeader();
        for (String line : result) {
            System.out.println(line);
        }
    }
}