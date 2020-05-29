//1712822 - NGUYEN KHANH TOAN - 17CNTN
//game.cpp
#include"Game.h"

//////////////////////////////////////////////////
///////////////////////////////FOR MENU OF GAME
void CGAME::draw_C(int x, int y) {
	GotoXY(x, y); // 17 10
	printf("%c", 219);
	GotoXY(x + 1, y);
	printf("%c", 219);
	GotoXY(x + 2, y);
	printf("%c", 219);
	GotoXY(x + 3, y);
	printf("%c", 219);
	GotoXY(x, y + 1);
	printf("%c", 219);
	GotoXY(x, y + 2);
	printf("%c", 219);
	GotoXY(x, y + 3);
	printf("%c", 219);
	GotoXY(x, y + 4);
	printf("%c", 219);
	GotoXY(x, y + 5);
	printf("%c", 219);
	GotoXY(x + 1, y + 5);
	printf("%c", 219);
	GotoXY(x + 2, y + 5);
	printf("%c", 219);
	GotoXY(x + 3, y + 5);
	printf("%c", 219);
}
void CGAME::draw_R(int x, int y) {
	GotoXY(x, y);
	printf("%c", 219);
	GotoXY(x + 1, y);
	printf("%c", 219);
	GotoXY(x + 2, y);
	printf("%c", 219);
	GotoXY(x + 3, y);
	printf("%c", 219);
	GotoXY(x, y + 1);
	printf("%c", 219);
	GotoXY(x, y + 2);
	printf("%c", 219);
	GotoXY(x, y + 3);
	printf("%c", 219);
	GotoXY(x, y + 4);
	printf("%c", 219);
	GotoXY(x, y + 5);
	printf("%c", 219);
	GotoXY(x + 1, y + 2);
	printf("%c", 219);
	GotoXY(x + 2, y + 2);
	printf("%c", 219);
	GotoXY(x + 3, y + 2);
	printf("%c", 219);
	GotoXY(x + 3, y + 1);
	printf("%c", 219);
	// 
	GotoXY(x + 1, y + 3);
	printf("%c", 219);
	GotoXY(x + 2, y + 4);
	printf("%c", 219);
	GotoXY(x + 3, y + 5);
	printf("%c", 219);
}
void CGAME::draw_O(int x, int y) {
	GotoXY(x, y);
	for (int i = 0; i < 4; i++) {
		printf("%c", 219);
	}
	GotoXY(x, y + 5);
	for (int i = 0; i < 4; i++) {
		printf("%c", 219);
	}
	for (int i = 0; i < 4; i++) {
		GotoXY(x, y + 1 + i);
		printf("%c", 219);
	}
	for (int i = 0; i < 4; i++) {
		GotoXY(x + 3, y + 1 + i);
		printf("%c", 219);
	}
}
void CGAME::draw_S(int x, int y) {
	GotoXY(x, y);
	for (int i = 0; i < 4; i++) {
		printf("%c", 219);
	}
	GotoXY(x, y + 3);
	for (int i = 0; i < 4; i++) {
		printf("%c", 219);
	}
	GotoXY(x, y + 1);
	printf("%c", 219);
	GotoXY(x, y + 2);
	printf("%c", 219);
	GotoXY(x, y + 5);
	for (int i = 0; i < 4; i++) {
		printf("%c", 219);
	}
	GotoXY(x + 3, y + 4);
	printf("%c", 219);
}
void CGAME::draw_T(int x, int y) {
	GotoXY(x, y);
	for (int i = 0; i < 5; i++) {
		printf("%c", 219);
	}
	for (int i = 0; i < 5; i++) {
		GotoXY(x + 2, y + 1 + i);
		printf("%c", 219);
	}
}
void CGAME::draw_H(int x, int y) {
	for (int i = 0; i < 6; i++) {
		GotoXY(x, y + i);
		printf("%c", 219);
	}
	GotoXY(x + 1, y + 3);
	printf("%c", 219);
	GotoXY(x + 2, y + 3);
	printf("%c", 219);
	for (int i = 0; i < 6; i++) {
		GotoXY(x + 3, y + i);
		printf("%c", 219);
	}
}
void CGAME::draw_E(int x, int y) {
	GotoXY(x, y);
	for (int i = 0; i < 4; i++) {
		printf("%c", 219);
	}
	GotoXY(x, y + 1);
	printf("%c", 219);
	GotoXY(x, y + 2);
	printf("%c", 219);
	GotoXY(x, y + 3);
	for (int i = 0; i < 4; i++) {
		printf("%c", 219);
	}
	GotoXY(x, y + 4);
	printf("%c", 219);
	GotoXY(x, y + 5);
	for (int i = 0; i < 4; i++) {
		printf("%c", 219);
	}
}
void CGAME::draw_A(int x, int y) {
	for (int i = 0; i < 6; i++) {
		GotoXY(x, y + i);
		printf("%c", 219);
	}
	GotoXY(x + 1, y);
	printf("%c", 219);
	GotoXY(x + 2, y);
	printf("%c", 219);
	GotoXY(x + 1, y + 3);
	printf("%c", 219);
	GotoXY(x + 2, y + 3);
	printf("%c", 219);
	for (int i = 0; i < 6; i++) {
		GotoXY(x + 3, y + i);
		printf("%c", 219);
	}
}
void CGAME::chooseThinking(const int &choose) {
	if (choose == 1) {
		TextColor(11);
		GotoXY(43, 19);
		printf("\t\t   START GAME");
		GotoXY(43, 21);
		printf("\t\t   LOAD GAME");
		GotoXY(43, 23);
		printf("\t\t   SETTINGS");
		GotoXY(43, 26);
		printf("\t\t   EXIT GAME");
		TextColor(12);
		GotoXY(43, 19);
		printf("\t\t   START GAME");
	}
	else if (choose == 2) {
		TextColor(11);
		GotoXY(43, 19);
		printf("\t\t   START GAME");
		GotoXY(43, 21);
		printf("\t\t   LOAD GAME");
		GotoXY(43, 23);
		printf("\t\t   SETTINGS");
		GotoXY(43, 26);
		printf("\t\t   EXIT GAME");
		TextColor(12);
		GotoXY(43, 21);
		printf("\t\t   LOAD GAME");
	}
	else if (choose == 3) {
		TextColor(11);
		GotoXY(43, 19);
		printf("\t\t   START GAME");
		GotoXY(43, 21);
		printf("\t\t   LOAD GAME");
		GotoXY(43, 23);
		printf("\t\t   SETTINGS");
		GotoXY(43, 26);
		printf("\t\t   EXIT GAME");
		TextColor(12);
		GotoXY(43, 23);
		printf("\t\t   SETTINGS");
	}
	else {
		TextColor(11);
		GotoXY(43, 19);
		printf("\t\t   START GAME");
		GotoXY(43, 21);
		printf("\t\t   LOAD GAME");
		GotoXY(43, 23);
		printf("\t\t   SETTINGS");
		GotoXY(43, 26);
		printf("\t\t   EXIT GAME");
		TextColor(12);
		GotoXY(43, 26);
		printf("\t\t   EXIT GAME");
	}
}

