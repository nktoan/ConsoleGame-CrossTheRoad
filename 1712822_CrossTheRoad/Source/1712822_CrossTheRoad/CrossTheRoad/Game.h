//1712822 - NGUYEN KHANH TOAN - 17CNTN
//game.h
#ifndef  GAME_H
#define GAME_H
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include"People.h"
#include<string>
#include<fstream>
#include"Animal.h"
#pragma comment (lib, "winmm.lib")

using namespace std;

class CGAME {
public:
	bool IS_RUNNING;
public:
	vector<CLane> lane;
	CPEOPLE *cn;
	vector<CAniLane>  Anilane;
	bool mute; //true if not have music
	int level; //1,2 
	CPOLICE *police;
public:
	CGAME() {
		//CLane l1(43), l2(40), l3(29), l4(26), l5(23), l6(20), l7(9), l8(6);
		CLane l1(43), l2(40), l3(29), l4(26), l5(23), l6(20), l7(9), l8(6);
		lane.push_back(l1); lane.push_back(l2); lane.push_back(l3); lane.push_back(l4);
		lane.push_back(l5); lane.push_back(l6); lane.push_back(l7); lane.push_back(l8);
		CAniLane al1(37), al2(33), al3(17), al4(13);
		Anilane.push_back(al1); Anilane.push_back(al2); Anilane.push_back(al3); Anilane.push_back(al4);
		cn = new CPEOPLE;
		IS_RUNNING = true;
		mute = false;
		level = 1;
		police = new CPOLICE(77, 46);
	}
	~CGAME() {
		for (int j = 0; j < lane.size(); j++) {
			for (int i = 0; i < lane[j].LVehicle.size(); i++) {
				lane[j].LVehicle[i]->clear(lane[j].LVehicle[i]->mx, lane[j].LVehicle[i]->my);
				delete lane[j].LVehicle[i];
			}
			lane[j].LVehicle.clear();
		}
		lane.clear();
		for (int j = 0; j < Anilane.size(); j++) {
			for (int i = 0; i < Anilane[j].LAnimal.size(); i++) {
				Anilane[j].LAnimal[i]->clear(Anilane[j].LAnimal[i]->mx, Anilane[j].LAnimal[i]->my);
				delete Anilane[j].LAnimal[i];
			}
			Anilane[j].LAnimal.clear();
		}
		delete police;
		Anilane.clear();
		delete cn;
	}
	CPEOPLE* getPeople() {
		return cn;
	}
	void clearAllGame() {
		for (int j = 0; j < lane.size(); j++) {
			for (int i = 0; i < lane[j].LVehicle.size(); i++) {
				lane[j].LVehicle[i]->clear(lane[j].LVehicle[i]->mx, lane[j].LVehicle[i]->my);
				delete lane[j].LVehicle[i];
			}
			lane[j].LVehicle.clear();
		}
		lane.clear();
		for (int j = 0; j < Anilane.size(); j++) {
			for (int i = 0; i < Anilane[j].LAnimal.size(); i++) {
				Anilane[j].LAnimal[i]->clear(Anilane[j].LAnimal[i]->mx, Anilane[j].LAnimal[i]->my);
				delete Anilane[j].LAnimal[i];
			}
			Anilane[j].LAnimal.clear();
		}
		Anilane.clear();
		delete cn;
	}
private:
	//For draw Menu
	void draw_C(int x, int y);
	void draw_R(int x, int y);
	void draw_O(int x, int y);
	void draw_S(int x, int y);
	void draw_T(int x, int y);
	void draw_H(int x, int y);
	void draw_E(int x, int y);
	void draw_A(int x, int y);
	void chooseThinking(const int &choose);
	//For Loading
	void showLoadingFF();
	//For draw Game
	void drawUpperline(int u);
	void drawLowerline(int u);
	void drawALane(int x, int y);
	void drawForest(int x, int y);
	//For draw Menu in Game
	void drawLaneMenuPlaying(int x, int y);
	
