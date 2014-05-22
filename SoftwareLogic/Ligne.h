#pragma once
#include "SFML/Graphics.hpp"
#include "Point.h"
//namespace SFML
using namespace sf;

class Ligne
{
public:
	Ligne::Ligne();
	Ligne::~Ligne();
	Ligne::Ligne(Point* pointDebut, Point* pointFin);
	Point* Ligne::getPointDebut();
	Point* Ligne::getPointFin();
	void Ligne::AffichageLigne(RenderWindow &mainWin);
	void Ligne::AffichageProgressifLigne(RenderWindow &mainWin, int fps);

	bool Ligne::AffichageComplet();
private:
	Point* pointDebut;
	Point* pointFin;

	float dyActuel;
	float dyFinal;
	float dxActuel;
	float dxFinal;
};