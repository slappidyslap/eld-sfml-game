#include "logger.h"
#include "tostring.h"
#include "Game.h"

int main()
{
    Game game;
    dgrdch::logInfo("App started");
    while (!game.GetWindow()->IsDone())
    {
        game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock();
    }
    dgrdch::logInfo("App closed");
}
