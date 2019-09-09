#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "console.h"

// gán mặt đất bằng kí tự đặc biệt
void Initialize(char ground[3][121]) {
	srand(time_t(NULL));
	int t;
	for (int i = 0; i <= 120; i++)
	{
		t = random(15);
		ground[0][i] = '_';
		switch (t)
		{
		case 1: ground[1][i] = '.'; ground[2][i] = ' ';
			break;
		case 2: ground[1][i] = '_'; ground[2][i] = ' ';
			break;
		case 3: ground[1][i] = 248; ground[2][i] = ' ';
			break;
		case 4: ground[1][i] = '`'; ground[2][i] = ' ';
			break;
		case 5: ground[2][i] = '.'; ground[1][i] = ' ';
			break;
		case 6: ground[2][i] = '`'; ground[1][i] = ' ';
			break;
		case 7: ground[2][i] = ' '; ground[1][i] = ' ';
			break;
		default:ground[1][i] = ' '; ground[2][i] = ' ';
			break;
		}
	}
	ground[0][120] = '\0';
	ground[1][120] = '\0';
	ground[2][120] = '\0';
}

// Vẽ ra nền trò chơi
void DrawGround(char ground[3][121], int y0) {
	gotoXY(0, y0);
	puts(&ground[0][0]);
	puts(&ground[1][0]);
	puts(&ground[2][0]);
}

// Hiệu ứng mặt đất
void MoveGround(char ground[3][121]) {
	//tạo phần tử tiếp theo
	int t = random(15);
	switch (t)
	{
	case 1: ground[1][119] = '.'; ground[2][119] = ' '; break;
	case 2: ground[1][119] = '_'; ground[2][119] = ' '; break;
	case 3: ground[1][119] = 248; ground[2][119] = ' '; break;
	case 4: ground[1][119] = '`'; ground[2][119] = ' '; break;
	case 5: ground[2][119] = '.'; ground[1][119] = ' '; break;
	case 6: ground[2][119] = '`'; ground[1][119] = ' '; break;
	case 7: ground[2][119] = ' '; ground[1][119] = ' '; break;
	default:ground[1][119] = ' '; ground[2][119] = ' '; break;
	}
	// dịch chuyển sang trái
	for (int i = 0; i <= 118; i++)
	{
		ground[1][i] = ground[1][i + 1];
		ground[2][i] = ground[2][i + 1];
	}
}