void CGAME::chooseThinkingSettings(const int &choose) {
	if (choose == 1) {
		TextColor(11);
		GotoXY(43, 19);
		printf("\t\t LEVEL 1");
		GotoXY(43, 21);
		printf("\t\t LEVEL 2");
		GotoXY(43, 23);
		printf("\t\t MUTE");
		TextColor(12);
		GotoXY(43, 19);
		printf("\t\t LEVEL 1");
	}
	else if (choose == 2) {
		TextColor(11);
		GotoXY(43, 19);
		printf("\t\t LEVEL 1");
		GotoXY(43, 21);
		printf("\t\t LEVEL 2");
		GotoXY(43, 23);
		printf("\t\t MUTE");
		TextColor(12);
		GotoXY(43, 21);
		printf("\t\t LEVEL 2");
	}
	else if (choose == 3) {
		TextColor(11);
		GotoXY(43, 19);
		printf("\t\t LEVEL 1");
		GotoXY(43, 21);
		printf("\t\t LEVEL 2");
		GotoXY(43, 23);
		printf("\t\t MUTE");
		TextColor(12);
		GotoXY(43, 23);
		printf("\t\t MUTE");
	}
}


void CGAME::chooseYesNoThinking(const int &choose) {
	if (choose == 1) {
		TextColor(12);
		GotoXY(32, 55);
		printf("YES");
		GotoXY(50, 55);
		printf("NO");
		TextColor(11);
		GotoXY(32, 55);
		printf("YES");
	}
	else if (choose == 2) {
		TextColor(12);
		GotoXY(32, 55);
		printf("YES");
		GotoXY(50, 55);
		printf("NO");
		TextColor(11);
		GotoXY(50, 55);
		printf("NO");
	}
}

