//1712822 - NGUYEN KHANH TOAN - 17CNTN
//people.h
#ifndef  PEOPLE_H
#define PEOPLE_H

#include<iostream>
#include"Animal.h"
#include"Vehicle.h"

using namespace std;

enum { DIE, ALIVE };

class CPEOPLE {
public:
	int mX, mY;
	bool mState;
public:
	CPEOPLE(){
		mX = (80 - 4) / 2;
		mY = 45;
		mState = true; //con song
		//this->Draw(mX,mY);
	}
public:
	void Draw(int x, int y) {
		TextColor(11);
		GotoXY(x, y+1);
		printf("%c%c", 195, 180);
		GotoXY(x, y);
		printf("%c%c", 220, 220);
	}
	void Clear(int x, int y) {
		GotoXY(x, y+1);
		printf("  ");
		GotoXY(x, y);
		printf("  ");
	}
	// PEOPLE : BEGIN - 3 - 3 - 4 - 4 - 3 - 3 - 3 - 3 - 4 - 4 - 3 - 3 - 3
	int UpWithThinking() {
		int go[] = { 3,3,4,4,3,3,3,3,4,4,3,3,3 };
		if (mY == 45) return 3;
		else if (mY == 42) return 3;
		else if (mY == 39) return 4;
		else if (mY == 35) return 4;
		else if (mY == 31) return 3;
		else if (mY == 28) return 3;
		else if (mY == 25) return 3;
		else if (mY == 22) return 3;
		else if (mY == 19) return 4;
		else if (mY == 15) return 4;
		else if (mY == 11) return 3;
		else if (mY == 8) return 3;
		else if (mY == 5) return 3;
		else if (mY == 2) return 3;
	}
	int DownWithThinking() {
		int go[] = { 3,3,4,4,3,3,3,3,4,4,3,3,3 };
		if (mY == 2) return 3;
		else if (mY == 5) return 3;
		else if (mY == 8) return 3;
		else if (mY == 11) return 4;
		else if (mY == 15) return 4;
		else if (mY == 19) return 3;
		else if (mY == 22) return 3;
		else if (mY == 25) return 3;
		else if (mY == 28) return 3;
		else if (mY == 31) return 4;
		else if (mY == 35) return 4;
		else if (mY == 39) return 3;
		else if (mY == 42) return 3;
		else if (mY == 45) return 3;
	}
	void Up() {
		//cout << mY;
		int steps = this->UpWithThinking();
		mY -= steps;
		if (mY < 2) {
			mY = 2;
			return;
		}
		this->Draw(mX, mY);
		this->Clear(mX, mY + steps);
		Sleep(20);
	}
	void Down() {
		int steps = this->DownWithThinking();
		mY += steps;
		if (mY > 45) {
			mY = 45;
			return;
		}
		this->Draw(mX, mY);
		this->Clear(mX, mY - steps);
		Sleep(20);
	}
	void Left() {
		mX -= 3;
		if (mX < 5) {
			mX = 5;
		}
		this->Draw(mX, mY);
		this->Clear(mX+3, mY);
		Sleep(20);
	}
	void Right() {
		mX += 3;
		if (mX > 77) {
			mX = 77;
		}
		this->Draw(mX, mY);
		this->Clear(mX-3, mY);
		Sleep(20);
	}
	//bool isImpact(const CVEHICLE* &);

	int impactVehicleThinking() {
		if (mY == 42) return 0;
		else if (mY == 39) return 1;
		else if (mY == 28) return 2;
		else if (mY == 25) return 3;
		else if (mY == 22) return 4;
		else if (mY == 19) return 5;
		else if (mY == 8) return 6;
		else if (mY == 5) return 7;
		return -1;
	}
	int impactAnimalThinking() {
		if (mY == 35) return 0;
		else if (mY == 31) return 1;
		else if (mY == 15) return 2;
		else if (mY == 11) return 3;
		return -1;
	}

	bool isImpactWithAnimal_type1(vector<CAniLane> &lane) {
		int indexThinking = this->impactAnimalThinking();
		if (indexThinking == -1) return false;
		for (int i = 0; i < lane[indexThinking].LAnimal.size(); i++) {
			if (lane[indexThinking].LAnimal[i]->toString() == "Bird") {
				//Kiem tra vi tri hien tai co dung ko?
				int lx = lane[indexThinking].LAnimal[i]->mx - 1;
				int rx = lane[indexThinking].LAnimal[i]->mx + 1;
				int people_lx = mX, people_rx = mX + 1;
				if (lx > people_rx || rx < people_lx) {}
				else return true;
			}
			else {
				//Kiem tra vi tri hien tai co dung ko?
				int lx = lane[indexThinking].LAnimal[i]->mx - 1;
				int rx = lane[indexThinking].LAnimal[i]->mx + 1;
				int people_lx = mX, people_rx = mX + 1;
				if (lx > people_rx || rx < people_lx) {}
				else return true;
			}
		}
		return false;
	}

