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
      Suit make_trump(const Card &upcard, int dealer, int &maker_idx) {
        Suit order_up_suit;

        for (int i = 1; i <= 4; ++i) {
            int player_idx = (dealer + i) % 4;
            bool is_dealer = (player_idx == dealer);
    
            if (players[player_idx]->make_trump(upcard, is_dealer, 1, order_up_suit)) {
                cout << *players[player_idx] << " orders up " << order_up_suit << endl;
                players[dealer]->add_and_discard(upcard);
                cout << endl;
                maker_idx = player_idx;
                return order_up_suit;
            } else {
                cout << *players[player_idx] << " passes" << endl;
            }
        }
    
        for (int i = 1; i <= 4; ++i) {
            int player_idx = (dealer + i) % 4;
            bool is_dealer = (player_idx == dealer);
    
            if (players[player_idx]->make_trump(upcard, is_dealer, 2, order_up_suit)) {
                cout << *players[player_idx] << " orders up " << order_up_suit << endl;
                cout << endl;
                maker_idx = player_idx;
                return order_up_suit;
            } else {
                cout << *players[player_idx] << " passes" << endl;
            }
        }
    }
      void play_tricks(int dealer, Suit trump, int maker_idx,
                 int &tricks02, int &tricks13) {
    
        int leader = (dealer + 1) % 4;
    
        for (int trick = 0; trick < 5; ++trick) {
    
            Card led_card = players[leader]->lead_card(trump);
            cout << led_card << " led by " << *players[leader] << endl;
    
            Card winning_card = led_card;
            int winning_player = leader;
    
            for (int i = 1; i < 4; ++i) {
                int player_idx = (leader + i) % 4;
                Card played = players[player_idx]->play_card(led_card, trump);
                cout << played << " played by " << *players[player_idx] << endl;
    
                if (Card_less(winning_card, played, led_card, trump)) {
                    winning_card = played;
                    winning_player = player_idx;
                }
            }
    
            cout << *players[winning_player] << " takes the trick" << endl;
            cout << endl;
    
            if (winning_player == 0 || winning_player == 2) {
                tricks02++;
            } else {
                tricks13++;
            }
    
            leader = winning_player;
        }
    }
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
