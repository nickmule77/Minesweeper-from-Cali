//============================================================================
// Name        : CS.cpp
// Author      : Nick Mule
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "MineSweeper.h"

using namespace std;

int main() {
	srand (time(0));
	MineSweeper newGame;
	newGame.SeedBombs();
	newGame.DisplayGame();
	//newGame.BombLocations();
	newGame.GenerateBorder();
	//newGame.ShowBackend();
	cout<<endl;
	newGame.UserInput();




}

//declare bombs first
//when inputting user choice, check around for bombs, determine then
