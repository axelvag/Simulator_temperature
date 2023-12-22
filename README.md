# Simulator_temperature

Simulation of the heat equation on a regular 2D grid

It is a room seen from above with:
 - black box: wall
 - blue box: cold air
 - red box: hot air

![image](image/Air1.jpg)

When I increase the heat in the center and in the top of the room:

![image](image/Air2.jpg)

After letting the room cool:

![image](image/Air3.jpg)

### Notion

Heat equation: a grid with heat source, wall, air ⇒ temperature evolution
Intuitive notion of the Laplacian: a box wants to be the same temperature as the average of its neighbors

Everything is done in C++ with the GraPic graphics library.

# Play

Click on a box to reheat it with the left mouse button ​🖱️​.

The value at the top left is the heat on the square where the mouse is placed.

And the ones at the bottom left are the x and y coordinates of the mouse.

# GrAPiC 

## Starting

Linux, Windows and Mac instruction :

http://licence-info.univ-lyon1.fr/grapic

## Introduction

GrAPiC is a small, easy-to-use framework to add graphical functionalities to your C/C++ code. 
Its main goal is to provide easy graphical functions to be used in introduction courses of algorithm and programming in C/C++. 
It is based on SDL2 but to use it you need to know only few very simples functions. 
The Grapic archive comes with the needed SDL part, you do not have to install SDL. Just unzip and enjoy ! 

## Starting

Compiling from the github (which is not the standard way).

* On Linux you need to install:
- g++
- doxygen
- zip
- lib-sdl2-dev lib-sdl2 sd2_image... sdl2_ttf...

1. sudo apt install g++ premake4 zip doxygen libsdl2-dev libsdl2-mixer-dev libsdl2-image-dev
2. make premake
3. make
(4. script/make_linux_test.sh): to test the archive doc/download/grapic-linux.tgz
(5. script/make_web.sh): to create the zip files in doc/download or to sync everything to the webpage (need passwd).


* On windows
0. Install CB 20
1. run premake-cb20.bat to generate the projects files    or     run premake-lifami.bat to generate lifami projects 
2. open build/windows-cb20/grapic.workspace

## Best way to make a projet in windows

(windows): 
 - Open build/windows-cb20/grapic.workspace in CodeBlocks
 - In the left part (Management) of the logiciel, double clic in the projet of yours choice (it's those in /apps)
 - Finally clic in the green arrow in the top of the screen

![OpenFolder](image/OpenFolder.jpg)
![OpenFile](image/OpenFile.jpg)

## Put your new project in GraPic

Add your directory with your cpp files in "apps" and add the path in "premake4".

