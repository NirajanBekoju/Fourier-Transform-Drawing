#include "Fourier.hpp"

Fourier::Fourier()
{
}

Fourier::~Fourier()
{
}

void Fourier::read_coordinate_from_file(std::string filename)
{
    // Create an input filestream
    std::ifstream coordinateFile(filename);

    // Create an input filestream
    if (!coordinateFile.is_open())
        throw std::runtime_error("Could not open the file");

    std::string line;
    std::getline(coordinateFile, line);
    while (std::getline(coordinateFile, line))
    {
        std::size_t pos = line.find(",");

        std::string x = line.substr(0, pos);
        int real = std::stoi(x);
        std::string y = line.substr(pos + 1, line.length() - pos - 2);
        int imaginary = std::stoi(y);

        Complex c(real, imaginary);
        this->coordinate_shape.push_back(c);
    }
}

void Fourier::show_coordinate()
{
    for (long unsigned int i = 0; i < this->coordinate_shape.size(); i++)
    {
        std::cout << coordinate_shape[i];
    }
}

void Fourier::dft()
{
    std::vector<double> dft_coor;

    int N = this->coordinate_shape.size();
    for (int k = 0; k < N; k++)
    {
        Complex sum(0, 0);
        for (int n = 0; n < N; n++)
        {
            double phi = (2 * M_PI * k * n) / N;
            Complex c(cos(phi), -sin(phi));
            Complex res = this->coordinate_shape[n] * c;
            sum = sum + res;
        }

        double real = sum.getReal() / N;
        double imaginary = sum.getImaginary() / N;
        Complex c(real, imaginary);
        double freq = k;
        double amplitude = c.amplitude();
        double phase = atan2(imaginary, real);

        dft_coor.push_back(real);
        dft_coor.push_back(imaginary);
        dft_coor.push_back(freq);
        dft_coor.push_back(amplitude);
        dft_coor.push_back(phase);

        dft_res.push_back(dft_coor);
        dft_coor.erase(dft_coor.begin(), dft_coor.end());
    }
}

void Fourier::show_dft_res()
{
    for (long unsigned int i = 0; i < this->dft_res.size(); i++)
    {
        for (long unsigned int j = 0; j < this->dft_res[i].size(); j++)
        {
            std::cout << dft_res[i][j] << ", ";
        }
        std::cout << "Next" << std::endl;
    }
}

std::vector<std::vector<double>> Fourier::getDFTRes()
{
    return this->dft_res;
}

void Fourier::getSortedRes()
{
    for (long unsigned int i = 0; i < this->dft_res.size() - 1; i++)
    {
        for (long unsigned int j = i + 1; j < this->dft_res.size(); j++)
        {
            if (this->dft_res[j][3] > this->dft_res[i][3])
            {
                std::vector<double> temp = this->dft_res[j];
                this->dft_res[j] = this->dft_res[i];
                this->dft_res[i] = temp;
            }
        }
    }
}

void Fourier::initCanvasDrawing()
{
    std::vector<double> x;
    std::vector<double> y;
    std::vector<sf::VertexArray> vertices;
    vertices.push_back(sf::VertexArray());
    vertices[0].setPrimitiveType(sf::LinesStrip);
    int lines_number = 0;
    int condition = false;

    sf::Color pencolor = sf::Color::White;

    sf::RenderWindow window(sf::VideoMode(350, 350), "Canvas ", sf::Style::Close);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Key::E)
                    window.close();
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                condition = true;
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                lines_number++;
                vertices.push_back(sf::VertexArray());
                vertices[lines_number].setPrimitiveType(sf::LinesStrip);
                condition = false;
                window.close();
            }
        }

        if (condition)
        {

            vertices[lines_number].append(sf::Vertex(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y), pencolor));
            if (event.type == sf::Event::MouseMoved)
            {
                double real = sf::Mouse::getPosition(window).x;
                double imaginary = sf::Mouse::getPosition(window).y;
                Complex c(real, imaginary);
                this->coordinate_shape.push_back(c);
            }
        }

        window.clear(sf::Color::Black);

        for (long unsigned int i = 0; i < vertices.size(); i++)
        {
            window.draw(vertices[i]);
        }

        window.display();
    }
}
