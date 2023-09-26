#include "Pinball.h"

using namespace std;

Pinball::Pinball()
{
    name = "null";
    year = 0;
    manufacturer = "PinCorp";
    aveFunRating = -1;
    theme = "boring";
}
Pinball::Pinball(std::string inName, int inYear, std::string inManufacturer, float inAveFunRating, std::string inTheme)
{
    name = inName;
    year = inYear;
    manufacturer = inManufacturer;
    aveFunRating = inAveFunRating;
    theme = inTheme;
}
Pinball::Pinball(const Pinball & copy)
{
    name = copy.name;
    year = copy.year;
    manufacturer = copy.manufacturer;
    aveFunRating = copy.aveFunRating;
    theme = copy.theme;
}
Pinball::~Pinball()
{

}

    //Getters
std::string Pinball::getName() const
{
    return(name);
}
int Pinball::getYear() const
{
    return(year);
}
std::string Pinball::getManufacturer() const
{
    return(manufacturer);
}
float Pinball::getFunRating() const
{
    return(aveFunRating);
}
std::string Pinball::getTheme() const
{
    return(theme);
}
    //Setters
void Pinball::setName(const std::string inputName)
{
    name = inputName;
}
void Pinball::setYear(const int inputYear)
{
    year = inputYear;
}
void Pinball::setManufacturer(const std::string inputManufacturer)
{
    manufacturer = inputManufacturer;
}
void Pinball::setFunRating(const float inputFunRating)
{
    aveFunRating = inputFunRating;
}
void Pinball::setTheme(const std::string inputTheme)
{
    theme = inputTheme;
}
    //Other Methods
void Pinball::print() const
{
    std::cout << name << ","<< year << "," << manufacturer << "," << aveFunRating <<  ","<< theme << "," << std::endl;
    // std::cout << year << std::endl;
    // std::cout << manufacturer << std::endl;
    // std::cout << aveFunRating << std::endl;
    // std::cout << theme << std::endl;
}
void Pinball::printYear() const
{
    std::cout << name << "," << manufacturer << std::endl;
}
//Scraped, put in main
// bool Pinball::readFile() const
// {
//     // std::string dinName;
//     // std::ifstream din;
//     // din.open("pinball.txt");
//     // if (din.fail())
//     // {
//     //     return (false);
//     // }
//     // else
//     // {
//     //     din.getline(din, dinName, ",")
//     //     name = dinName;
//     //     return (true);
//     // }
// }

// bool Pinball::writeFile() const
// {
    
// }