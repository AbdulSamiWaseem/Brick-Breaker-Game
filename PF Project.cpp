#include <iostream>
#include <fstream>
#include "yourgraphics.h"

using namespace std;
int main() {
	int w = 0, h = 0, brickWidth, brickHeight;
	int u = 400;
	int count = 0;
	int brickX[6][10];
	int brickY[6][10];
	int brick[6][10];
	int barWidth = 200;
	int ballSize = 17;
	int ballMoveX = u + 100;
	int ballMoveY = 399 - ballSize;
	bool ballDown = true;
	bool ballRight = true;
	bool brickBreak = false;
	int marginTop = 80;
	int score = 0;
	int lifes = 3;
	int a, chk;


	getWindowDimensions(w, h);
	brickWidth = w / 10;
	brickHeight = 20;
	cls();
	showConsoleCursor(false);
	drawLine(0, 50, 960, 50, 255);
	ifstream readFile("gameSave.txt");
	if (readFile >> a)
	{
		cout << "Enter 0 to Run New Game" << endl;
		cout << "Enter 1 to Run Save Game " << endl;
		cin >> chk;
		while (chk != 1 && chk != 0) {
			cout << "Enter Valid Input" << endl;
			cin >> chk;
		}
		cls();
		if (chk == 1) {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == 0 && j == 0)
					{
						brick[i][j] = a;
					}
					else {
						readFile >> a;
						brick[i][j] = a;
					}
				}
			}
			readFile >> a;
			ballMoveX = a;
			readFile >> a;
			ballMoveY = a;
			readFile >> a;
			u = a;
			readFile >> a;
			score = a;
			readFile >> a;
			lifes = a;
			readFile >> a;
			ballDown = a;
			readFile >> a;
			ballRight = a;
		}
		else {
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 10; j++) {
					brick[i][j] = 3;
				}
			}
			for (int i = 2; i < 4; i++) {
				for (int j = 0; j < 10; j++) {
					brick[i][j] = 2;
				}
			}
			for (int i = 4; i < 6; i++) {
				for (int j = 0; j < 10; j++) {
					brick[i][j] = 1;
				}
			}
		}
	}

	else {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 10; j++) {
				brick[i][j] = 3;
			}
		}
		for (int i = 2; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				brick[i][j] = 2;
			}
		}
		for (int i = 4; i < 6; i++) {
			for (int j = 0; j < 10; j++) {
				brick[i][j] = 1;
			}
		}

	}
	readFile.close();
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			brickY[i][j] = brickHeight * i + marginTop;
			brickX[i][j] = brickWidth * j;
		}
	}

	cls();
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 10; j++) {
			if (brick[i][j] == 3)
			{
				drawRectangle(brickWidth * j, brickHeight * i + marginTop, brickWidth * (j + 1), brickHeight * (i + 1) + marginTop, 255, 255, 255, 120, 22, 22);
			}
			else if (brick[i][j] == 2)
			{
				drawRectangle(brickWidth * j, brickHeight * i + marginTop, brickWidth * (j + 1), brickHeight * (i + 1) + marginTop, 255, 255, 255, 255, 13, 13);
			}
			else if (brick[i][j] == 1) {
				drawRectangle(brickWidth * j, brickHeight * i + marginTop, brickWidth * (j + 1), brickHeight * (i + 1) + marginTop, 255, 255, 255, 219, 88, 88);
			}
			else {
				drawRectangle(brickWidth * j, brickHeight * i + marginTop, brickWidth * (j + 1), brickHeight * (i + 1) + marginTop, 12, 12, 12, 12, 12, 12);
			}
		}
	}

	drawRectangle(u, 400, u + barWidth, 420, 200, 255, 255, 255, 255, 255);

	while (lifes > 0) {
		drawLine(0, 50, 960, 50, 255);

		gotoxy(50, 1);
		cout << "PLAYING";
		delay(1);

		if (lifes == 3) {
			drawEllipse(710, 18, 725, 33, 255, 0, 0, 255, 0, 0);
			drawEllipse(740, 18, 755, 33, 255, 0, 0, 255, 0, 0);
			drawEllipse(770, 18, 785, 33, 255, 0, 0, 255, 0, 0);
		}
		else if (lifes == 2) {
			drawEllipse(710, 18, 725, 33, 255, 0, 0, 255, 0, 0);
			drawEllipse(740, 18, 755, 33, 255, 0, 0, 255, 0, 0);
			drawEllipse(770, 18, 785, 33, 255, 0, 0, 0, 0, 0);
		}
		else if (lifes == 1) {
			drawEllipse(710, 18, 725, 33, 255, 0, 0, 255, 0, 0);
			drawEllipse(740, 18, 755, 33, 255, 0, 0, 0, 0, 0);
			drawEllipse(770, 18, 785, 33, 255, 0, 0, 0, 0, 0);
		}
		else if (lifes == 0) {
			drawEllipse(710, 18, 725, 33, 255, 0, 0, 0, 0, 0);
			drawEllipse(740, 18, 755, 33, 255, 0, 0, 0, 0, 0);
			drawEllipse(770, 18, 785, 33, 255, 0, 0, 0, 0, 0);
		}

		gotoxy(1, 1);
		cout << "Score : " << score;
		gotoxy(80, 1);
		cout << "Lifes :";


		drawLine(0, 0, 0, 480, 255);
		drawLine(960, 0, 960, 480, 255);
		char c = getKey();
		char d = ' ';

		if (c == 'q') {
			break;
		}
		else if (c == 'p') {
			while (true)
			{
				gotoxy(50, 1);
				cout << "PAUSED!";
				d = getKey();
				if (d == 'c')
				{

					break;
				}
			}
		}
		else if (c == 's') {
			ofstream writeFile("gameSave.txt");
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 10; j++) {
					writeFile << brick[i][j] << endl;
				}
			}
			writeFile << ballMoveX << endl;
			writeFile << ballMoveY << endl;
			writeFile << u << endl;
			writeFile << score << endl;
			writeFile << lifes << endl;
			writeFile << ballDown << endl;
			writeFile << ballRight << endl;
			writeFile.close();

		}
		else if (GetAsyncKeyState(VK_LEFT)) {
			if (u > 0) {
				u -= 4;
				drawRectangle(0 + 2, 400, w - 2, 420, 12, 12, 12, 12, 12, 12);
				drawRectangle(u, 400, u + barWidth, 420, 200, 255, 255, 255, 255, 255);
			}
		}

		else if (GetAsyncKeyState(VK_RIGHT)) {
			if (u + barWidth < w)
			{
				u = u + 4;
				drawRectangle(0 + 2, 400, w - 2, 420, 12, 12, 12, 12, 12, 12);
				drawRectangle(u, 400, u + barWidth, 420, 200, 255, 255, 255, 255, 255);
			}
		}
		drawEllipse(ballMoveX - ballSize / 2, ballMoveY, ballMoveX + ballSize / 2, ballMoveY + ballSize, 12, 12, 12, 12, 12, 12);
		if (ballMoveX - ballSize / 2 <= 0 || ballMoveX + ballSize / 2 >= w)
		{
			ballRight = !ballRight;
		}


		if (ballDown) {
			if (ballMoveY == 500) {
				lifes--;
				ballMoveX = u + 100;
				ballMoveY = 399 - ballSize;
			}

			if ((ballMoveX >= u && ballMoveX <= u + barWidth) && ballMoveY + ballSize == 399) {
				ballDown = false;
			}
			else {
				if (ballRight) {
					ballMoveX++;
					ballMoveY++;
				}
				else {
					ballMoveX--;
					ballMoveY++;
				}
			}
		}

		else {
			if (ballMoveY <= 50) {
				ballDown = true;
			}
			else if (ballMoveY > brickHeight * 6 + marginTop)
			{

				if (ballRight)
				{
					ballMoveX++;
					ballMoveY--;
				}
				else {
					ballMoveX--;
					ballMoveY--;
				}
			}
			else {
				for (int i = 0; i < 6; i++) {
					for (int j = 0; j < 10; j++) {
						if (ballMoveY <= brickY[i][j] + brickHeight && (ballMoveX >= brickX[i][j] && ballMoveX <= brickX[i][j] + brickWidth)) {
							if (brick[i][j] == 3) {
								brick[i][j]--;
								drawRectangle(brickX[i][j], brickY[i][j], brickX[i][j] + brickWidth, brickY[i][j] + brickHeight, 255, 255, 255, 255, 13, 13);
								ballDown = true;
								score += 20;
							}
							if (brick[i][j] == 2) {
								brick[i][j]--;
								drawRectangle(brickX[i][j], brickY[i][j], brickX[i][j] + brickWidth, brickY[i][j] + brickHeight, 255, 255, 255, 219, 88, 88);
								ballDown = true;
								score += 20;
							}
							else if (brick[i][j] == 1) {
								brick[i][j]--;
								drawRectangle(brickX[i][j], brickY[i][j], brickX[i][j] + brickWidth, brickY[i][j] + brickHeight, 12, 12, 12, 12, 12, 12);
								ballDown = true;
								score += 50;
							}
							else {
								if (ballRight)
								{
									ballMoveX++;
									ballMoveY--;
								}
								else {
									ballMoveX--;
									ballMoveY--;
								}
							}

						}
					}
				}
			}
		}


		drawEllipse(ballMoveX - ballSize / 2, ballMoveY, ballMoveX + ballSize / 2, ballMoveY + ballSize, 255, 0, 0, 255, 0, 0);

	}


	if (lifes < 1) {
		cls();
		int highScores[5];
		int a;
		bool flag = false;
		ifstream readFileH("highScores.txt");
		for (int i = 0; i < 5; i++) {
			if (readFileH >> a) {
				highScores[i] = a;
			}
			else {
				highScores[i] = 0;
			}
		}

		readFileH.close();

		ofstream writeFileH("highScores.txt");
		for (int i = 0; i < 5; i++) {
			if (highScores[i] < score) {
				flag = true;
				break;
			}
		}
		int min = 9999999999;
		int index = -1;
		if (flag) {
			for (int i = 0; i < 5; i++) {
				if (highScores[i] < min) {
					min = highScores[i];
					index = i;
				}
			}
			highScores[index] = score;
		}
		for (int i = 0; i < 5; i++) {
			writeFileH << highScores[i] << endl;
		}
		writeFileH.close();
		gotoxy(50, 2);
		cout << "HighScores";
		int y = 3;
		for (int i = 0; i < 5; i++) {
			count = i + 1;
			y += 3;
			gotoxy(50, y);
			cout << count << ". " << highScores[i] << endl;
		}
		delay(5000);

		cls();
		gotoxy(50, 13);
		cout << "G";
		delay(100);
		cout << "A";
		delay(100);
		cout << "M";
		delay(100);
		cout << "E";
		gotoxy(50, 14);
		delay(100);
		cout << "O";
		delay(100);
		cout << "V";
		delay(100);
		cout << "E";
		delay(100);
		cout << "R";
		delay(100);
		cout << ".";
		delay(100);
		cout << ".";
		delay(100);
		cout << ".";
		delay(100);
		cout << ".";
		delay(100);
		cout << ".";
		delay(100);
		cout << ".";
		delay(100);
		cout << ".";
		delay(100);
		cout << ".";
		delay(100);
		cout << ".";
		delay(10000);
	}
	return 0;
}