void CGAME::drawMenu() {
	system("cls");
	TextColor(14);
	draw_C(30, 10);
	draw_R(35, 10);
	draw_O(40, 10);
	draw_S(45, 10);
	draw_S(50, 10);
	draw_T(58, 10);
	draw_H(64, 10);
	draw_E(69, 10);
	draw_R(79, 10);
	draw_O(84, 10);
	draw_A(89, 10);
	draw_O(94, 10);
	////////////
	///Draw Author
	TextColor(14);
	GotoXY(47, 34);
	printf("Version 1.0 - Release 01-12-2018");
	GotoXY(42, 36);
	printf("Author: Nguyen Khanh Toan - 17CNTN - HCMUS");
	////////////
	///Draw Menu
	TextColor(12);
	GotoXY(42, 18);
	printf("%c", 218);
	GotoXY(42, 25);
	printf("%c", 195);
	GotoXY(42, 28);
	printf("%c", 192);
	GotoXY(83, 18);
	printf("%c", 191);
	GotoXY(83, 25);
	printf("%c", 180);
	GotoXY(83, 28);
	printf("%c", 217);
	for (int i = 43; i <= 82; i++)
	{
		GotoXY(i, 18);
		printf("%c", 196);
		GotoXY(i, 25);
		printf("%c", 196);
		GotoXY(i, 28);
		printf("%c", 196);
	}

	for (int i = 19; i <= 24; i++)
	{
		GotoXY(42, i);
		printf("%c", 179);
		GotoXY(83, i);
		printf("%c", 179);

	}

	for (int i = 26; i <= 27; i++)
	{
		GotoXY(42, i);
		printf("%c", 179);
		GotoXY(83, i);
		printf("%c", 179);
	}
	GotoXY(43, 19);
	printf("\t\t   START GAME");
	GotoXY(43, 21);
	printf("\t\t   LOAD GAME");
	GotoXY(43, 23);
	printf("\t\t   SETTINGS");
	GotoXY(43, 26);
	printf("\t\t   EXIT GAME");
	int choose = 1;
	chooseThinking(choose);
	while (1) {
		char key = _getch();
		if (int(key == 72)) {
			choose--;
			if (choose == 0) {
				choose = 4;
			}
			chooseThinking(choose);
		}
		else if (int(key == 80)) {
			choose++;
			if (choose == 5) {
				choose = 1;
			}
			chooseThinking(choose);
		}
		else if ((int)key == 13) {
			if (choose == 4) {
				system("cls");
				exit(0);
				return;
			}
			else if (choose == 1) {
				system("cls");
				this->showLoadingFF();
				Sleep(750);
				system("cls");
				this->drawGame();
				break;
			}
			else if (choose == 2) {
				GotoXY(43, 19);
				printf("\t\t              ");
				GotoXY(43, 21);
				printf("\t\t             ");
				GotoXY(43, 23);
				printf("\t\t             ");
				GotoXY(43, 26);
				printf("\t\t             ");
				TextColor(11);
				GotoXY(43, 19);
				printf("\t Enter The Name of File Below :");
				GotoXY(43, 21);
				printf("\t Name : ");
				string t;
				cin >> t;
				system("cls");
				this->loadGameStart(t);
				return;
			}
			else if (choose == 3) {
				GotoXY(43, 19);
				printf("\t\t              ");
				GotoXY(43, 21);
				printf("\t\t             ");
				GotoXY(43, 23);
				printf("\t\t             ");
				GotoXY(43, 26);
				printf("\t\t             ");
				TextColor(11);
				GotoXY(43, 19);
				printf("\t\t LEVEL 1");
				GotoXY(43, 21);
				printf("\t\t LEVEL 2");
				GotoXY(43, 23);
				printf("\t\t MUTE");
				int choose2 = 1;
				chooseThinkingSettings(choose2);
				while (1) {
					char key = _getch();
					if (int(key == 72)) {
						choose2--;
						if (choose2 == 0) {
							choose2 = 3;
						}
						chooseThinkingSettings(choose2);
					}
					else if (int(key == 80)) {
						choose2++;
						if (choose2 == 4) {
							choose2 = 1;
						}
						chooseThinkingSettings(choose2);
					}
					else if ((int)key == 13) {
						if (choose2 == 1) {
							this->level = 1;
							this->startGame();
							return;
						}
						else if (choose2 == 2) {
							this->level = 2;
							this->startGame();
							return;
						}
						else if (choose2 == 3) {
							this->mute = true;
							this->startGame();
							return;
						}
					}
				}
			}
		}
	}
}
void CGAME::showLoadingFF() {
	TextColor(14);
	GotoXY(35, 10);
	drawUpperline(12);
	GotoXY(35, 14);
	drawLowerline(12);

	char character = 179; // |

	for (int i = 11; i < 14; i++) {
		GotoXY(35, i);
		printf("%c", character);
		GotoXY(87, i);
		printf("%c", character);
	}
	TextColor(12);
	GotoXY(53, 12);
	printf("LOADING GAME...50 / 100");
}
//////////////////////////////////////////////////
///////////////////////////////FOR GAME

