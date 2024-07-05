#include <iostream>
#include <string>
#include "entities.h"
#include "PlayGame.h"
using namespace std;

int main() {
    entities* ent = entities :: get_instance();

    int n_snakes, n_ladders, n_players;

    cin>>n_snakes;
    while(n_snakes-- > 0){
        int start, end;
        cin>>start>>end;
        (*ent).set_snakes(start, end);
    }

    cin>>n_ladders;
    while(n_ladders-->0){
        int start, end;
        cin>>start>>end;
        (*ent).set_ladders(start, end);
    }

    cin>>n_players;
    int i=1;
    while(n_players-->0){
        string player;
        cin>>player;
        (*ent).set_player(i++, player);
    }

    PlayGame play;
    cout<<play.play()<<" wins the game."<<endl;
    return 0;
}
