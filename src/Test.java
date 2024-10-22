import java.util.Scanner;

public class ClockAngle {

    public static double calculateAngle(int hour, int minute, int second) {
        if (hour >= 12) {
            hour -= 12;
        }

        double hour_angle = (hour * 30) + (minute * 0.5) + (second * (0.5 / 60));
        double minute_angle = (minute * 6) + (second * 0.1);
        double angle = Math.abs(hour_angle - minute_angle);
        if (angle > 180) {
            angle = 360 - angle;
        }
        return angle;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter hour: ");
        int hour = sc.nextInt();

        System.out.print("Enter minute: ");
        int minute = sc.nextInt();

        System.out.print("Enter second: ");
        int second = sc.nextInt();

        double angle = calculateAngle(hour, minute, second);
        System.out.println("The angle between the hour and minute hand is: " + angle + " degrees.");
    }
}
