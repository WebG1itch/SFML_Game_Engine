# Assignment 1

To run the project, locate the `SFML_Game_Engine.exe` in the `cmake-build-debug` folder. Run this file with `keys.cfg` and `OpenSans-Regular.ttf` in the same folder to run the canvas properly. (Those two extra files are only required for the text to show, and for the mouse-click functionality to work) 

You can try to build the project, but I personally think it would be quite difficult since I've setup cmake and SFML for my own system. 
The main files for this program are `main.cpp`, `Core/GameLoop`, and `Core/Window`, however, all files in `/Core/` and `/Util/` are used. The rest of the files are for the game engine and game I'm building for the later assignments.

What I learned: I already have experience in SFML, so the majority of what I learned is for the game engine I'm setting up, not so much what it takes to create primitive shapes. Function callbacks is the most important part, especially for a game engine, as it allows me to call functions from events that happen in the game. Aside from this, I've learned about different core classes that need to be in a game engine, as well as helper classes such as the textbox class I created. 
