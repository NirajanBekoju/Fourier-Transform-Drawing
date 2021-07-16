#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <stdexcept>  // std::runtime_error
#include "Complex.hpp"
#include <utility>
#include "SFML/Graphics.hpp"

class Fourier {
// Main objective of this class is
// 1. Image Way
// Read the coordinate from csv file :- read_coordinate_from_file(std::string filename);
// Apply DFT Algoritms and setthe result to dft_res :- dft();
// Sort the dft_res on the basis of amplitude in descending order :- getSortedRes();

// 2. Canvas Method
// Make a window canvas and draw something in the canvas by dragging mouse.
// Get the coordinate of the drawing in canvas and assign it to coordinate_shape;
// Apply DFT Algoritms and setthe result to dft_res :- dft();
// Sort the dft_res on the basis of amplitude in descending order :- getSortedRes();

private:
    // vector of complex numbers
    std::vector<Complex> coordinate_shape;
    // result of the DFT = [[real, imaginary, frequency, amplitude, phase]]
    std::vector <std::vector <double>> dft_res; 

    // Variables for Canvas
    std::vector<double>x;
    std::vector<double>y;
    std::vector<sf::VertexArray> vertices;
    int lines_number = 0; 
    int condition = false; 
    sf::Color pencolor = sf::Color::White;

    sf::RenderWindow *CanvasWindow;
    sf::Event event_canvas;

public:
    Fourier();
    ~Fourier();
    void read_coordinate_from_file(std::string filename);
    void show_coordinate();
    void dft();
    void show_dft_res();
    std::vector <std::vector <double>> getDFTRes();
    void getSortedRes();

    // Functions for Canvas
    void initCanvasDrawing();
};