	//For draw function of Game
	//For load Game
	string drawMenuLoad();
	void clearMenuLoad();
	//For save Game
	string drawMenuSave();
	void clearMenuSave();
	//For pause game
	void drawMenuPause();
	void clearMenuPause();
	//for exit game
	void drawExitGame();
	void clearExitGame();
	//for lose game
	void drawLoseGame();
	void clearLoseGame();
	//
	void drawWinFinal();
	void drawWinGame();
	void clearWinGame();
	//
	void chooseYesNoThinking(const int &choose);
	void chooseThinkingSettings(const int &choose);
public:
	void drawMenu();
	void drawGame();

	void exitGame(HANDLE t) {
		SuspendThread(t);
		this->drawExitGame();
		GotoXY(32, 55);
		printf("YES");
		GotoXY(50, 55);
		printf("NO");
		int choose = 1;
		chooseYesNoThinking(choose);
		while (1) {
			char key = _getch();
			if (int(key == 77)) {
				choose++;
				if (choose == 3) {
					choose = 1;
				}
				chooseYesNoThinking(choose);
			}
			else if (int(key == 75)) {
				choose--;
				if (choose == 0) {
					choose = 2;
				}
				chooseYesNoThinking(choose);
			}
			else if ((int)key == 13) {
				if (choose == 1) {
					this->clearExitGame();
					system("cls");
					IS_RUNNING = false;
					exit(0);
					return;
				}
				else {
					this->clearExitGame();
					ResumeThread(t);
					return;
				}
			}
		}
	}
	void startGame() {
		this->drawMenu();
		if (this->level == 1) {
			for (int i = 0; i < 8; i++) {
				lane[i].MaxVehicle = 2;
			}
			for (int i = 0; i < 4; i++) {
				Anilane[i].MaxAnimal = 1;
			}
		}
		else if (this->level == 2) {
			for (int i = 0; i < 8; i++) {
				lane[i].MaxVehicle = 3;
			}
			for (int i = 0; i < 4; i++) {
				Anilane[i].MaxAnimal = 2;
			}
		}
		this->drawGame();
	}
	void winGame(HANDLE t) {
		IS_RUNNING = false;
		SuspendThread(t);
		if (this->level == 1) {
			this->drawWinGame();
			GotoXY(32, 55);
			printf("YES");
			GotoXY(50, 55);
			printf("NO");
			int choose = 1;
			chooseYesNoThinking(choose);
			while (1) {
				char key = _getch();
				if (int(key == 77)) {
					choose++;
					if (choose == 3) {
						choose = 1;
					}
					chooseYesNoThinking(choose);
				}
				else if (int(key == 75)) {
					choose--;
					if (choose == 0) {
						choose = 2;
					}
					chooseYesNoThinking(choose);
				}
				else if ((int)key == 13) {
					if (choose == 1) {
						this->level++;
						this->clearWinGame();
						if (cn != NULL) {
							cn->Clear(cn->mX, cn->mY);
							delete cn;
						}
						cn = new CPEOPLE;
						for (int j = 0; j < lane.size(); j++) {
							for (int i = 0; i < lane[j].LVehicle.size(); i++) {
								lane[j].LVehicle[i]->clear(lane[j].LVehicle[i]->mx, lane[j].LVehicle[i]->my);
								delete lane[j].LVehicle[i];
							}
							lane[j].LVehicle.clear();
						}
						lane.clear();
						for (int j = 0; j < Anilane.size(); j++) {
							for (int i = 0; i < Anilane[j].LAnimal.size(); i++) {
								Anilane[j].LAnimal[i]->clear(Anilane[j].LAnimal[i]->mx, Anilane[j].LAnimal[i]->my);
								delete Anilane[j].LAnimal[i];
							}
							Anilane[j].LAnimal.clear();
						}
						Anilane.clear();
						CLane l1(43), l2(40), l3(29), l4(26), l5(23), l6(20), l7(9), l8(6);
						lane.push_back(l1); lane.push_back(l2); lane.push_back(l3); lane.push_back(l4);
						lane.push_back(l5); lane.push_back(l6); lane.push_back(l7); lane.push_back(l8);
						CAniLane al1(37), al2(33), al3(17), al4(13);
						Anilane.push_back(al1); Anilane.push_back(al2); Anilane.push_back(al3); Anilane.push_back(al4);
						for (int i = 0; i < 8; i++) {
							lane[i].MaxVehicle = 3;
						}
						for (int i = 0; i < 4; i++) {
							Anilane[i].MaxAnimal = 2;
						}
						if (!this->mute) mciSendStringA("play MusicGame.mp3 repeat", NULL, 0, NULL);
						this->drawGame();
						ResumeThread(t);
						IS_RUNNING = true;
						return;
					}
					else if (choose == 2) {
						this->clearWinGame();
						system("cls");
						exit(0);
						return;
					}
				}
			}
		}
		else if (this->level==2) {
			this->drawWinFinal();
			exit(0);
			return;
		}
	}
	void loseGame(HANDLE t) {
		IS_RUNNING = false;
		SuspendThread(t);
		this->drawLoseGame();
		int toadoY = cn->mY + 1;
		police->my = toadoY;
		police->draw(police->mx, police->my);

		GotoXY(32, 55);
		printf("YES");
		GotoXY(50, 55);
		printf("NO");
		int choose = 1;
		chooseYesNoThinking(choose);
		while (1) {
			if (police->mx >= 14) {
				police->MoveLeft(4);
			}
			char key = _getch();
			if (int(key == 77)) {
				choose++;
				if (choose == 3) {
					choose = 1;
				}
				chooseYesNoThinking(choose);
			}
			else if (int(key == 75)) {
				choose--;
				if (choose == 0) {
					choose = 2;
				}
				chooseYesNoThinking(choose);
			}
			else if ((int)key == 13) {
				police->clear(police->mx, police->my);
				if (choose == 1) {
					this->clearLoseGame();
					if (cn != NULL) {
						cn->Clear(cn->mX,cn->mY);
						delete cn;
					}
					if (police != NULL) {
						police->clear(police->mx, police->my);
						delete police;
					}
					cn = new CPEOPLE;
					police = new CPOLICE(77, 46);
					for (int j = 0; j < lane.size(); j++) {
						for (int i = 0; i < lane[j].LVehicle.size(); i++) {
							lane[j].LVehicle[i]->clear(lane[j].LVehicle[i]->mx, lane[j].LVehicle[i]->my);
							delete lane[j].LVehicle[i];
						}
						lane[j].LVehicle.clear();
					}
					lane.clear();
					for (int j = 0; j < Anilane.size(); j++) {
						for (int i = 0; i < Anilane[j].LAnimal.size(); i++) {
							Anilane[j].LAnimal[i]->clear(Anilane[j].LAnimal[i]->mx, Anilane[j].LAnimal[i]->my);
							delete Anilane[j].LAnimal[i];
						}
						Anilane[j].LAnimal.clear();
					}
					Anilane.clear();
					CLane l1(43), l2(40), l3(29), l4(26), l5(23), l6(20), l7(9), l8(6);
					lane.push_back(l1); lane.push_back(l2); lane.push_back(l3); lane.push_back(l4);
					lane.push_back(l5); lane.push_back(l6); lane.push_back(l7); lane.push_back(l8);
					CAniLane al1(37), al2(33), al3(17), al4(13);
					Anilane.push_back(al1); Anilane.push_back(al2); Anilane.push_back(al3); Anilane.push_back(al4);
					if (this->level == 1) {
						for (int i = 0; i < 8; i++) {
							lane[i].MaxVehicle = 2;
						}
						for (int i = 0; i < 4; i++) {
							Anilane[i].MaxAnimal = 1;
						}
					}
					else if (this->level == 2) {
						for (int i = 0; i < 8; i++) {
							lane[i].MaxVehicle = 3;
						}
						for (int i = 0; i < 4; i++) {
							Anilane[i].MaxAnimal = 2;
						}
					}
					if (!this->mute) mciSendStringA("play MusicGame.mp3 repeat", NULL, 0, NULL);
					this->drawGame();
					ResumeThread(t);
					IS_RUNNING = true;
					return;
				}
				else {
					this->clearLoseGame();
					system("cls");
					exit(0);
					return;
				}
			}
		}
	}
	void pauseGame(HANDLE t) {
		SuspendThread(t);
		this->drawMenuPause();
		GotoXY(32, 55);
		printf("YES");
		GotoXY(50, 55);
		printf("NO");
		int choose = 1;
		chooseYesNoThinking(choose);
		while (1) {
			char key = _getch();
			if (int(key == 77)) {
				choose++;
				if (choose == 3) {
					choose = 1;
				}
				chooseYesNoThinking(choose);
			}
			else if (int(key == 75)) {
				choose--;
				if (choose == 0) {
					choose = 2;
				}
				chooseYesNoThinking(choose);
			}
			else if ((int)key == 13) {
				if (choose == 1) {
					this->clearMenuPause();
					ResumeThread(t);
					return;
				}
				else {
					this->clearMenuPause();
					IS_RUNNING = false;
					system("cls");
					exit(0);
					return;
				}
			}
		}
	}
	void resumeGame(HANDLE t) {
		char MOVING = _getch();
		this->updatePosPeople(MOVING);
		if (this->getPeople()->isImpactWithVehicle_type1(this->lane) || this->getPeople()->isImpactWithAnimal_type1(this->Anilane)) {
			this->cn->mState = false;
		}
		if (this->getPeople()->isFinish()) {
			//xu ly khi ve dich
		}
	}
	void updatePosPeople(const char &c) {
		this->cn->TuongTacPhim(c);
	}
	void updatePosVehicle() {
		lane[0].Continue(1); lane[1].Continue(0); lane[2].Continue(1); lane[3].Continue(0);
		lane[4].Continue(1); lane[5].Continue(0); lane[6].Continue(1); lane[7].Continue(0);
		Anilane[0].Continue();
		Anilane[1].Continue();
		Anilane[2].Continue();
		Anilane[3].Continue();
	}
	void loadGame(HANDLE t) { //chua  them animal
		IS_RUNNING = false;
		SuspendThread(t);
		string filename = this->drawMenuLoad();
		this->clearMenuLoad();
		//Xoa du lieu hien co
		//
		if (cn != NULL) {
			cn->Clear(cn->mX, cn->mY);
			delete cn;
		}
		cn = new CPEOPLE;
		for (int j = 0; j < lane.size(); j++) {
			for (int i = 0; i < lane[j].LVehicle.size(); i++) {
				lane[j].LVehicle[i]->clear(lane[j].LVehicle[i]->mx, lane[j].LVehicle[i]->my);
				delete lane[j].LVehicle[i];
			}
			lane[j].LVehicle.clear();
		}
		lane.clear();
		for (int j = 0; j < Anilane.size(); j++) {
			for (int i = 0; i < Anilane[j].LAnimal.size(); i++) {
				Anilane[j].LAnimal[i]->clear(Anilane[j].LAnimal[i]->mx, Anilane[j].LAnimal[i]->my);
				delete Anilane[j].LAnimal[i];
			}
			Anilane[j].LAnimal.clear();
		}
		Anilane.clear();
		CLane l1(43), l2(40), l3(29), l4(26), l5(23), l6(20), l7(9), l8(6);
		lane.push_back(l1); lane.push_back(l2); lane.push_back(l3); lane.push_back(l4);
		lane.push_back(l5); lane.push_back(l6); lane.push_back(l7); lane.push_back(l8);
		CAniLane al1(37), al2(33), al3(17), al4(13);
		Anilane.push_back(al1); Anilane.push_back(al2); Anilane.push_back(al3); Anilane.push_back(al4);
		//XU ly doc du lieu
		char* s = new char[filename.size() + 1];
		for (int i = 0; i < filename.size(); i++) {
			s[i] = filename[i];
		}
		s[filename.size()] = '\0';
		FILE *f = fopen(s, "rb");
		fread(&this->cn->mX, sizeof(int), 1, f);
		fread(&this->cn->mX, sizeof(int), 1, f);
		fread(&this->cn->mY, sizeof(int), 1, f);
		/*fscanf_s(f, "%d", &this->level);
		fscanf_s(f, "%d", &this->cn->mX);
		fscanf_s(f, "%d", &this->cn->mY);*/
		int temp;
		for (int k = 0; k < 8; k++) {
			fread(&temp,sizeof(int), 1, f);
			//fscanf_s(f, "%d", &temp);
			fread(&temp, sizeof(int), 1, f);
			//fscanf_s(f, "%d", &temp);
			if (temp == 1) {
				this->lane[k].light.active = true;
			}
			else this->lane[k].light.active = false;
			for (int i = 0; i < 3; i++) {
				int type,mx, my;
				fread(&type, sizeof(int), 1, f);
				fread(&mx, sizeof(int), 1, f);
				fread(&my, sizeof(int), 1, f);
				//fscanf_s(f, "%d", &type);
				//fscanf_s(f, "%d", &mx);
				//fscanf_s(f, "%d", &my);
				if (my == -1 || mx == -1 || type == -1) {
					continue;
				}
				else {
					CVEHICLE* p;
					if (type == 0) {
						p = new CTRUCK(mx, my);
					}
					else p = new CCAR(mx, my);
					p->draw(mx, my);
					this->lane[k].LVehicle.push_back(p);
				}
			}
		}
		for (int k = 0; k < 4; k++) {
			fread(&temp, sizeof(int), 1, f);
			//fscanf_s(f, "%d", &temp);
			for (int i = 0; i < 2; i++) {
				int type, mx, my;
				fread(&type, sizeof(int), 1, f);
				fread(&mx, sizeof(int), 1, f);
				fread(&my, sizeof(int), 1, f);
				//fscanf_s(f, "%d", &type);
				//fscanf_s(f, "%d", &mx);
				//fscanf_s(f, "%d", &my);
				if (my == -1 || mx == -1 || type == -1) {
					continue;
				}
				else {
					CANIMAL* p;
					if (type == 0) {
						p = new CDINAUSOR(mx, my);
					}
					else p = new CBIRD(mx, my);
					p->draw(mx, my);
					this->Anilane[k].LAnimal.push_back(p);
				}
			}
		}
		//Xu ly them thong tin
		if (this->level == 1) {
			for (int i = 0; i < 8; i++) {
				lane[i].MaxVehicle = 2;
			}
			for (int i = 0; i < 4; i++) {
				Anilane[i].MaxAnimal = 1;
			}
		}
		else if (this->level == 2) {
			for (int i = 0; i < 8; i++) {
				lane[i].MaxVehicle = 3;
			}
			for (int i = 0; i < 4; i++) {
				Anilane[i].MaxAnimal = 2;
			}
		}
		//Ve nguoi
		cn->Draw(cn->mX, cn->mY);

		//Ve den giao thong
		for (int i = 0; i < lane.size(); i++) {
			int temp;
			if (this->lane[i].light.active == true) temp = 0;
			else temp = 1;
			lane[i].light.draw(temp);
		}

		ResumeThread(t);
		IS_RUNNING = true;
		return;
	}
	void loadGameStart(string filename) { //chua  them animal
		//Xoa du lieu hien co
		//
		if (cn != NULL) {
			cn->Clear(cn->mX, cn->mY);
			delete cn;
		}
		cn = new CPEOPLE;
		for (int j = 0; j < lane.size(); j++) {
			for (int i = 0; i < lane[j].LVehicle.size(); i++) {
				lane[j].LVehicle[i]->clear(lane[j].LVehicle[i]->mx, lane[j].LVehicle[i]->my);
				delete lane[j].LVehicle[i];
			}
			lane[j].LVehicle.clear();
		}
		lane.clear();
		for (int j = 0; j < Anilane.size(); j++) {
			for (int i = 0; i < Anilane[j].LAnimal.size(); i++) {
				Anilane[j].LAnimal[i]->clear(Anilane[j].LAnimal[i]->mx, Anilane[j].LAnimal[i]->my);
				delete Anilane[j].LAnimal[i];
			}
			Anilane[j].LAnimal.clear();
		}
		Anilane.clear();
		CLane l1(43), l2(40), l3(29), l4(26), l5(23), l6(20), l7(9), l8(6);
		lane.push_back(l1); lane.push_back(l2); lane.push_back(l3); lane.push_back(l4);
		lane.push_back(l5); lane.push_back(l6); lane.push_back(l7); lane.push_back(l8);
		CAniLane al1(37), al2(33), al3(17), al4(13);
		Anilane.push_back(al1); Anilane.push_back(al2); Anilane.push_back(al3); Anilane.push_back(al4);
		//XU ly doc du lieu
		char* s = new char[filename.size() + 1];
		for (int i = 0; i < filename.size(); i++) {
			s[i] = filename[i];
		}
		s[filename.size()] = '\0';
		FILE *f = fopen(s, "rb");
		fread(&this->cn->mX, sizeof(int), 1, f);
		fread(&this->cn->mX, sizeof(int), 1, f);
		fread(&this->cn->mY, sizeof(int), 1, f);
		/*fscanf_s(f, "%d", &this->level);
		fscanf_s(f, "%d", &this->cn->mX);
		fscanf_s(f, "%d", &this->cn->mY);*/
		int temp;
		for (int k = 0; k < 8; k++) {
			fread(&temp,sizeof(int), 1, f);
			//fscanf_s(f, "%d", &temp);
			fread(&temp, sizeof(int), 1, f);
			//fscanf_s(f, "%d", &temp);
			if (temp == 1) {
				this->lane[k].light.active = true;
			}
			else this->lane[k].light.active = false;
			for (int i = 0; i < 3; i++) {
				int type, mx, my;
				fread(&type, sizeof(int), 1, f);
				fread(&mx, sizeof(int), 1, f);
				fread(&my, sizeof(int), 1, f);
				//fscanf_s(f, "%d", &type);
				//fscanf_s(f, "%d", &mx);
				//fscanf_s(f, "%d", &my);
				if (my == -1 || mx == -1 || type == -1) {
					continue;
				}
				else {
					CVEHICLE* p;
					if (type == 0) {
						p = new CTRUCK(mx, my);
					}
					else p = new CCAR(mx, my);
					p->draw(mx, my);
					this->lane[k].LVehicle.push_back(p);
				}
			}
		}
		for (int k = 0; k < 4; k++) {
			//fscanf_s(f, "%d", &temp);
			fread(&temp, sizeof(int), 1, f);
			for (int i = 0; i < 2; i++) {
				int type, mx, my;
				fread(&type, sizeof(int), 1, f);
				fread(&mx, sizeof(int), 1, f);
				fread(&my, sizeof(int), 1, f);
				//fscanf_s(f, "%d", &type);
				//fscanf_s(f, "%d", &mx);
				//fscanf_s(f, "%d", &my);
				if (my == -1 || mx == -1 || type == -1) {
					continue;
				}
				else {
					CANIMAL* p;
					if (type == 0) {
						p = new CDINAUSOR(mx, my);
					}
					else p = new CBIRD(mx, my);
					p->draw(mx, my);
					this->Anilane[k].LAnimal.push_back(p);
				}
			}
		}
		//Xu ly them thong tin
		if (this->level == 1) {
			for (int i = 0; i < 8; i++) {
				lane[i].MaxVehicle = 2;
			}
			for (int i = 0; i < 4; i++) {
				Anilane[i].MaxAnimal = 1;
			}
		}
		else if (this->level == 2) {
			for (int i = 0; i < 8; i++) {
				lane[i].MaxVehicle = 3;
			}
			for (int i = 0; i < 4; i++) {
				Anilane[i].MaxAnimal = 2;
			}
		}
		this->drawGame();
		//Ve nguoi
		cn->Draw(cn->mX, cn->mY);

		//Ve den giao thong
		for (int i = 0; i < lane.size(); i++) {
			int temp;
			if (this->lane[i].light.active == true) temp = 0;
			else temp = 1;
			lane[i].light.draw(temp);
		}
		return;
	}
	void saveGame(HANDLE t) { 
		SuspendThread(t);
		string filename = this->drawMenuSave();
		char* s = new char[filename.size() + 1];
		for (int i = 0; i < filename.size(); i++) {
			s[i] = filename[i];
		}
		s[filename.size()] = '\0';
		FILE *f = fopen(s, "wb");
		fwrite(&this->level, sizeof(int), 1, f);
		fwrite(&this->cn->mX, sizeof(int), 1, f);
		fwrite(&this->cn->mY, sizeof(int), 1, f);
		//fprintf(f, "%d ", this->level);
		//fprintf(f, "%d ", this->cn->mX);
		//fprintf(f, "%d", this->cn->mY);
		//fprintf(f, "\n");

		for (int i = 0; i < 8; i++) {
			int temp = this->lane[i].LVehicle.size();
			fwrite(&temp, sizeof(int), 1, f);
			//fprintf(f, " %d ", temp);
			if (this->lane[i].light.active == true) {
				temp = 1;
				fwrite(&temp, sizeof(int), 1, f);
				//fprintf(f, " %d ", temp);
			}
			else {
				temp = 0;
				fwrite(&temp, sizeof(int), 1, f);
				//fprintf(f, " %d ", temp);
			}
			for (int j = 0; j < this->lane[i].LVehicle.size(); j++) {
				if (this->lane[i].LVehicle[j]->toString() == "Car") {
					//fprintf(f, " %d ", 1);
					temp = 1;
					fwrite(&temp, sizeof(int), 1, f);
				}
				else {
					//fprintf(f, " %d ", 0);
					temp = 0;
					fwrite(&temp, sizeof(int), 1, f);
				}
				temp = this->lane[i].LVehicle[j]->mx;
				fwrite(&temp, sizeof(int), 1, f);
				//fprintf(f, " %d ", temp);
				temp = this->lane[i].LVehicle[j]->my;
				fwrite(&temp, sizeof(int), 1, f);
				//fprintf(f, " %d ", temp);
			}
			int inconlai = 3 - this->lane[i].LVehicle.size();
			for (int k = 0; k < inconlai; k++) {
				temp = -1;
				fwrite(&temp, sizeof(int), 1, f);
				fwrite(&temp, sizeof(int), 1, f);
				fwrite(&temp, sizeof(int), 1, f);
				//fprintf(f, " %d ", temp);
				//fprintf(f, " %d ", temp);
				//fprintf(f, " %d ", temp);
			}
			//fprintf(f,"\n");
		}
		for (int i = 0; i < 4; i++) {
			int temp = this->Anilane[i].LAnimal.size();
			fwrite(&temp, sizeof(int), 1, f);
			//fprintf(f, " %d ", temp);
			for (int j = 0; j < this->Anilane[i].LAnimal.size(); j++) {
				if (this->Anilane[i].LAnimal[j]->toString() == "Bird") { //Bird in 1
					temp = 1;
					fwrite(&temp, sizeof(int), 1, f);
					//fprintf(f, " %d ", 1);
				}
				else {
					//fprintf(f, " %d ", 0);
					temp = 0;
					fwrite(&temp, sizeof(int), 1, f);
				}
				temp = this->Anilane[i].LAnimal[j]->mx;
				fwrite(&temp, sizeof(int), 1, f);
				//fprintf(f, " %d ", temp);
				temp = this->Anilane[i].LAnimal[j]->my;
				fwrite(&temp, sizeof(int), 1, f);
				//fprintf(f, " %d ", temp);
			}
			int inconlai = 2 - this->Anilane[i].LAnimal.size();
			for (int k = 0; k < inconlai; k++) {
				temp = -1;
				fwrite(&temp, sizeof(int), 1, f);
				fwrite(&temp, sizeof(int), 1, f);
				fwrite(&temp, sizeof(int), 1, f);
				//fprintf(f, " %d ", temp);
				//fprintf(f, " %d ", temp);
				//fprintf(f, " %d ", temp);
			}
			//fprintf(f, "\n");
		}
		fclose(f);
		this->clearMenuSave();
		ResumeThread(t);
		this->pauseGame(t);

	}
};

#endif // ! GAME_H


