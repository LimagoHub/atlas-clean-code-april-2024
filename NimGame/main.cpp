#include <iostream>
#include "client/GameClient.h"
#include "game/nim/NimGame.h"
#include "game/nim/player/ComputerPlayer.h"
#include "game/nim/player/HumanPlayer.h"
#include "io/ConsoleWriter.h"


using namespace atlas::clients;
using namespace atlas::games;
using namespace atlas::games::player;
int main() {
    atlas::io::ConsoleWriter consoleWriter;
    HumanPlayer human {"Human"};
    ComputerPlayer computer{"HAL"};
    NimGame game(consoleWriter);
    game.addPlayer(&human);
    game.addPlayer(&computer);

    GameClient client(game);
    client.run();
    return 0;
}