// Vẽ chướng ngại vật
void DrawObstacle(int type, int x, int y0, int color) {

	TextColor(color);
	switch (type)
	{
	case 1:
		gotoXY(x - 1, y0 - 4); printf("%c%c", 186, 186);
		gotoXY(x - 1, y0 - 3); printf("%c%c%c", 186, 186, 186);
		gotoXY(x - 1, y0 - 2); printf("%c%c%c", 186, 204, 188);
		gotoXY(x - 1, y0 - 1); printf("%c%c", 200, 185);
		gotoXY(x, y0); printf("%c", 186);
		break;
	case 2:
		gotoXY(x - 1, y0 - 1); printf("%c%c%c%c%c%c%c%c%c", 200, 206, 188, 200, 206, 188, 200, 206, 188);
		gotoXY(x, y0); printf("%c__%c__%c", 186, 186, 186);
		break;
	case 3:
		gotoXY(x - 1, y0 - 2); printf("%c%c%c%c%c%c", 186, 186, 186, 186, 186, 186);
		gotoXY(x - 1, y0 - 1); printf("%c%c%c%c%c%c", 200, 206, 188, 200, 206, 188);
		gotoXY(x, y0); printf("%c__%c", 186, 186);
		break;
	case 4:
		gotoXY(x - 1, y0 - 4); printf("     %c%c", 186, 186);
		gotoXY(x - 1, y0 - 3); printf("    %c%c%c", 186, 186, 186);
		gotoXY(x - 1, y0 - 2); printf("    %c%c%c", 186, 204, 188);
		gotoXY(x - 1, y0 - 1); printf("%c%c%c%c%c", 200, 206, 188, 200, 185);
		gotoXY(x, y0); printf("%c__%c", 186, 186);
		break;
	case 5:
		gotoXY(x - 1, y0 - 4); printf(" %c%c %c%c", 186, 186, 186, 186);
		gotoXY(x - 1, y0 - 3); printf("%c%c%C%c%c%c", 186, 186, 186, 186, 186, 186);
		gotoXY(x - 1, y0 - 3); printf("%c%c%C%c%c%c%c%c%c", 186, 204, 188, 186, 204, 188, 186, 186, 186);
		gotoXY(x - 1, y0 - 1); printf("%c%c %C%c %c%c%c", 200, 185, 200, 185, 200, 206, 188);
		gotoXY(x, y0); printf("%c__%c__%c", 186, 186, 186);
		break;
	case 6:
		gotoXY(x - 1, y0 - 4); printf("    %c%c %c%c", 186, 186, 186, 186);
		gotoXY(x - 1, y0 - 3); printf("   %c%c%c%c%c%c", 186, 186, 186, 186, 186, 186);
		gotoXY(x - 1, y0 - 3); printf("   %c%c%c%c%c%c%c%c%c", 186, 204, 188, 186, 204, 188, 186, 186, 186);
		gotoXY(x - 1, y0 - 1); printf("%c%c %c%c %c%c%c", 200, 185, 200, 185, 200, 206, 188);
		gotoXY(x, y0); printf("%c__%c__%c__%c", 186, 186, 186, 186);
		break;
	case 7:
		gotoXY(x - 1, y0 - 4); printf(" %c%c %c%c   %c%c", 186, 186, 186, 186, 186, 186);
		gotoXY(x - 1, y0 - 3); printf("%c%c%c%c%C%c%c %c%c%c", 186, 186, 186, 186, 186, 186, 186, 186, 186, 186);
		gotoXY(x - 1, y0 - 3); printf("%c%c%c%c%c%C%c%c%c%c%c", 186, 204, 186, 186, 204, 188, 186, 186, 186, 204, 186);
		gotoXY(x - 1, y0 - 1); printf("%c%c %c%c %c%c%c%c%c", 200, 185, 200, 185, 200, 206, 188, 200, 185);
		gotoXY(x, y0); printf("%c__%c__%c__%c", 186, 186, 186, 186);
		break;

	default:break;
	}
}

// In đè chướng ngại vật
void DeleteObstacle(int type, int x, int y0) {
	switch (type)
	{
	case 1:
		gotoXY(x + 1, y0 - 4); printf("              ");
		gotoXY(x + 1, y0 - 3); printf("              ");
		gotoXY(x + 1, y0 - 2); printf("              ");
		gotoXY(x, y0 - 1);     printf("              ");
		gotoXY(x, y0);         printf("              ");
		break;
	case 2: 
		gotoXY(x + 7, y0 - 1); printf("              ");
		gotoXY(x + 6, y0);     printf("              ");
		break;
	case 3:
		gotoXY(x + 4, y0 - 2); printf("              ");
		gotoXY(x + 4, y0 - 1); printf("              ");
		gotoXY(x + 3, y0);	   printf("              ");
		break;
	case 4:
		gotoXY(x + 4, y0 - 4); printf("              ");
		gotoXY(x + 4, y0 - 3); printf("              ");
		gotoXY(x + 4, y0 - 2); printf("              ");
		gotoXY(x + 3, y0 - 1); printf("              ");
		gotoXY(x + 3, y0);	   printf("              ");
		break;
	case 5:
		gotoXY(x + 4, y0 - 4); printf("              ");
		gotoXY(x + 4, y0 - 3); printf("              ");
		gotoXY(x + 4, y0 - 2); printf("              ");
		gotoXY(x + 4, y0 - 1); printf("              ");
		gotoXY(x + 6, y0);	   printf("              ");
		break;
	case 6:
		gotoXY(x + 7, y0 - 4); printf("              ");
		gotoXY(x + 7, y0 - 3); printf("              ");
		gotoXY(x + 10, y0 - 2);printf("              ");
		gotoXY(x + 10, y0 - 1);printf("              ");
		gotoXY(x + 9, y0);	   printf("              ");
		break;
	case 7:
		gotoXY(x + 10, y0 - 4);printf("              ");
		gotoXY(x + 10, y0 - 3);printf("              ");
		gotoXY(x + 10, y0 - 2);printf("              ");
		gotoXY(x + 9, y0 - 1); printf("              ");
		gotoXY(x + 9, y0);	   printf("              ");
		break;
	default:break;
	}
}

