# Overview

This is a classic Snake game implemented in C++ using the console. The game features a dynamically growing snake, collision detection, and a simple interface with color support. Players control the snake using keyboard inputs and aim to eat fruit to increase their score.

# Features

-> Dynamically growing snake
-> Randomly generated fruit positions
-> Collision detection (self and wall)
-> Score tracking with a high score feature
-> Smooth movement with minimal flickering
-> Colorful display
-> Option to restart after game over

# Controls

-> W - Move Up
-> A - Move Left
-> S - Move Down
-> D - Move Right
-> X - Exit the game

# How to Play

-> Run the program.
-> Enter the grid size (width and height).
-> Use W, A, S, D keys to move the snake.
-> Eat the fruit (&) to grow and increase your score.
-> Avoid colliding with the walls and yourself.
-> If you lose, press R to restart or X to exit.
-> Installation and Compilation

# Requirements

-> C++ Compiler (GCC, MSVC, Clang, etc.)
-> Windows OS (uses windows.h and _kbhit() for input handling)
-> Compilation (Windows)
-> Open Command Prompt and navigate to the directory containing the source file.
-> Compile using g++:
-> g++ -o snake_game snake_game.cpp -std=c++11
-> Run the executable:
-> snake_game

# Code Explanation

-> The game consists of the following core functions:
-> setup() - Initializes game variables and generates the first fruit.
-> Draw() - Renders the game board with walls, snake, and fruit.
-> Input() - Captures user input for movement.
-> MoveSnake() - Updates the snake's position and checks for collisions.
-> GameOverScreen() - Displays the game-over message and handles restart.

# Future Improvements

-> Cross-platform support (remove windows.h dependency)
-> Enhanced UI/UX with graphical elements
-> Sound effects and background music
-> Difficulty levels (speed adjustments)
-> Multiplayer mode

# Author

Rudra Trivedi
Prit Kasundra
Parth Sorathiya
Aryan Dalsaniya