void CGAME::drawLaneMenuPlaying(int x, int y) {
	char character2 = 196;
	GotoXY(x + 1, y);
	for (int i = 91; i <= 117; i++) {
		printf("%c", character2);
	}
	GotoXY(x + 1, y - 4);
	for (int i = 91; i <= 117; i++) {
		printf("%c", character2);
	}
}
void CGAME::drawGame(){
	//Ve khung
	TextColor(14);
	GotoXY(4, 4);
	drawUpperline(18);
	GotoXY(4, 44);
	drawLowerline(18);

	char character = 179; // |

	for (int i = 5; i < 44; i++) {
		GotoXY(4, i);
		printf("%c", character);
		GotoXY(80, i);
		printf("%c", character);
	}

	//Ve lan 
	drawALane(4, 44);
	drawForest(4, 38);
	drawForest(4, 34);
	drawALane(4, 30);
	drawALane(4, 24);
	drawForest(4, 18);
	drawForest(4, 14);
	drawALane(4, 10);

	//Ve nguoi
	cn->Draw(cn->mX, cn->mY);

	//Ve den giao thong
	for (int i = 0; i < lane.size(); i++) {
		lane[i].light.draw(0);
	}
	
	//Ve menu khi dang choi game
	TextColor(11);
	GotoXY(90, 4);
	drawUpperline(6);
	GotoXY(90, 44);
	drawLowerline(6);

	for (int i = 5; i < 44; i++) {
		GotoXY(90, i);
		printf("%c", character);
		GotoXY(118, i);
		printf("%c", character);
	}

	drawLaneMenuPlaying(90, 8);
	drawLaneMenuPlaying(90, 12);
	drawLaneMenuPlaying(90, 16);
	drawLaneMenuPlaying(90, 20);
	drawLaneMenuPlaying(90, 24);
	drawLaneMenuPlaying(90, 28);
	drawLaneMenuPlaying(90, 32);
	drawLaneMenuPlaying(90, 36);
	GotoXY(99, 6);
	printf("%c%c%c %s", 24, 24, 24, "MOVE UP");
	GotoXY(99, 10);
	printf("%c%c%c %s", 25, 25, 25, "MOVE DOWN");
	GotoXY(99, 14);
	printf("%c%c%c %s", 26, 26, 26, "MOVE RIGHT");
	GotoXY(99, 18);
	printf("%c%c%c %s", 27, 27, 27, "MOVE LEFT");
	GotoXY(99, 22);
	printf("%s : %s", "L", "SAVE GAME");
	GotoXY(99, 26);
	printf("%s : %s", "T", "LOAD GAME");
	GotoXY(99, 30);
	printf("%s : %s", "P", "PAUSE GAME");
	GotoXY(99, 34);
	printf("%s : %s", "E", "EXIT GAME");
	GotoXY(100, 40);
	printf(" LEVEL %d ", this->level);
}

