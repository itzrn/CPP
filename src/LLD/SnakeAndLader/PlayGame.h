#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <iostream>
#include <unordered_map>
#include <string>
#include "dice.h"
#include "entities.h"
using namespace std;


class PlayGame{

    private:
        unordered_map<string, int> player_latest_position;
        entities* ent;
        dice* dice_;

    public:
        PlayGame(){
            player_latest_position.clear();
            ent = entities::get_instance();
            dice_ = new dice();
        }

        void initialize_player_start_value(){
            for(auto i:(*ent).get_players()){
                player_latest_position[i.second]=0;
            }
        }

        bool is_player_won(string& player){
            return player_latest_position[player]==100;
        }


        string play(){
            initialize_player_start_value();

            int i_player=0;

            do{
                i_player++; // ith player playing
                if(i_player>(*ent).get_players().size()){ // when the number of players getting increase then turing the turn to player 1
                    i_player=1;
                }

                string& player_name = (*ent).get_players()[i_player]; // name of the player which have the current turn
                cout << player_name;

                int dice_value = (*dice_).get_dice_value();

                int end_pos = player_latest_position[player_name]+dice_value;

                string sl="";
                if(end_pos <= 100){
                    cout << " rolled a " << dice_value<<" ans moved from "<<player_latest_position[player_name];
                    if((*ent).get_snakes().find(end_pos) != end((*ent).get_snakes())){
                        sl = " after Snake bite";

                        player_latest_position[player_name] = (*ent).get_snakes()[end_pos];
                    }else{
                        if((*ent).get_ladders().find(end_pos) != end((*ent).get_ladders())){
                            sl = " after Ladder climb";
                            player_latest_position[player_name] = (*ent).get_ladders()[end_pos];
                        }else{
                            player_latest_position[player_name] = end_pos;
                        }
                    } 
                }
                cout << " to " << player_latest_position[player_name];
                cout<<sl<<endl;

            }while(!is_player_won((*ent).get_players()[i_player]));

            return (*ent).get_players()[i_player];
        }
};



#endif