	bool isImpactWithAnimal(vector<CAniLane> &lane) {
		int indexThinking = this->impactAnimalThinking();
		if (indexThinking == -1) return false;
		for (int i = 0; i < lane[indexThinking].LAnimal.size(); i++) {
			if (lane[indexThinking].LAnimal[i]->toString() == "Bird") {
				//Kiem tra vi tri hien tai co dung ko?
				int lx = lane[indexThinking].LAnimal[i]->mx - 1;
				int rx = lane[indexThinking].LAnimal[i]->mx + 1;
				int people_lx = mX, people_rx = mX + 1;
				if (lx > people_rx || rx < people_lx) {}
				else return true;
				//Kiem tra dung di qua roi?
				int	cur_x = lane[indexThinking].LAnimal[i]->mx;
				int old_x = lane[indexThinking].LAnimal[i]->mx - 7;
				if (cur_x > mX && old_x < mX) {
					return true;
				}
				//last one
			}
			else {
				//Kiem tra vi tri hien tai co dung ko?
				int lx = lane[indexThinking].LAnimal[i]->mx - 1;
				int rx = lane[indexThinking].LAnimal[i]->mx + 1;
				int people_lx = mX, people_rx = mX + 1;
				if (lx > people_rx || rx < people_lx) {}
				else return true;
				//Kiem tra dung di qua roi?
				int	cur_x = lane[indexThinking].LAnimal[i]->mx;
				int old_x = lane[indexThinking].LAnimal[i]->mx - 7;
				if (cur_x > mX && old_x < mX) {
					return true;
				}
				//last one
			}
		}
		return false;
	}

	bool isImpactWithVehicle_type1(vector<CLane> &lane){
		int indexThinking = this->impactVehicleThinking();
		if (indexThinking == -1) return false;
		for (int i = 0; i < lane[indexThinking].LVehicle.size(); i++) {
			if (lane[indexThinking].LVehicle[i]->toString() == "Car") {
				//Kiem tra vi tri hien tai co dung ko?
				int lx = lane[indexThinking].LVehicle[i]->mx - 1;
				int rx = lane[indexThinking].LVehicle[i]->mx + 1;
				int people_lx = mX, people_rx = mX + 1;
				if (lx > people_rx || rx < people_lx) {}
				else return true;
			}
			else {
				//Kiem tra vi tri hien tai co dung ko?
				int lx = lane[indexThinking].LVehicle[i]->mx - 1;
				int rx = lane[indexThinking].LVehicle[i]->mx + 2;
				int people_lx = mX, people_rx = mX + 1;
				if (lx > people_rx || rx < people_lx) {}
				else return true;
			}
		}
		return false;
	}

	bool isImpactWithVehicle(vector<CLane> &lane) {
		int indexThinking = this->impactVehicleThinking();
		if (indexThinking == -1) return false;
		if (lane[indexThinking].light.active == false) return false;
		for (int i = 0; i < lane[indexThinking].LVehicle.size(); i++) {
			if (lane[indexThinking].LVehicle[i]->toString() == "Car") {
				//Kiem tra vi tri hien tai co dung ko?
				int lx = lane[indexThinking].LVehicle[i]->mx - 1;
				int rx = lane[indexThinking].LVehicle[i]->mx + 1;
				int people_lx = mX , people_rx = mX + 1;
				if (lx > people_rx || rx < people_lx) {}
				else return true;
				//Kiem tra dung di qua roi?
				if (indexThinking % 2 == 1) {
					int	cur_x = lane[indexThinking].LVehicle[i]->mx;
					int old_x = lane[indexThinking].LVehicle[i]->mx + 7;
					if (cur_x < mX && old_x > mX) {
						return true;
					}
				}
				else {
					int	cur_x = lane[indexThinking].LVehicle[i]->mx;
					int old_x = lane[indexThinking].LVehicle[i]->mx - 7;
					if (cur_x > mX && old_x < mX) {
						return true;
					}
				}
				//last one
			}
			else {
				//Kiem tra vi tri hien tai co dung ko?
				int lx = lane[indexThinking].LVehicle[i]->mx - 1;
				int rx = lane[indexThinking].LVehicle[i]->mx + 2;
				int people_lx = mX, people_rx = mX + 1;
				if (lx > people_rx || rx < people_lx) {}
				else return true;
				//Kiem tra dung di qua roi?
				if (indexThinking % 2 == 1) {
					int	cur_x = lane[indexThinking].LVehicle[i]->mx;
					int old_x = lane[indexThinking].LVehicle[i]->mx + 7;
					if (cur_x < mX && old_x > mX) {
						return true;
					}
				}
				else {
					int	cur_x = lane[indexThinking].LVehicle[i]->mx;
					int old_x = lane[indexThinking].LVehicle[i]->mx - 7;
					if (cur_x > mX && old_x < mX) {
						return true;
					}
				}
				//last one
			}
		}
		return false;
	}
	bool isFinish() {
		if (mY <= 2) return true;
		return false;
	}
	bool isDead() {
		return !mState;
	}
	void TuongTacPhim(const char &key)
	{
		//key = _getch(); //nhan tu man hinh
		if (int(key == 75)) Left(); else
			if (int(key == 77)) Right(); else
				if (int(key == 72)) Up(); else
					if (int(key == 80)) Down(); 
	}
};

#endif // ! PEOPLE_H