void CGAME::drawUpperline(int u)
{
	char character1 = 218;
	char character2 = 196;
	char character4 = 191;

	printf("%c%c", character1, character2);
	for (int i = 0; i < u; ++i)
		printf("%c%c%c%c", character2, character2, character2, character2);
	printf("%c%c%c\n", character2, character2, character4);
}

void CGAME::drawLowerline(int u)
{
	char character1 = 192;
	char character2 = 196;
	char character4 = 217;

	printf("%c%c", character1, character2);
	for (int i = 0; i < u; ++i)
		printf("%c%c%c%c", character2, character2, character2, character2);
	printf("%c%c%c", character2, character2, character4);
}

void CGAME::drawALane(int x, int y) {
	char character2 = 196;
	GotoXY(x + 1, y);
	for (int i = 5; i <= 79; i++) {
		printf("%c", character2);
	}
	int uy = y - 6;
	GotoXY(x + 1, uy);
	for (int i = 5; i <= 79; i++) {
		printf("%c", character2);
	}
	int my = y - 3;
	GotoXY(x + 1, my);
	for (int i = 5; i <= 79; i++) {
		if (i % 8<4) printf("%c", character2);
		else printf(" ");
	}
}

void CGAME::drawForest(int x, int y) {
	char character2 = 196;
	GotoXY(x + 1, y);
	for (int i = 5; i <= 79; i++) {
		printf("%c", character2);
	}
	GotoXY(x + 1, y - 4);
	for (int i = 5; i <= 79; i++) {
		printf("%c", character2);
	}
}

