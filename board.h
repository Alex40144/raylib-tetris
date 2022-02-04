#ifndef board_h
#define board_h
#include "raylibWrapper.h"
#include <vector>
#include "Vec2.h"
class Board
{
private:
    class Cell
    {
        public:
            Cell();
            void SetColor(Color NewColor);
            void Remove();
            Color GetColor() const;
        private:
            bool bExists;
            Color color;
    };
public:
    Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellSize, int padding);
    void SetCell(Vec2<int> pos, Color color);
    void DrawCell(Vec2<int> pos) const;
    void DrawBorder() const;
    void Draw() const;
private:
    std::vector<Cell> cells;
    Vec2<int> screenPos;
    const int width;
    const int height;
    const int cellSize;
    const int padding;
};
#endif