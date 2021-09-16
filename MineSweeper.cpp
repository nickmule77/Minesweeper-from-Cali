/*
 * MineSweeper.cpp
 *
 *  Created on: Apr 26, 2021
 *      Author: nickm
 */

#include "MineSweeper.h"

MineSweeper::MineSweeper() {
	INITIAL = "*";
	bombs = 0;
	playerMatrix.resize(ROWS, vector<string>(COLUMNS, INITIAL));
	gameMatrix.resize(ROWS, vector<string>(COLUMNS, INITIAL));
	//first number is row, second is column, starts at 0
}

void MineSweeper::DisplayGame()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout<<playerMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

void MineSweeper::SeedBombs()
{
	while (bombs < 5)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				INITIAL = to_string(rand() % 10 +1);
				if (gameMatrix[i][j] == "B")
				{
				}
				else if (INITIAL == "10")
				{
					if (bombs >= 5)
					{
						break;
					}
					else
					{
						bombs++;
						gameMatrix[i][j] = "B";
						if (bomb1 != "0")
						{
							if (bomb2 != "0")
							{
								if (bomb3 != "0")
								{
									if (bomb4 != "0")
									{
										bomb5 = to_string(i) + " " + to_string(j);
									}
									else
									{
										bomb4 = to_string(i) + " " + to_string(j);
									}
								}
								else
								{
									bomb3 = to_string(i) + " " + to_string(j);
								}
							}
							else
							{
								bomb2 = to_string(i) + " " + to_string(j);
							}
						}
						else
						{
							bomb1 = to_string(i) + " " + to_string(j);
						}
					}
				}
			}
		}
	}
}

void MineSweeper::BombLocations()
{
	cout<<bomb1<<endl;
	cout<<bomb2<<endl;
	cout<<bomb3<<endl;
	cout<<bomb4<<endl;
	cout<<bomb5<<endl;
}

void MineSweeper::GenerateBorder()
{
	vector<string> nick (5, "*");
	gameMatrix.insert(gameMatrix.begin(), nick);
	gameMatrix.insert(gameMatrix.end(), nick);
	for (unsigned int i = 0; i < gameMatrix.size(); i++)
	{
		gameMatrix[i].insert(gameMatrix[i].begin(), "*");
		gameMatrix[i].insert(gameMatrix[i].end(), "*");
	}
}

void MineSweeper::ShowBackend()
{
	for (unsigned int i = 0; i < gameMatrix.size(); i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout<<gameMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

void MineSweeper::WinCheck()
{
	int starCount = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (playerMatrix[i][j] == "*")
			{
				starCount++;
			}
		}
	}
	if (starCount == 5)
	{
		win = true;
	}

}

void MineSweeper::UserInput()
{
	//have a display matrix and then the actual matrix to deal with hiding B's, dont use bomblocations
	//location = x, y
	//x = row, y = column ; i = column, j = row
	//subtract 1 from location each
	// value = 0;
	// check all 8 adjacents, if == "B", value++
	// matrix[y][x] == value;
	int x;
	int y;

	while (gameOver == false and win == false)
	{
		cout<<"x-position = "<<endl;
		cin>>x;
		cout<<"y-position = "<<endl;
		cin>>y;
		//y-=1;
		//x-=1;
		int value = 0;
		if (gameMatrix[y][x] == "B")
		{
			playerMatrix[y-1][x-1] = "B";
			gameOver = true;
		}
		else
		{
			if (gameMatrix[y-1][x] == "B")
			{
				//to the left
				value++;
			}
			if (gameMatrix[y+1][x] == "B")
			{
				//to the right
				value++;
			}
			if (gameMatrix[y][x+1] == "B")
			{
				//down
				value++;
			}
			if (gameMatrix[y][x-1] == "B")
			{
				//up
				value++;
			}
			if (gameMatrix[y-1][x-1] == "B")
			{
				//up left
				value++;
			}
			if (gameMatrix[y-1][x+1] == "B")
			{
				//down left
				value++;
			}
			if (gameMatrix[y+1][x+1] == "B")
			{
				//down right
				value++;
			}
			if (gameMatrix[y+1][x-1] == "B")
			{
				//down right
				value++;
			}
			playerMatrix[y-1][x-1] = to_string(value);
		}
		DisplayGame();
		WinCheck();
	}
	if (gameOver == true)
	{
		cout<<"You stepped on a mine! Better luck next time."<<endl;
	}
	else if (win == true)
	{
		cout<<"Congrats, you won!"<<endl;
	}
}

MineSweeper::~MineSweeper() {
	// TODO Auto-generated destructor stub
}

