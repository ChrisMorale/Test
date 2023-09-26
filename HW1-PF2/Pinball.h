#ifndef Pinball_h
#define Pinball_h

#include <iostream>
#include <fstream>

class Pinball
{
    public:
    // Constructors/Destructors
        Pinball();
        Pinball(std::string inName, int inYear, std::string inManufacturer, float inAveFunRating, std::string inTheme);
        Pinball(const Pinball & copy);
        ~Pinball();

    //Getters
        std::string getName() const;
        int getYear() const;
        std::string getManufacturer() const;
        float getFunRating() const;
        std::string getTheme() const;
    //Setters
        void setName(const std::string inputName);
        void setYear(const int inputYear);
        void setManufacturer(const std::string inputManufacturer);
        void setFunRating(const float inputFunRating);
        void setTheme(const std::string inputTheme);
    //Other Methods
        void print() const;
        //Prints specific info about a machine from a different year.
        void printYear() const;
        //Unused, put in main instead
        // bool readFile() const;
        // bool writeFile() const;

    private:
        std::string name;
        int year;
        std::string manufacturer;
        float aveFunRating;
        std::string theme;

};

#endif