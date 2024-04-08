#include <iostream>
#include "client/GameClient.h"
#include "game/nim/NimGame.h"

using namespace atlas::clients;
using namespace atlas::games;
int main() {
    NimGame game;
    GameClient client(game);
    client.run();
    return 0;
}