// Vẽ Player
void DrawPlayer(int height, int leg, int y0) {
	gotoXY(25, y0 - 5 - height); printf("           .___");
	gotoXY(25, y0 - 4 - height); printf("          |[o__]");
	gotoXY(25, y0 - 3 - height); printf(".       _/ [~__");
	gotoXY(25, y0 - 2 - height); printf("|-___.-'  /");
	gotoXY(25, y0 - 1 - height); printf(" `-._.__)/'");
	gotoXY(29, y0 - 0 - height); printf(" %c%c",124,124);
	gotoXY(29, y0 - (-1) -  height);

	if ((height > 0) || (leg == 3)) {
		printf(" --");
		return;
	}
	if (leg == 1) {
		printf(" %c_", 212);
	}
	if (leg == 2) {
		printf(" _%c",212);
	}
}

// Sử lí hiệu ứng nhảy và in đè lên player
void HandingPlayer(int jump, int height, int y0) {
	if (jump > 0 && jump < 25) {

		gotoXY(38, y0 - 4 - height); printf("     ");
		gotoXY(35, y0 - 3 - height); printf("     ");
		gotoXY(26, y0 - 2 - height); printf("          ");
		gotoXY(29, y0 - height);     printf("     ");
	}
	else {
		gotoXY(36, y0 - 6 - height); printf("      ");
		gotoXY(35, y0 - 5 - height); printf("      ");
		gotoXY(38, y0 - 4 - height); printf("      ");
	}
}

