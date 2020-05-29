//1712822 - NGUYEN KHANH TOAN - 17CNTN
//vehicle.h
#ifndef  VEHICLE_H
#define VEHICLE_H

#include<iostream>
#include"WindowFunction.h"
#include<vector>

using namespace std;

class CVEHICLE {
public:
	int mx, my;
public:
	CVEHICLE(int dx, int dy) : mx(dx), my(dy) {}
	virtual ~CVEHICLE(){}
public:
	virtual void MoveRight(const int &step) = 0;//step >=6
	virtual void MoveLeft(const int &step) = 0; //step >=6
	virtual string toString() = 0;

	//For drawing and clearing vehicle
	virtual void draw(const int &x, const int &y) = 0;
	virtual void clear(const int &x, const int &y) = 0;
};

class CTRUCK : public CVEHICLE {
public:
	CTRUCK(int dx, int dy) : CVEHICLE(dx,dy) {}
	~CTRUCK() {}
public:
	void MoveRight(const int &step){
		mx += step;
		if (mx < 7 || mx>76) {}
		else {
			this->draw(mx, my);
		}
		//Sleep(100);
		this->clear(mx-step,my);
		Sleep(50);
	}
	void MoveLeft(const int &step) {
		mx -= step;
		if (mx < 7 || mx>76) {}
		else this->draw(mx, my);
		this->clear(mx+step, my);
		Sleep(50);
	}
	void draw(const int &x,const int &y) {
		TextColor(4);
		char character2 = 219;
		GotoXY(x - 1, y);
		printf("%c", character2);
		GotoXY(x, y);
		printf("%c", character2);
		GotoXY(x, y - 1);
		printf("%c", character2);
		GotoXY(x + 1, y - 1);
		printf("%c", character2);
		GotoXY(x + 1, y);
		printf("%c", character2);
		GotoXY(x + 2, y);
		printf("%c", character2);
	}
	void clear(const int &x, const int &y) {
		GotoXY(x - 1, y);
		printf(" ");
		GotoXY(x, y);
		printf(" ");
		GotoXY(x, y - 1);
		printf(" ");
		GotoXY(x + 1, y - 1);
		printf(" ");
		GotoXY(x + 1, y);
		printf(" ");
		GotoXY(x + 2, y);
		printf(" ");
	}
	string toString() {
		return "Truck";
	}
};

class CPOLICE : public CVEHICLE {
public:
	int cnt;
public:
	CPOLICE(int dx, int dy) : CVEHICLE(dx, dy),cnt(0) {}
	~CPOLICE() {}
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
	void MoveLeft(const int &step) {
		mx -= step;
		if (mx < 7 || mx>76) {}
		else this->draw(mx, my);
		this->clear(mx + step, my);
		Sleep(50);
	}
	void draw(const int &x, const int &y) {
		TextColor(4);
		char character2 = 219;
		GotoXY(x - 1, y);
		printf("%c", character2);
		GotoXY(x, y);
		printf("%c", character2);
		if (cnt == 0) {
			GotoXY(x, y - 1);
			TextColor(12);
			printf("%c", character2);
			GotoXY(x + 1, y - 1);
			TextColor(11);
			printf("%c", character2);
			cnt++;
		}
		else {
			GotoXY(x, y - 1);
			TextColor(11);
			printf("%c", character2);
			GotoXY(x + 1, y - 1);
			TextColor(12);
			printf("%c", character2);
			cnt++;
			if (cnt == 2) {
				cnt = 0;
			}
		}
		TextColor(4);
		GotoXY(x + 1, y);
		printf("%c", character2);
		GotoXY(x + 2, y);
		printf("%c", character2);
	}
	void clear(const int &x, const int &y) {
		GotoXY(x - 1, y);
		printf(" ");
		GotoXY(x, y);
		printf(" ");
		GotoXY(x, y - 1);
		printf(" ");
		GotoXY(x + 1, y - 1);
		printf(" ");
		GotoXY(x + 1, y);
		printf(" ");
		GotoXY(x + 2, y);
		printf(" ");
	}
	string toString() {
		return "Accident! Accident! Accident!";
	}
};

class CCAR :public CVEHICLE {
public:
	CCAR(int dx, int dy) : CVEHICLE(dx, dy) {}
	~CCAR() {}
public:
	void MoveRight(const int &step) {
		mx += step;
		if (mx < 7 || mx>76) {}
		else {
			this->draw(mx, my);
		}
		this->clear(mx-step,my);
		Sleep(50);
	}
	void MoveLeft(const int &step) {
		mx -= step;
		if (mx < 7 || mx>76) {}
		else this->draw(mx, my);
		this->clear(mx + step, my);
		Sleep(50);
	}
	void draw(const int &x, const int &y) {
		TextColor(5);
		char character2 = 219;
		GotoXY(x - 1, y);
		printf("%c", character2);
		GotoXY(x, y);
		printf("%c", character2);
		GotoXY(x, y - 1);
		printf("%c", character2);
		GotoXY(x + 1, y - 1);
		printf("%c", character2);
		GotoXY(x + 1, y);
		printf("%c", character2);
	}
	void clear(const int &x, const int &y) {
		GotoXY(x - 1, y);
		printf(" ");
		GotoXY(x, y);
		printf(" ");
		GotoXY(x, y - 1);
		printf(" ");
		GotoXY(x + 1, y - 1);
		printf(" ");
		GotoXY(x + 1, y);
		printf(" ");
	}
	string toString() {
		return "Car";
	}
};

