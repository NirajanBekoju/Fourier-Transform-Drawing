#pragma once

#include "Fourier.hpp"
#include "Complex.hpp"
#include "SFML/Graphics.hpp"

class Draw {
// Main objective of this class is to
// Draw the epicycles based on the result of DFT algorithm :- epicycles();
// Draw the path
private:
    Fourier f;
    double time = 0;
    // These two variables is for SFML window and events; 
    sf::RenderWindow *FourierDrawingWindow;
    sf::Event evnt;
    // path variable contains the (x, y) coordinate of the path of the object to be traced
    std::vector <std::vector <double>> path;
public:
    Draw();
    ~Draw();
    // To initialize the image method
    void initImageMethod(std::string);
    // To initialize the Canvas method
    void initCanvasMethod();
    // To initialize the drawing window
    void initFourierDrawingWindow();
    // To draw the epicycles
    std::vector <double> epicyles(double, double, double);
    // To make the Fourier Transform Drawing
    // This function make call to epicycles function to draw epicycles
    void FourierDrawing();
};