//////////////////////////////////////////////////
///////////////////////////////FOR FUNCTION OF GAME
//For load Game
string CGAME::drawMenuLoad() {
	TextColor(14);
	GotoXY(24, 50);
	drawUpperline(8);
	GotoXY(24, 58);
	drawLowerline(8);

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf("%c", character);
		GotoXY(60, i);
		printf("%c", character);
	}
	TextColor(12);
	GotoXY(36, 48);
	printf("Load The Game");
	GotoXY(27, 51);
	printf("Enter The Name of File Below : ");
	GotoXY(32, 55);
	printf("Name : ");
	string s;
	cin >> s;
	return s;
}
void CGAME::clearMenuLoad(){
	GotoXY(24, 50);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}
	GotoXY(24, 58);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf("  ");
		GotoXY(60, i);
		printf("  ");
	}
	GotoXY(36, 48);
	printf("                      ");
	GotoXY(27, 51);
	printf("                                        ");
	GotoXY(32, 55);
	printf("                                          ");
}
//For save Game
string CGAME::drawMenuSave() {
	TextColor(14);
	GotoXY(24, 50);
	drawUpperline(8);
	GotoXY(24, 58);
	drawLowerline(8);

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf("%c", character);
		GotoXY(60, i);
		printf("%c", character);
	}
	TextColor(12);
	GotoXY(36, 48);
	printf("Save The Game");
	GotoXY(27, 51);
	printf("Enter The Name of File Below : ");
	GotoXY(32, 55);
	printf("Name : ");
	string s;
	cin >> s;
	return s;
}
void CGAME::clearMenuSave() {
	GotoXY(24, 50);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}
	GotoXY(24, 58);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf("  ");
		GotoXY(60, i);
		printf("  ");
	}
	GotoXY(36, 48);
	printf("                     ");
	GotoXY(27, 51);
	printf("                                               ");
	GotoXY(32, 55);
	printf("                                               ");
}
//For pause game
void CGAME::drawMenuPause() {
	TextColor(14);
	GotoXY(24, 50);
	drawUpperline(8);
	GotoXY(24, 58);
	drawLowerline(8);

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf("%c", character);
		GotoXY(60, i);
		printf("%c", character);
	}
	TextColor(12);
	GotoXY(36, 48);
	printf("Game Is Pausing");
	GotoXY(27, 51);
	printf("Do You Want To Resume The Game?");
	GotoXY(32, 55);
	printf("YES");
	GotoXY(50, 55);
	printf("NO");
}
void CGAME::clearMenuPause() {
	GotoXY(24, 50);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}
	GotoXY(24, 58);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf(" ");
		GotoXY(60, i);
		printf(" ");
	}
	GotoXY(36, 48);
	printf("                ");
	GotoXY(27, 51);
	printf("                                    ");
	GotoXY(32, 55);
	printf("        ");
	GotoXY(50, 55);
	printf("         ");
}
//for exit game
void CGAME::drawExitGame() {
	TextColor(14);
	GotoXY(24, 50);
	drawUpperline(8);
	GotoXY(24, 58);
	drawLowerline(8);

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf("%c", character);
		GotoXY(60, i);
		printf("%c", character);
	}
	TextColor(12);
	GotoXY(36, 48);
	printf("Game Is Pausing");
	GotoXY(27, 51);
	printf("Do You Really Want To Exit Game?");
	GotoXY(32, 55);
	printf("YES");
	GotoXY(50, 55);
	printf("NO");
}
void CGAME::clearExitGame() {
	GotoXY(24, 50);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}
	GotoXY(24, 58);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf(" ");
		GotoXY(60, i);
		printf(" ");
	}
	GotoXY(36, 48);
	printf("                                      ");
	GotoXY(27, 51);
	printf("                                      ");
	GotoXY(32, 55);
	printf("     ");
	GotoXY(50, 55);
	printf("     ");
}
//For dead
void CGAME::drawLoseGame() {
	TextColor(14);
	GotoXY(24, 50);
	drawUpperline(8);
	GotoXY(24, 58);
	drawLowerline(8);

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf("%c", character);
		GotoXY(60, i);
		printf("%c", character);
	}
	TextColor(12);
	GotoXY(30, 48);
	printf("Accident! Police is coming!");
	GotoXY(27, 51);
	printf("Do You Want To Start A New Game?");
	GotoXY(32, 55);
	printf("YES");
	GotoXY(50, 55);
	printf("NO");
}
void CGAME::clearLoseGame() {
	GotoXY(24, 50);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}
	GotoXY(24, 58);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf(" ");
		GotoXY(60, i);
		printf(" ");
	}
	GotoXY(29, 48);
	printf("                                      ");
	GotoXY(27, 51);
	printf("                                      ");
	GotoXY(32, 55);
	printf("         ");
	GotoXY(50, 55);
	printf("        ");
}
void CGAME::drawWinFinal() {
	TextColor(14);
	GotoXY(24, 50);
	drawUpperline(8);
	GotoXY(24, 58);
	drawLowerline(8);

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf("%c", character);
		GotoXY(60, i);
		printf("%c", character);
	}
	TextColor(12);
	GotoXY(33, 48);
	printf("You Win This Game");
	GotoXY(25, 51);
	printf("Congratulation! Thanks For Playing!");
	GotoXY(27, 53);
	printf("Please Waiting For New Version!");
	GotoXY(80, 51);
}
void CGAME::drawWinGame() {
	TextColor(14);
	GotoXY(24, 50);
	drawUpperline(8);
	GotoXY(24, 58);
	drawLowerline(8);

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf("%c", character);
		GotoXY(60, i);
		printf("%c", character);
	}
	TextColor(12);
	GotoXY(33, 48);
	printf("You Win This Level");
	GotoXY(30, 51);
	printf("Do You Want To Continue?");
	GotoXY(32, 55);
	printf("YES");
	GotoXY(50, 55);
	printf("NO");
}
void CGAME::clearWinGame() {
	GotoXY(24, 50);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}
	GotoXY(24, 58);
	for (int i = 24; i <= 70; i++) {
		printf(" ");
	}

	char character = 179; // |

	for (int i = 51; i < 58; i++) {
		GotoXY(24, i);
		printf(" ");
		GotoXY(60, i);
		printf(" ");
	}
	GotoXY(33, 48);
	printf("                                      ");
	GotoXY(27, 51);
	printf("                                            ");
	GotoXY(32, 55);
	printf("             ");
	GotoXY(50, 55);
	printf("             ");
}