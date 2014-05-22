#include "Rectangle.h"
#include "SFML/Graphics.hpp"

Rectangle::Rectangle(Line* _Lines[4])
{
	for (int i = 0; i < 4; i++)
	{
		this->LinesComposition[i] = _Lines[i];
	}
}
Rectangle::Rectangle(Point* _vertexA, Point* _vertexB, Point* _vertexC, Point* _vertexD)
{
	this->vertex[0] = _vertexA;
	this->vertex[1] = _vertexB;
	this->vertex[2] = _vertexC;
	this->vertex[3] = _vertexD;
	
	for (int i = 0; i < 4; i++)
	{
		this->vertex[i]->setUsed(true);
	}

	this->LinesComposition[0] = new Line(_vertexA, _vertexB);
	this->LinesComposition[1] = new Line(_vertexA, _vertexC);
	this->LinesComposition[2] = new Line(_vertexB, _vertexD);
	this->LinesComposition[3] = new Line(_vertexC, _vertexD);
}
Rectangle::~Rectangle(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->LinesComposition[i];
	}
	for (int i = 0; i < 4; i++)
	{
		delete this->vertex[i];
	}
}
void Rectangle::Display(RenderWindow& _mainWin, int _fps)
{
	if (_fps == 0)
	{
		//Affichage d'un coup
		this->instantDisplay(_mainWin);
	}
	else
	{
		//Affichage progressif
		this->progressiveDisplay(_mainWin, _fps);
	}

}
void Rectangle::progressiveDisplay(RenderWindow& _mainWin, int _fps)
{
	if (this->LinesComposition[0]->DisplayCompleted() == false && this->LinesComposition[1]->DisplayCompleted() == false)
	{
		//Supérieur
		this->progressiveDisplayTop(_mainWin, _fps);
	}
	else if (this->LinesComposition[2]->DisplayCompleted() == false && this->LinesComposition[3]->DisplayCompleted() == false)
	{
		//Inférieur
		this->progressiveDisplayTop(_mainWin, _fps);
		this->progressiveDisplayBottom(_mainWin, _fps);
	}
	else
	{
		//Pour protection: Complet
		this->instantDisplay(_mainWin);
	}
}
void Rectangle::instantDisplay(RenderWindow& _mainWin)
{
	for (int i = 0; i < 4; i++)
	{
		LinesComposition[i]->InstantDisplay(_mainWin);
	}
}

void Rectangle::progressiveDisplayTop(RenderWindow& _mainWin, int _fps)
{
	LinesComposition[0]->ProgressiveDisplay(_mainWin, _fps);
	LinesComposition[1]->ProgressiveDisplay(_mainWin, _fps);
}

void Rectangle::progressiveDisplayBottom(RenderWindow& _mainWin, int _fps)
{
	LinesComposition[2]->ProgressiveDisplay(_mainWin, _fps);
	LinesComposition[3]->ProgressiveDisplay(_mainWin, _fps);
}
