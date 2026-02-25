#include <iostream>
#include <ifstream>
using namespace std;

class Game {
    public:
      Game(/* ... */);
      void play();
    
    private:
      std::vector<Player*> players;
      Pack pack;
      // ...
    
      void shuffle() {
          
      }
      void deal(/* ... */);
      void make_trump(/* ... */);
      void play_hand(/* ... */);
      // ...
};

int main(int argc, char *argv[]) {

    if (argc != 12 || (atoi(argv[3]) > 100 || atoi(argv[3]) < 1) 
    || ((argv[3] != "noshuffle") || (argv[3] != "shuffle")) || 
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
