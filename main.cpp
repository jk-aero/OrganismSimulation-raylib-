#include "raylib.h"
#include<vector>
#include <random>
#include <iostream>
#include <string>


// Function to generate and return a random integer within a specified range
int getRandomInt(int max, int min = 0) {
    // Initialize a random seed engine based on random device
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the distribution for the range [min, max]
    std::uniform_int_distribution<int> distrib(min, (max));

    // Generate and return a random integer
    return distrib(gen);
}

class Organism
{
public:
    int size;
    int posX, posY, range;
    bool isDead;
    double energy;
    // Constructor
    Organism(int size, int posX, int posY, int range ,double energy)
        : size(size), posX(posX), posY(posY), range(range),energy(energy), isDead(false) {
        // Initialize other properties as needed
    }

    // Destructor (if needed)
    ~Organism() {
        // Perform cleanup if necessary
    }

    // Member functions (methods) to interact with the organism
    void move(int newX, int newY) {
        posX = newX;
        posY = newY;
    }

    void consumeEnergy(double amount) {
        energy -= amount;
        if (energy <= 0) {
            isDead = true;
            energy = 0;
        }
    }

};


class Food {
private:
    int size;       // Size of the food (assuming size is in some unit)
    int energy;     // Energy content of the food (assuming energy is in some unit)

public:
    // Constructor with default values
    Food(int size = 0, int energy = 0) : size(size), energy(energy) {}

    // Getter and setter methods
    int getSize() const {
        return size;
    }

    void setSize(int newSize) {
        size = newSize;
    }

    int getEnergy() const {
        return energy;
    }

    void setEnergy(int newEnergy) {
        energy = newEnergy;
    }

    // Other methods if needed
    void printDetails() const {
        std::cout << "Food Size: " << size << ", Energy: " << energy << std::endl;
    }


int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 800;



    std::vector<Organism> totalOrganisms;
    std::vector<food>totalFoods;
    int organismCount(30);
    int foodCount = 80;
    for (int i=0;i<organismCount;i++)
    {
        int size = getRandomInt(10,5);
        int energy = 100;
        int x = getRandomInt(screenWidth);
        int range = getRandomInt(30,size+5);
        int y = getRandomInt(screenHeight);
        
        totalOrganisms.push_back(Organism(size, x, y,range, energy));
    
    
    }

    for (int i = 0; i < foodCount; i++)
    {
        totalFood.push_back()


    }

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
   

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
       



        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        DrawCircle(150, 50, 10.0, RED);

        for (Organism one : totalOrganisms)
        {
            DrawCircle(one.posX,one.posY, one.size, ORANGE);
            DrawCircleLines(one.posX, one.posY, one.range, ORANGE);                         // Draw circle outline

        }


                               
        ClearBackground(RAYWHITE);
        EndDrawing();
            }

       CloseWindow(); 
    return 0;
}
