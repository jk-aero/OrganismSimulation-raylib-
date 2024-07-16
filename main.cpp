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
    Organism(int size, int posX, int posY, double energy)
        : size(size), posX(posX), posY(posY), energy(energy), isDead(false) {
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


class food
{
    int size;
    int energy;


};



int main(void)
{
    const int screenWidth = 1000;
    const int screenHeight = 800;



    std::vector<Organism> totalOrganisms;
    std::vector<food>foods;
    int organismCount(30);
    int foodCount = 80;
    for (int i=0;i<organismCount;i++)
    {
        int size = getRandomInt(10,5);
        int energy = 100;
        int x = getRandomInt(screenWidth);
        int y = getRandomInt(screenHeight);
        
        totalOrganisms.push_back(Organism(size, x, y, energy));
    
    
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
            DrawCircle(one.size, one.posX, one.posY, ORANGE);
        }
                               

        EndDrawing();
            }

       CloseWindow(); 
    return 0;
}
