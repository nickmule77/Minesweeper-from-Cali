/*
 * MineSweeper.h
 *
 *  Created on: Apr 26, 2021
 *      Author: nickm
 */

#ifndef MINESWEEPER_H_
#define MINESWEEPER_H_

#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class MineSweeper {
public:
	MineSweeper();
	void DisplayGame();
	void SeedBombs();
	void UserInput();
	void BombLocations();
	void GenerateBorder();
	void ShowBackend();
	void WinCheck();
	virtual ~MineSweeper();
private:
	int bombs;
	vector< vector<string>> gameMatrix;
	vector< vector<string>> playerMatrix;
	int ROWS = 5;
	int COLUMNS = 5;
	string INITIAL;
	string bomb1 = "0";
	string bomb2 = "0";
	string bomb3 = "0";
	string bomb4 = "0";
	string bomb5 = "0";
	bool gameOver = false;
	bool win = false;
};

#endif /* MINESWEEPER_H_ */
