#pragma once
#include "Line.h"
#include "SFML/Graphics.hpp"

//namespace SFML
using namespace sf;

class Rectangle
{
public:
	Rectangle(Line* _Lines[4]);
	Rectangle(Point* _sommetA, Point* _sommetB, Point* _sommetC, Point* _sommetD);
	Rectangle::~Rectangle(void);
	void Rectangle::Display(RenderWindow& _mainWin, int _fps=0);
	//float Rectangle::GetOrigineX();
	//float Rectangle::GetOrigineY();
	//float Rectangle::GetSommet();
private:
	Line* LinesComposition[4];
	Point* vertex[4];
	void Rectangle::instantDisplay(RenderWindow& _mainWin);
	void Rectangle::progressiveDisplay(RenderWindow& _mainWin, int _fps);
	void Rectangle::progressiveDisplayTop(RenderWindow& _mainWin, int _fps);
	void Rectangle::progressiveDisplayBottom(RenderWindow& _mainWin, int _fps);
	//float origineX;
	//float origineY;
	//float sommet;
};