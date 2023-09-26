#include "Pinball.h"

#include <iostream>
#include <fstream>
#include <string>

//Print the menu the user uses to interact with the program.
void PrintMenu()
{
    std::cout << "Welcome to Pinball Info, what can I do for you?" << std::endl;
    std::cout << "Option 1: Load Machines from ascii file." << std::endl;
    std::cout << "Option 2: Insert New Machine into the list." << std::endl;
    std::cout << "Option 3: Find machines made in a certain year." << std::endl;
    std::cout << "Option 4: Print information for all machines." << std::endl;
    std::cout << "Enter zero to write list to file and exit." << std::endl;
    std::cout << "Enter selection: " << std::endl; 
}

int main()
{
    
    int select = -1;
    int max = 10;

    // variables for creating new machines
    std::string inputname;
    int inputyear;
    std::string inputmanufacturer;
    float inputaveFunRating;
    std::string inputtheme;
    // variables to store info from an incomming text file
    std::string dinName;
    std::string dinYear;
    int readYear;
    std::string dinManufacturer;
    std::string dinAveFunRating;
    float readAveFunRating;
    std::string dinTheme;
    std::string trashEmpty;
// variables used to determine specific aspects of pinball objects
    std::string findEmpty = "";
    int findYear = 0;
// input and output variables used to affect the text files
    std::ifstream din;
    std::ofstream dout;
// Array used to store information about Pinball objects
    Pinball list[max];
// While loop cycles the menu until the user inputs zero
// Switch statement allows user to input a number to select an option.
    while(select != 0){
        PrintMenu();
        std::cin >> select;
        switch(select)
        {
            //Option 1 uses the input variable to take in information from "pinball.txt"
            // and store the info into the list array.
            //For loop cycles throught the whole array and stores info to the array, if there is info
            case 1:
                din.open("pinball.txt");
                for(int i = 0; i < max; i++)
                {
                    if (din.fail())
                    {
                        //std::cout << "fail" << std::endl;
                    }
                    else
                    {
                        dinName = "null";
                        dinYear = "0";
                        dinManufacturer = "PinCorp";
                        dinAveFunRating = "-1";
                        dinTheme = "boring";
                        //din.getline(dinName, 256, ',');
                        std::getline(din, dinName, ',');
                        if(i == 4)
                        {
                            dinName = "null";
                        }
                        //std::cout << "name1" << dinName << "name2" << std::endl;
                        list[i].setName(dinName);
                        // std::cout << din.peek() << std::endl;

                        std::getline(din, dinYear, ',');
                        //std::cout << "Year "<< dinYear << std::endl;
                        readYear = stoi(dinYear);
                        list[i].setYear(readYear);
                        

                        std::getline(din, dinManufacturer, ',');
                        //std::cout << dinManufacturer << std::endl;
                        list[i].setManufacturer(dinManufacturer);
                        
                        std::getline(din, dinAveFunRating, ',');
                        //std::cout << dinAveFunRating << std::endl;
                        readAveFunRating = std::stof(dinAveFunRating);
                        list[i].setFunRating(readAveFunRating);

                        std::getline(din, dinTheme, ',');
                        //std::cout << "theme" << dinTheme << "theme2"<< std::endl;
                        list[i].setTheme(dinTheme);

                        din.ignore(256, '\\');

                        // while (find != '\\')
                        // {
                        //     find = din.peek();
                            
                        // }
                        
                        dinName = "null";
                        dinYear = "0";
                        dinManufacturer = "PinCorp";
                        dinAveFunRating = "-1";
                        dinTheme = "boring";

                    }

                    //list[i].print();
                }
                din.close();
                std::cout << "Done!" << std::endl;
                break;
            //Option 2 allows the user to input info to add a new machine to the pinball list array
            case 2:
                std::cout << "What is the name of the machine?" << std::endl;
                std::cin >> inputname;
                std::cout << "What is the year of the machine?(numbers)" << std::endl;
                std::cin >> inputyear;
                // while(typeid(inputyear) != typeid(int))
                // {
                //     std::cout << "Sorry, invalid input!" << std::endl;
                //     std::cout << "What is the year of the machine?" << std::endl;
                //     std::cin >> inputyear;
                // }
                std::cout << "What is the manufacturer of the machine?" << std::endl;
                std::cin >> inputmanufacturer;
                std::cout << "What is the average fun rating of the machine?(numbers)" << std::endl;
                std::cin >> inputaveFunRating;
                // while(typeid(inputaveFunRating) != typeid(float))
                // {
                //     std::cout << "Sorry, invalid input!" << std::endl;
                //     std::cout << "What is the average fun rating of the machine?" << std::endl;
                //     std::cin >> inputaveFunRating;
                // }
                std::cout << "What is the theme of the machine?" << std::endl;
                std::cin >> inputtheme;
                //For loop finds the first empty array part to put the machine in.
                for(int i = 0; i < max; i++)
                {
                    //std::cout << "hi" << std::endl;
                    findEmpty = list[i].getName();
                    
                    if (findEmpty == "null")
                    {
                        list[i] = Pinball(inputname, inputyear, inputmanufacturer, inputaveFunRating, inputtheme);
                        //list[i].print();
                        break;
                    }
                    //list[i].print();
                    // break;
                }



                break;
            // Program takes a user entered year and displays selected info about that machine
            case 3:
                std::cout << "Enter a year: " << std::endl;
                std::cin >> findYear;
                for(int i = 0; i < 10; i++)
                {
                    if (list[i].getYear() == findYear)
                    {
                        list[i].printYear();
                    }
                } 
                break;
            //Prints all parts of the array, even empty ones.
            case 4:
                for (int i = 0; i < max; i++)
                {
                    list[i].print();
                }
                break;
            
        }
    }
    //When user inputs zero on the menu, the array's contents are put into the pinballFinal text document.
    std::cout << "Thank you for your time!" << std::endl;
    dout.open("pinballFinal.txt");
    for (int i = 0; i < 10; i++)
    {
        dout << list[i].getName() << "," << list[i].getYear() << "," << list[i].getManufacturer() << "," << list[i].getFunRating() << "," << list[i].getTheme() << "," << "\\" << std::endl;
    }
    dout.close();
    return(0);
}
//g++ -Wall *.cpp -o hw1.exe