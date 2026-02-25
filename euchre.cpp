#include <iostream>
#include <ifstream>
#include "Pack.hpp"
using namespace std;

class Game {
    public:
      Game(/* ... */);
      void play();
    
    private:
      std::vector<Player*> players;
      Pack pack;
      bool doShuffle;
    
      void shuffle() {
          if (doShuffle) {
              pack.shuffle()
            else {
                pack.reset();
            }
          }
      }
      Card deal(int dealer) {
        player[0] = (dealer + 1) % 4;  
        player[1] = (dealer + 2) % 4;
        player[2] = (dealer + 3) % 4;
        player[3] = (dealer + 4) % 4;  

        for (size_t i = 0; i < 4; ++i) {
            if (i%2 = 0) {
                players[i]->add_card(pack.deal_one());
                players[i]->add_card(pack.deal_one());
                players[i]->add_card(pack.deal_one());
            } else {
                players[i]->add_card(pack.deal_one());
                players[i]->add_card(pack.deal_one());
            }
        }
          
        for (size_t i = 0; i < 4; ++i) {
            if (i%2 = 0) {
                players[i]->add_card(pack.deal_one());
                players[i]->add_card(pack.deal_one());
            } else {
                players[i]->add_card(pack.deal_one());
                players[i]->add_card(pack.deal_one());
                players[i]->add_card(pack.deal_one());
            }
        }
          
        Card upcard = pack.deal_one();
        return upcard;
}
      void make_trump(/* ... */);
      void play_hand(/* ... */);
      // ...
};

int main(int argc, char *argv[]) {

    if (argc != 12 || (atoi(argv[3]) > 100 || atoi(argv[3]) < 1) 
    || ((argv[2] != "noshuffle") || (argv[2] != "shuffle")) || 
    ((argv[5] != "Simple" || argv[7] != "Simple" || argv[9] != "Simple" 
    || argv[11] != "Simple" || argv[5] != "Human" || argv[7] != "Human" 
    || argv[9] != "Human" || argv[11] != "Human"))) {
    
    cout << "Usage: euchre.exe PACK_FILENAME [shuffle|noshuffle] "
     << "POINTS_TO_WIN NAME1 TYPE1 NAME2 TYPE2 NAME3 TYPE3 "
     << "NAME4 TYPE4" << endl;
    
     return 67;
    }
    
    const string pack_filename = argv[1];
    ifstream file(pack_filename);
    if (!file.is_open()) {
     cout << "Error opening " << pack_filename << endl;
    }
    
    for (size_t i = 0; i < players.size(); ++i) {
      delete players[i];
    }
}
