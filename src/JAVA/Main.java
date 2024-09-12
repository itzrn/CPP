import java.util.*;
// import SnakesAndLadder.PlayGame;

/**
 * Main
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Board board = Board.getInstance(); // this is the way to call the static function of another class without making any object

        int n_snake=sc.nextInt();
        while(n_snake-->0){
            board.getSnake().put(sc.nextInt(), sc.nextInt());
        }

        int n_ladder=sc.nextInt();
        while (n_ladder-->0) {
            board.getLadder().put(sc.nextInt(), sc.nextInt());
        }

        int n_player=sc.nextInt();
        int i=1;
        while (n_player-->0) {
            board.getPlayer().put(i, sc.next());
            i++;
        }

        PlayGame playGame = new PlayGame();
        System.out.println("Winner -> "+  playGame.play());
        sc.close();
    }
}