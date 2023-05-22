#include "Core/GameLoop.h"
int main() {

    GameLoop Game;
    while(!Game.GetWindow()->IsDone()) {
        // Game loop stuff :D
        //Game.HandleInput();
        Game.Update();
        Game.Render();
        Game.RestartClock();
    }
    return 0;
}
