//1712822 - NGUYEN KHANH TOAN - 17CNTN
//animal.h
#ifndef  ANIMAL_H
#define ANIMAL_H

#include<iostream>
#include"WindowFunction.h"
#include<vector>
#include<string>

using namespace std;

class CANIMAL {
public:
	int mx, my;
public:
	CANIMAL(int dx, int dy) : mx(dx), my(dy) {}
	virtual ~CANIMAL() {}
public:
	virtual void MoveRight(const int &step) = 0;//step >=6
	virtual string toString() = 0;

	//For drawing and clearing vehicle
	virtual void draw(const int &x, const int &y) = 0;
	virtual void clear(const int &x, const int &y) = 0;
};
class CDINAUSOR : public CANIMAL {
public:
	CDINAUSOR(int dx, int dy) : CANIMAL(dx, dy) {}
	~CDINAUSOR() {}
public:
	void MoveRight(const int &step) {
		mx += step;
		if (mx < 7 || mx>76) {}
		else {
			this->draw(mx, my);
		}
		//Sleep(100);
		this->clear(mx - step, my);
		Sleep(50);
	}
	void draw(const int &x, const int &y) {
		TextColor(3);
		char character2 = 219;
		char character3 = 220;
		GotoXY(x, y);
		printf("%c", character2);
		GotoXY(x + 1, y);
		printf("%c", character2);
		GotoXY(x + 1, y - 1);
		printf("%c", character2);
		GotoXY(x - 1, y + 1);
		printf("%c", character2);
		GotoXY(x, y + 1);
		printf("%c", character2);
	}
	void clear(const int &x, const int &y) {
		GotoXY(x, y);
		printf(" ");
		GotoXY(x + 1, y);
		printf(" ");
		GotoXY(x + 1, y - 1);
		printf(" ");
		GotoXY(x - 1, y + 1);
		printf(" ");
		GotoXY(x, y + 1);
		printf(" ");
	}
	string toString() {
		return "Dinausor";
	}
};

class CBIRD :public CANIMAL {
public:
	CBIRD(int dx, int dy) : CANIMAL(dx, dy) {}
	~CBIRD() {}
public:
	void MoveRight(const int &step) {
		mx += step;
		if (mx < 7 || mx>76) {}
		else {
			this->draw(mx, my);
		}
		this->clear(mx - step, my);
		Sleep(50);
	}
	void draw(const int &x, const int &y) {
		TextColor(6);
		char character2 = 219;
		GotoXY(x, y);
		printf("%c", character2);
		GotoXY(x - 1, y - 1);
		printf("%c", character2);
		GotoXY(x + 1, y - 1);
		printf("%c", character2);
	}
	void clear(const int &x, const int &y) {
		GotoXY(x, y);
		printf(" ");
		GotoXY(x - 1, y - 1);
		printf(" ");
		GotoXY(x + 1, y - 1);
		printf(" ");
	}
	string toString() {
		return "Bird";
	}
};

class CAniLane { //4 lane
public:
	int ly;
	vector<CANIMAL*> LAnimal;
	int MaxAnimal;
public:
	CAniLane() : ly(0), MaxAnimal(1) {}
	CAniLane(int y) : ly(y), MaxAnimal(1) {} //1,2
	~CAniLane() {
		for (int i = 0; i < LAnimal.size(); i++) {
			delete LAnimal[i];
		}
		LAnimal.clear();
	}
public:
	void Generate() {
		if (LAnimal.size() >= MaxAnimal) return;
		else if (LAnimal.size() == 0) {
			int iSecret = rand() % 5 + 1;
			if (iSecret == 4) {
				int iRan = rand() % 2 + 1;
				CANIMAL* newVeh;
				if (iRan == 1) { //bird
					newVeh = new CBIRD(7, ly-1); //6?
					newVeh->draw(7, ly - 1);
				}
				else { //car
					newVeh = new CDINAUSOR(7, ly-1);
					newVeh->draw(7, ly - 1);
				}
				LAnimal.push_back(newVeh);
			}
		}
		else {
			int iSecret = rand() % 5 + 1;
			CANIMAL* lst = LAnimal[LAnimal.size() - 1];
			if (iSecret == 4 && lst->mx > 12) {
				int iRan = rand() % 2 + 1;
				CANIMAL* newVeh;
				if (iRan == 1) { //bird
					newVeh = new CBIRD(7, ly - 1);
					newVeh->draw(7, ly - 1);
				}
				else {
					newVeh = new CDINAUSOR(7, ly - 1);
					newVeh->draw(7, ly - 1);
				}
				LAnimal.push_back(newVeh);
			}
		}
	}
	void checkClear() {
		if (LAnimal.size() == 0) return;
		while (LAnimal[0]->mx > 76) {
			LAnimal.erase(LAnimal.begin());
			if (LAnimal.size() == 0) return;
		}
	}
	void Continue() {
		this->Generate();
		for (int i = 0; i < LAnimal.size(); i++) {
			LAnimal[i]->MoveRight(7);
		}
		this->checkClear();
	}
};

#endif // ! ANIMAL_H


