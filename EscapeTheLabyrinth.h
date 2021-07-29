// EscapeTheLabyrinth file 
// Checks wether the path is correct or no 
#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

const string kYourName = "Nikita Mashchenko";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "EWSSESENENNSSWNN";
const string kPathOutOfTwistyMaze = "SWSENEESNNWN";
// the function is used to check word for incorrect symbols
bool checkWord(const string& moves_)
{
     for (size_t i = 0; i < moves_.size(); i++) {
         if(moves_[i] != 'E' && moves_[i] != 'W' 
         && moves_[i] != 'N' && moves_[i] != 'S')
         {
             return false;
         }
}
         return true;
}
//this function checks if there is something inside 
// the current node
void checkItem(MazeCell *cur_, int &spellbook_, int &potion_, int& wand_) {
        if (cur_ -> whatsHere == "Spellbook") {
       spellbook_++;
      } else if (cur_ -> whatsHere == "Potion") {
          potion_++;
        } else if (cur_ -> whatsHere == "Wand") {
            wand_++;
          }
}
// checks the first node for S,P or W
bool checkFirst(const string& moves, MazeCell *start_,
int &spellbook, int &potion, int& wand) {
    if(!checkWord(moves)) {
        return false;
    }
    
    if (start_ -> whatsHere == "Spellbook") {
       spellbook++;
      } else if (start_ -> whatsHere == "Potion") {
          potion++;
        } else if (start_ -> whatsHere == "Wand") {
            wand++;
          }
          return true;
}
// checks the path to freedom and if it's right
bool isPathToFreedom(MazeCell *start, const string& moves) {
    int spellbook = 0, potion = 0, wand = 0;
    checkFirst(moves, start, spellbook, potion, wand);
    MazeCell* cur = start;
    for (size_t i = 0; i < moves.size(); i++) {
  if (moves[i] == 'N') {
    if (cur -> north != nullptr) {
      cur = cur -> north;
    }
        checkItem(cur, spellbook, potion, wand);
        }
        else if (moves[i] == 'S') {
          if (cur -> south != nullptr) {
            cur = cur -> south;
          }
               checkItem(cur, spellbook, potion, wand);
              }
              else if (moves[i] == 'E') {
                if (cur -> east != nullptr) {
                  cur = cur -> east;
                }
                    checkItem(cur, spellbook, potion, wand);
                    }
                    else if (moves[i] == 'W') {
                      if (cur -> west != nullptr) {
                        cur = cur -> west;
                      }
                        checkItem(cur, spellbook, potion, wand);
                          } else {
                            return false;
                          }
                if(spellbook >= 1 && potion >= 1 && wand >= 1) {
                if(checkWord(moves))
                return true;
            }
    }
    return false;
}
