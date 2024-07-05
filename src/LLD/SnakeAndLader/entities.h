#ifndef ENTITIES_H
#define ENTITIES_H

#include <unordered_map>
#include <string>
using namespace std;

class entities{
    private:
        static unordered_map<int, int> snakes;
        static unordered_map<int, int> ladders;
        static unordered_map<int, string> players;
        static entities* instance;

        // making constructor to be private, to make singleton pattern
        /**
         * Key Characteristics of Singleton Pattern
            Single Instance: It ensures that only one instance of the class is created.
            Global Access: It provides a global point of access to the instance.
            Lazy Initialization: The instance is created only when it is first requested.

         * Components of Singleton Pattern
            Private Static Instance: A static variable to hold the single instance of the class.
            Private Constructor: The constructor is private to prevent direct instantiation.
            Public Static Method: A static method that provides access to the instance.
         */
        entities(){ // doing all the make clear to ensure that the not be any value present in map
            snakes.clear();
            ladders.clear();
            players.clear();
        }

    public:
        void set_snakes(int start, int end){
            snakes[start]=end;
        }

        unordered_map<int, int>& get_snakes(){
            return snakes;
        }

        void set_ladders(int start, int end) {
            ladders[start] = end;
        }

        unordered_map<int, int>& get_ladders(){
            return ladders;
        }

        void set_player(int i, const string& player){
            players[i]=player;
        }

        unordered_map<int, string>& get_players(){
            return players;
        }

        static entities* get_instance(){
            if(!instance){
                instance = new entities();
            }
            return instance;
        }
};

entities* entities :: instance=NULL;
unordered_map<int, int> entities::snakes;
unordered_map<int, int> entities::ladders;
unordered_map<int, string> entities::players;
#endif