// Sử lí va chạm Player với Obstancle
int CheckCollision(int height, int obstancle, int obstanclePosition, int y0) {
	// Dùng mảng 2 chiều int xy[100][21]: Nếu xy[x0, y0] bằng 1 tức là tại cột x0, 
	// dòng y0 có đồ họa của khủng long, ngược lại xy[x0, y0] bằng 0.

	int xy[100][21];
	for (int i = 1; i <= 99; i++)
	{
		for (int j = 1; j <= 20; j++)
		{
			xy[i][j] = 0;
		}
	}

	xy[38][y0 - 4 - height] = 1;
	xy[25][y0 - 3 - height] = 1;
	xy[35][y0 - 3 - height] = 1;
	xy[36][y0 - 3 - height] = 1;
	xy[37][y0 - 3 - height] = 1;
	xy[26][y0 - 2 - height] = 1;
	xy[27][y0 - 2 - height] = 1;
	xy[28][y0 - 2 - height] = 1;
	xy[31][y0 - 2 - height] = 1;
	xy[32][y0 - 2 - height] = 1;
	xy[33][y0 - 2 - height] = 1;
	xy[34][y0 - 2 - height] = 1;
	xy[29][y0 - 1 - height] = 1;
	xy[30][y0 - 1 - height] = 1;
	xy[29][y0 - height] = 1;
		xy[30][y0 - height] = 1;

	switch (obstancle)
	{
	case 1:
		if (xy[obstancle]    [y0 - 4]) return 1;
		if (xy[obstancle + 1][y0 - 4]) return 1;
		if (xy[obstancle - 1][y0 - 3]) return 1;
		if (xy[obstancle - 1][y0 - 2]) return 1;
		if (xy[obstancle - 1][y0 - 1]) return 1;
		break;
	case 2:
		if (xy[obstancle - 1][y0 - 1]) return 1;
		if (xy[obstancle]    [y0 - 1]) return 1;
		if (xy[obstancle + 1][y0 - 1]) return 1;
		if (xy[obstancle + 2][y0 - 1]) return 1;
		if (xy[obstancle + 3][y0 - 1]) return 1;
		if (xy[obstancle + 4][y0 - 1]) return 1;
		if (xy[obstancle + 5][y0 - 1]) return 1;
		if (xy[obstancle + 6][y0 - 1]) return 1;
		if (xy[obstancle + 7][y0 - 1]) return 1;
		break;
	case 3:
		if (xy[obstancle - 1][y0 - 2]) return 1;
		if (xy[obstancle]    [y0 - 2]) return 1;
		if (xy[obstancle + 1][y0 - 2]) return 1;
		if (xy[obstancle + 2][y0 - 2]) return 1;
		if (xy[obstancle + 3][y0 - 2]) return 1;
		if (xy[obstancle + 4][y0 - 2]) return 1;
		if (xy[obstancle - 1][y0 - 1]) return 1;
		break;
	case 4:
		if (xy[obstancle + 3][y0 - 4]) return 1;
		if (xy[obstancle + 4][y0 - 4]) return 1;
		if (xy[obstancle + 2][y0 - 3]) return 1;
		if (xy[obstancle + 2][y0 - 2]) return 1;
		if (xy[obstancle - 1][y0 - 1]) return 1;
		if (xy[obstancle]    [y0 - 1]) return 1;
		if (xy[obstancle + 1][y0 - 1]) return 1;
		break;
	case 5:
		if (xy[obstancle - 1][y0 - 4]) return 1;
		if (xy[obstancle + 3][y0 - 4]) return 1;
		if (xy[obstancle + 4][y0 - 4]) return 1;
		if (xy[obstancle - 1][y0 - 3]) return 1;
		if (xy[obstancle - 1][y0 - 2]) return 1;
		if (xy[obstancle + 5][y0 - 2]) return 1;
		if (xy[obstancle + 6][y0 - 2]) return 1;
		if (xy[obstancle + 7][y0 - 2]) return 1;
		if (xy[obstancle - 1][y0 - 1]) return 1;
		break;
	case 6:
		if (xy[obstancle + 3][y0 - 4]) return 1;
		if (xy[obstancle + 4][y0 - 4]) return 1;
		if (xy[obstancle + 6][y0 - 4]) return 1;
		if (xy[obstancle + 7][y0 - 4]) return 1;
		if (xy[obstancle + 2][y0 - 3]) return 1;
		if (xy[obstancle + 2][y0 - 2]) return 1;
		if (xy[obstancle + 8][y0 - 2]) return 1;
		if (xy[obstancle + 9][y0 - 2]) return 1;
		if (xy[obstancle + 10][y0 - 2])return 1;
		if (xy[obstancle]     [y0 - 1])return 1;
		if (xy[obstancle + 1][y0 - 1]) return 1;
		break;
	case 7:
		if (xy[obstancle]    [y0 - 4]) return 1;
		if (xy[obstancle + 1][y0 - 4]) return 1;
		if (xy[obstancle + 3][y0 - 4]) return 1;
		if (xy[obstancle + 4][y0 - 4]) return 1;
		if (xy[obstancle + 9][y0 - 4]) return 1;
		if (xy[obstancle + 10][y0 - 4])return 1;
		if (xy[obstancle - 1][y0 - 3]) return 1;
		if (xy[obstancle - 1][y0 - 2]) return 1;
		if (xy[obstancle - 1][y0 - 1]) return 1;
		break;
	default:break;
	}
	return 0;
}

void CreateMenu(int firstColor) {

	TextColor(firstColor); // hiển thị title
	system("cls"); // xoá màn hình  
	// Tên game T-Rex Game
	gotoXY(22, 2); printf("___________         __________                     ________     ");
	gotoXY(22, 3); printf("\\__    ___/         \\______   \\ ____ ___  ___     /  _____/_____    _____   ____  ");
	gotoXY(22, 4); printf("    |  |     ______  |       _""// __ \\  \\    /    /   \\  ___\\__  \\  /     \\_/ __ \\ ");
	gotoXY(22, 5); printf("    |  |    /_____/  |    |   \\  ___/ >    <     \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/ ");
	gotoXY(22, 6); printf("    |__|             |____|_  /\\___  >__/\\_ \\     \\______  (____  /__|_|  /\\___>");
	gotoXY(22, 7); printf("                            \\/     \\/      \\/      \\/     \\/      \\/     \\/ ");

}

