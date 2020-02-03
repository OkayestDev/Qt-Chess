#include <list>
#include "./move.h"
#include "./tile.h"

using namespace std;

class MoveHistory
{
private:
    list<Move> moves;
    list<Move>::iterator index;

public:
    MoveHistory();
    void addMove(Tile *, Tile *);
    QString listToString();
};