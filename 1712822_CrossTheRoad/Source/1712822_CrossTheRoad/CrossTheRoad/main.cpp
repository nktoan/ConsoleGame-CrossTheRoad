//1712822 - NGUYEN KHANH TOAN - 17CNTN
//main.cpp

#include"Game.h"

using namespace std;

CGAME* cg;
char MOVING;

void SubThread() {
	while (cg->IS_RUNNING) {
		if (!cg->getPeople()->isDead()) {
			Sleep(500);
			cg->updatePosPeople(MOVING);
		}
		MOVING = ' ';
		if (cg->getPeople()->isImpactWithVehicle_type1(cg->lane) || cg->getPeople()->isImpactWithAnimal_type1(cg->Anilane)) {
			cg->cn->mState = false;
		}
		cg->updatePosVehicle();
		if (cg->getPeople()->isImpactWithVehicle(cg->lane) || cg->getPeople()->isImpactWithAnimal(cg->Anilane)) {
			cg->cn->mState = false;
		}
		Sleep(1000);
	}
}

void main() {
	//////////////////////////////////
	////////////////////REAL PROGRAM
	srand(time(NULL));
	resizeConsole(1500, 1000);
	FixConsoleWindow();
	Nocursortype();
	cg = new CGAME;
	cg->startGame();
	if (!cg->mute) mciSendStringA("play MusicGame.mp3 repeat", NULL, 0, NULL);
	int temp;
	thread t1(SubThread);
	while (1) {
		temp = _getch();
		if (!cg->getPeople()->isDead()) { //neu con song
			if (temp == 'e' || temp == 'E') {
				cg->exitGame(t1.native_handle());
			}
			else if (temp == 'p' || temp == 'P') {
				cg->pauseGame(t1.native_handle());
			}
			else if (temp == 'l' || temp == 'L') {
				cg->saveGame(t1.native_handle());
			}
			else if (temp == 'T' || temp == 't') {
				cg->loadGame(t1.native_handle());
			}
			else {
				//neu chua chet thi di tiep kiem tra dung cham, ve dich thi win hoac next level
				cg->resumeGame(t1.native_handle());
				MOVING = temp;
				if (cg->getPeople()->isFinish()) {
					cg->winGame(t1.native_handle());
				}
			}
		}
		else { //neu da chet
			mciSendStringA("stop MusicGame.mp3", NULL, 0, NULL);
			mciSendStringA("play GameOver.mp3", NULL, 0, NULL);
			cg->loseGame(t1.native_handle());
			//neu muon choi lai thi choi ko thi thoat
		}
	}
	cg->clearAllGame();
	delete cg;
}