void Game(int firstColor, int secondColor) {
	// khai báo thuộc tính chung 
	
	int y0 = 20;
	int frameCount, frameTime, highScore = 0;
	int height{}, jump{};
	int obstancle{}, obstanclePosition{};
	int tmp;
	char input{};
	char ground[3][121];

	// Sét vật ở nền
	Initialize(ground);
	//// sét điểm từ file
	//FILE* memory = fopen("memory.txt", "r");
	//fscanf(memory, "%d", +&highScore);
	//fclose(memory);

	// Khởi tạo giao diện chính
	CreateMenu(firstColor);
	// Hiện thị nền
	DrawGround(ground, y0);
	// Hiện thị nhân vật
	DrawPlayer(0, 3, y0);
	// Hiện thị điểm cao nhất
	gotoXY(60, 10); printf("Score High: %d", highScore);
	gotoXY(119, 25);
	
	
	while (true)
	{
	gameStart:

		frameCount = 0;
		frameTime = 10;
		jump = 0;
		obstancle = 0;

		do {
			input = inputKey();
			if (input == 27) { // esc
				system("cls");
				return;
			}
		// ấn space để chơi game
		} while (input != 32);
		system("cls");
		// -- Xử lí luồng Game -- //
		while (true)
		{
			system("cls");
			// Hiển thị thông báo và điểm
			gotoXY(50,  1);  printf("Press Ecs to quit game !");
			gotoXY(100, 1); printf("Highs: %d", highScore);
			gotoXY(100, 2); printf("Score: %d", frameCount);

			// xoá màn đã vẽ
			//DeleteObstacle(obstancle, obstanclePosition, y0);
			//HandingPlayer(jump, height, y0);

			TextColor(firstColor);

			// Tạo nền di chuyển
			MoveGround(ground);

			// Spawn chướng ngại vật
			if (obstancle == 0) {
				tmp = random(100);
				if (tmp <= 7) {
					obstancle = tmp;
					obstanclePosition = 120;
				}
			}
			else {
				obstanclePosition--;
			}
			if (obstanclePosition == 1) {
				DrawObstacle(obstancle, 1, y0, 0);
				obstancle = 0;
				TextColor(firstColor);
			}

			// Nhảy cho player
			height = (50 - jump) * jump / 60;
			if ((jump < 50) && (jump != 0)) {
				jump++;
			}
			else {
				jump = 0;
			}
			// Hiển thị các object trên màn hình
			DrawGround(ground, y0);
			DrawObstacle(obstancle, obstanclePosition, y0, firstColor);
			DrawPlayer(height, 1 + frameCount % 2, y0);

			// Kiểm tra va chạm 
			if (obstanclePosition <= 39) {
				if (CheckCollision(height, obstancle, obstanclePosition, y0)) {
					// thay đổi con mắt của Player
					gotoXY(36, y0 - 5 - height); printf("x  ");
					gotoXY(57, 10); printf("Game Over !\n");
					gotoXY(45, 12); printf("Press Space to play again or Esc to exit !");
					

					if (highScore < frameCount) {
						// sét mới highScore
						highScore = frameCount;

						// set xong thì lưu nó vào file memory
						/*FILE* memory = fopen("memory.txt", "w");
						fprintf(memory, "%d", highScore);
						fclose(memory);*/
					}
					goto gameStart; // gọi đến gameStart 
				}
			}

			// Kiểm tra Input
			if (_kbhit()) {
				input = _getch();
				// ấn phím Space
				if ((input == 32) && (jump == 0)) {
					jump = 1;
				}
				// esc
				if (input == 27) {
					system("cls");
					return;
				}
			}

			Sleep(frameTime);
			frameCount++;
			if ((frameCount % 600 == 0) && (frameTime > 2)) {
				frameTime--;
			}
		}
	}
}

int main()
{
	int firstColor = 7, secondColor = 60;
	Game(firstColor, secondColor);
}