class CTRAFFIC {
public:
	int tx, ty;
	bool active;
	int times; //for red light
public:
	CTRAFFIC() : active(true),tx(0),ty(0),times(30) {}
	CTRAFFIC(int dx,int dy) : active(true), tx(dx), ty(dy),times(30) {}
public:
	void draw(const int &type) {
		if (type == 1) TextColor(12);
		else TextColor(10);
		GotoXY(tx - 1, ty + 1);
		printf("%c", 219);
		GotoXY(tx - 1, ty);
		printf("%c", 219);
		//
		GotoXY(tx, ty + 1);
		printf("%c", 219);
		GotoXY(tx, ty);
		printf("%c", 219);
		//
		GotoXY(tx + 1, ty + 1);
		printf("%c", 219);
		GotoXY(tx + 1, ty);
		printf("%c", 219);
	}
};

class CLane { //1,3,5,7
public:
	int ly;
	vector<CVEHICLE*> LVehicle;
	CTRAFFIC light;
	int MaxVehicle;
public:
	CLane() : ly(0), light(83, ly-1), MaxVehicle(2) {}
	CLane(int y) : ly(y), light(83, ly-1), MaxVehicle(2) {} //2->3
	~CLane() {
		for (int i = 0; i < LVehicle.size(); i++) {
			delete LVehicle[i];
		}
		LVehicle.clear();
	}
public:
	void Generate(const int &type) {
		if (LVehicle.size() >= MaxVehicle) return;
		else if (LVehicle.size() == 0) {
			int iSecret = rand() % 5 + 1;
			if (type == 1) {
				if (iSecret == 4) {
					int iRan = rand() % 2 + 1;
					CVEHICLE* newVeh;
					if (iRan == 1) { //truck
						newVeh = new CTRUCK(6, ly);
						newVeh->draw(6, ly);
					}
					else { //car
						newVeh = new CCAR(6, ly);
						newVeh->draw(6, ly);
					}
					LVehicle.push_back(newVeh);
				}
			}
			else {
				if (iSecret == 4) {
					int iRan = rand() % 2 + 1;
					CVEHICLE* newVeh;
					if (iRan == 1) { //truck
						newVeh = new CTRUCK(77, ly);
						newVeh->draw(77, ly);
					}
					else { //car
						newVeh = new CCAR(77, ly);
						newVeh->draw(77, ly);
					}
					LVehicle.push_back(newVeh);
				}
			}
		}
		else {
			int iSecret = rand() % 5 + 1;
			CVEHICLE* lst = LVehicle[LVehicle.size() - 1];
			if (type == 1) {
				if (iSecret == 4 && lst->mx > 12) {
					int iRan = rand() % 2 + 1;
					CVEHICLE* newVeh;
					if (iRan == 1) { //truck
						newVeh = new CTRUCK(6, ly);
						newVeh->draw(6, ly);
					}
					else { 
						newVeh = new CCAR(6, ly);
						newVeh->draw(6, ly);
					}
					LVehicle.push_back(newVeh);
				}
			}
			else if (type == 0) {
				if (iSecret == 4 && lst->mx < 71) {
					int iRan = rand() % 2 + 1;
					CVEHICLE* newVeh;
					if (iRan == 1) { //truck
						newVeh = new CTRUCK(77, ly);
						newVeh->draw(77, ly);
					}
					else {
						newVeh = new CCAR(77, ly);
						newVeh->draw(77, ly);
					}
					LVehicle.push_back(newVeh);
				}
			}
		}
	}
	void checkClear() {
		if (LVehicle.size() == 0) return;
		while (LVehicle[0]->mx > 76) {
			LVehicle.erase(LVehicle.begin());
			if (LVehicle.size() == 0) return;
		}
		while (LVehicle[0]->mx < 7) {
			LVehicle.erase(LVehicle.begin());
			if (LVehicle.size() == 0) return;
		}
	}
	void Continue(const int &type) {
		if (light.active == false) {
			light.draw(1);
			light.times--;
			if (light.times == 0) {
				light.active = true;
				light.draw(0);
				light.times = 30;
			}
		}
		else if (light.active == true) {
			this->Generate(type);
			if (type == 1) { //1 - di phai
				for (int i = 0; i < LVehicle.size(); i++) {
					LVehicle[i]->MoveRight(7);
				}
			}
			else { //0 - di trai
				for (int i = 0; i < LVehicle.size(); i++) {
					LVehicle[i]->MoveLeft(7);
				}
			}
			this->checkClear();
			int randForRed = rand() % 100;
			if (randForRed == 27 || randForRed == 11) {
				light.active = false;
			}
		}
	}
};
#endif // ! VEHICLE_H


