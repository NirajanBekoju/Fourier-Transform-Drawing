#include "Draw.hpp"

int main()
{
    std::string fileName = "csv/nirajan.csv";
    bool canvas = false;
    Draw d;
    if (canvas)
    {
        d.initCanvasMethod();
    }
    else{
        d.initImageMethod(fileName);
    }
    d.initFourierDrawingWindow();
    d.FourierDrawing();
    return 0;
}