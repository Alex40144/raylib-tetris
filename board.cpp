#include "board.h"
#include <assert.h>
Board::Cell::Cell()
    :bExists(false),
    color(WHITE)
{

}

void Board::Cell::SetColor(Color Newcolor){
    color = Newcolor;
    bExists = true;
}

void Board::Cell::Remove(){
    bExists = false;
}

Color Board::Cell::GetColor() const {
    return color;
}

Board::Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellSize, int padding)
    :
    screenPos(screenPos),
    width(widthHeight.GetX()),
    height(widthHeight.GetY()),
    cellSize(cellSize),
    padding(padding)
{
    assert(width > 0 && height > 0); //width or height smaller than one
    assert(cellSize > 0); //cell size less than one
    cells.resize(width * height);
}

void Board::SetCell(Vec2<int> pos, Color color){
    assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < width && pos.GetY() < height); //x or y out of bounds
    cells[(width * pos.GetY()) + pos.GetX()].SetColor(color);
}

void Board::DrawCell(Vec2<int> pos) const{
    assert(pos.GetX() >= 0 && pos.GetX() < width && pos.GetY() >= 0 && pos.GetY() < height); //x or y is out of bounds
    Color color = cells[(width * pos.GetY()) + pos.GetX()].GetColor();
    Vec2<int> topLeft = screenPos + padding + (pos * cellSize);
    raylibWrapper::DrawRectangle(topLeft, Vec2<int>{cellSize, cellSize} - padding, color);
}

void Board::Draw() const {
    for(int iY = 0; iY < height; ++iY){
        for(int iX = 0; iX < width; ++iX){
            DrawCell(Vec2<int>{iX, iY});
        }
    }
    DrawBorder();
}

void Board::DrawBorder() const {
    raylibWrapper::DrawRectangleLinesEx(screenPos-(cellSize/2),
        Vec2{width * cellSize,
        height * cellSize} + cellSize,
        cellSize/2,
        WHITE);
}