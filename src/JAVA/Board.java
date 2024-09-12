import java.util.HashMap;
import java.util.Map;

/**
 * Dice
 */
public class Board {

    // private static final int boardSize = 100;

    private static Map<Integer, Integer> snake;
    private static Map<Integer, Integer> ladder;
    private static Map<Integer, String> player;
    static Board instance;

    public Board(){
        snake = new HashMap<>();
        ladder = new HashMap<>();
        player= new HashMap<>();
        instance = null;
    }

    public void setSnake(int start, int end){
        snake.put(start, end);
    }

    public void setLadder(int start, int end){
        ladder.put(start, end);
    }

    public Map<Integer, Integer> getSnake(){
        return snake;
    }

    public Map<Integer, Integer> getLadder(){
        return ladder;
    }

    public void setPlayer(int i, String name){
        player.put(i, name);
    }

    public Map<Integer, String> getPlayer(){
        return player;
    }

    public static Board getInstance(){
        if(instance == null){
            instance = new Board();
        }
        return instance;
    }
}