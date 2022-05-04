#include <iostream> // Console output
#include <chrono> // Time library
#include <thread> // Access on current thread to wait few milliseconds

#include "tetrissound.h"


class RacingCar {
public:
    RacingCar(std::string name, unsigned int topSpeed) :
        name(name), topSpeed(topSpeed){}

    void drive(int randomNumber){
        distanceDone += randomNumber * topSpeed;
    }

    unsigned int getDistanceDone() const{
        return distanceDone;
    }
    std::string getName() const{
        return name;
    }

private:
    std::string name;
    unsigned int topSpeed{0};
    unsigned int distanceDone{0};
};

// See: https://stackoverflow.com/questions/9262270/color-console-output-with-c-in-windows#9262335
inline void setcolor(int textcol, int backcol)
{
    textcol %= 16; backcol %= 16;
    unsigned short wAttributes = ((unsigned)backcol << 4) | (unsigned)textcol;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    SetConsoleTextAttribute(hStdOut, wAttributes);
}

void visualizeCar(std::string name, unsigned int distanceDone){
    std::cout << name << " - " << distanceDone/1000 << ":" << std::endl;
    for (int i = 0; i < distanceDone/1000; ++i) {
        std::cout << "■";
    }
    std::cout << std::endl;
}

int main()
{
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    auto racingCar1 = RacingCar("MasterBlaster", 289);
    auto racingCar2 = RacingCar("TheDestroyer", 292);
    int routeLengthInMeter {64000};

    srand(time(NULL));
    while (true) {
        int randomNumberCar1 = rand() % 10;
        int randomNumberCar2 = rand() % 10;

        racingCar1.drive(randomNumberCar1);
        racingCar2.drive(randomNumberCar2);

        auto ddCar1 = racingCar1.getDistanceDone();
        auto ddCar2 = racingCar2.getDistanceDone();

        // call cls (clear screen) in console
        system("cls");

        constexpr int greenTextColor{2};
        constexpr int blackBackgroundColor{0};
        setcolor(greenTextColor, blackBackgroundColor);

        visualizeCar(racingCar1.getName(), ddCar1);
        visualizeCar(racingCar2.getName(), ddCar2);

        // The duration of every visualization step in this loop are 100 milliseconds
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        // Which car has won?
        if(ddCar1 > routeLengthInMeter || ddCar2 > routeLengthInMeter){
            if(ddCar1 == ddCar2){
                // Rarely, but possible
                std::cout << "Really, two winners?" << std::endl;
            }
            else if(ddCar1 > ddCar2){
                // Car 1 has won
                std::cout << racingCar1.getName() << " has won!" << std::endl;
            }
            else{
                // Car 2 has won
                std::cout << racingCar2.getName() << " has won!" << std::endl;
            }
            std::cout << "Race over" << std::endl;
            tetris::playSound();
            // Race over -> Leave loop
            break;
        }
    }
    return 0;
}
