# Overview

This is a classic Snake game implemented in C++ using the console. The game has a dynamically growing snake, collision detection, and a simple interface with color support. Players control the snake by using keyboard inputs and try to eat fruit to increase their score.

# Features

-> Dynamically growing snake
-> Randomly generated fruit positions
-> Collision detection
-> Score tracking with a high score feature
-> Glides with less flicker
-> Colored graphics
-> Ability to reset game in case of game over

# Controls

-> W: Up
-> A: Left
-> S: Down
-> D: Right
-> X: Quit game

# How to Play

-> Run the program.
-> Enter the grid size (width and height).
-> Use W, A, S, D keys to move the snake.
-> Eat the fruit (&) to grow and increase your score.
->Avoid colliding with the walls and yourself.
-> If you lose, press R to restart or X to exit.

# Prerequisites

-> C++ Compiler
-> Windows OS (makes use of windows.h and _kbhit() for input)
-> Compilation (Windows)
-> Open Command Prompt and go to the directory of the source file.
-> Compile using g++:
-> g++ -o snake_game snake_game.cpp -std=c++11
-> Run the executable:
-> snake_game

# Code Explanation

-> The game is built on the following key methods:
-> setup() initializes game variables and calls the production of the first fruit.
-> Draw() draws the game board by rendering walls, snake, and fruit.
-> Input() captures user inputs for movement.
-> MoveSnake() updates positions of the snake and checks for collision.
-> GameOverScreen() prints out game over messages with restart functionality

# Author

Rudra Trivedi
Prit Kasundra
Parth Sorathiya
Aryan Dalsaniya
