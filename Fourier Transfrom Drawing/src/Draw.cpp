#include "Draw.hpp"

Draw::Draw()
{

}

Draw::~Draw()
{
}

void Draw::initFourierDrawingWindow()
{
    this->FourierDrawingWindow = new sf::RenderWindow(sf::VideoMode(1300, 700), "Fourier Drawing");
}

void Draw::initImageMethod(std::string fileName){
    f.read_coordinate_from_file(fileName);
    f.dft();
    f.getSortedRes();
}

void Draw::initCanvasMethod(){
    f.initCanvasDrawing();
    f.dft();
    f.getSortedRes();
}

std::vector<double> Draw::epicyles(double x = 400, double y = 400, double rotation = 0)
{
    std::vector<std::vector<double>> fourier = f.getDFTRes();
    std::vector<double> vec;
    for (long unsigned int i = 0; i < fourier.size(); i++)
    {
        double prev_x = x;
        double prev_y = y;
        double freq = fourier[i][2];
        double radius = fourier[i][3];
        double phase = fourier[i][4];
        x += radius * cos(freq * time + phase + rotation);
        y += radius * sin(freq * time + phase + rotation);

        // Draw the epicycle
        sf::CircleShape ci(radius);
        ci.setPointCount(50);
        ci.setPosition(prev_x - radius, prev_y - radius);
        ci.setFillColor(sf::Color::Transparent);
        ci.setOutlineThickness(1);
        ci.setOutlineColor(sf::Color(0, 209, 209, 127));
        this->FourierDrawingWindow->draw(ci);

        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(prev_x, prev_y), sf::Color(255, 255, 255, 127)),
            sf::Vertex(sf::Vector2f(x, y), sf::Color(255, 255, 255, 127))};
        this->FourierDrawingWindow->draw(line, 2, sf::Lines);
        // End of drawing epicycle
    }
    vec.push_back(x);
    vec.push_back(y);
    return vec;
}

void Draw::FourierDrawing()
{
    while (this->FourierDrawingWindow->isOpen())
    {
        while (FourierDrawingWindow->pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                FourierDrawingWindow->close();
                break;
            default:
                break;
            }
        }
        this->FourierDrawingWindow->clear();

        std::vector<double> v = epicyles(FourierDrawingWindow->getSize().x / 2, FourierDrawingWindow->getSize().y / 2, 0);

        // Unshift the vector
        std::vector<std::vector<double>>::iterator iter = this->path.begin();
        path.insert(iter, v);

        // Begin the shape of the path
        for (long unsigned int i = 0; i < path.size() - 1; i++)
        {
            sf::Vertex line[] = 
            {
                sf::Vertex(sf::Vector2f(path[i][0], path[i][1]), sf::Color::Yellow),
                sf::Vertex(sf::Vector2f(path[i + 1][0], path[i + 1][1]), sf::Color::Yellow)
            };
            this->FourierDrawingWindow->draw(line, 2, sf::Lines);
        }
        // End the shape of the path

        double dt = 2 * M_PI / f.getDFTRes().size();
        this->time += dt;

        if (time > 2 * M_PI)
        {
            this->time = 0;
            this->path.erase(this->path.begin(), this->path.end());
        }

        this->FourierDrawingWindow->display();
    }
}
