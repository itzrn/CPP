import java.util.HashMap;
import java.util.Map;

public class PlayGame {
    Map<String, Integer> player_latest_position;
    Board board;
    Dice dice;
    int nplayer;

    PlayGame(){
        player_latest_position = new HashMap<>();
        board = Board.getInstance();
        dice = new Dice();
        nplayer = board.getPlayer().size();
    }

    void initialize_player_start_value(){
        for(String str : board.getPlayer().values()){
            player_latest_position.put(str, 0);
        }
    }

    boolean is_player_won(String player){
        return player_latest_position.get(player)==100;
    }

    public String play(){
        initialize_player_start_value();

        int i_player=0;

        do{
            i_player++;
            if(i_player>nplayer){
                i_player=1;
            }

            String player = board.getPlayer().get(i_player);
            System.out.print(player);

            int dice_value = dice.roll();

            int end_pos = dice_value + player_latest_position.get(i_player);

            String s1="";

            if(end_pos <= 100){
                System.out.println(" rolled a "+dice_value+" and moved from "+player_latest_position.get(player));

                if(board.getSnake().getOrDefault(end_pos, -1) != -1){
                    s1 = " after snake bite";
                    player_latest_position.put(player, board.getSnake().get(end_pos));
                }else{
                    if(board.getLadder().getOrDefault(end_pos, -1) != -1){
                        s1 = " after ladder climb";
                        player_latest_position.put(player, board.getLadder().get(end_pos));
                    }else{
                        player_latest_position.put(player, end_pos);
                    }
                }
            }

            System.out.println("to "+player_latest_position.get(player)+s1);
        }while(player_latest_position.get(board.getPlayer().get(i_player)) != 100);

        return board.getPlayer().get(i_player);
    }
}