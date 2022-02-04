#ifndef game_h
#define game_h
#include <string>
#include "board.h"


class Game
{
public:
    Game(int width, int height, int fps, std::string title);
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    ~Game() noexcept;

    bool GameShouldClose() const;

    void Tick();

private:
    void Draw();
    void Update();

    Board board;
};

#endif