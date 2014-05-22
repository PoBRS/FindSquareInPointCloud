#include "Ligne.h"

Ligne::Ligne(Point* pointDebut, Point* pointFin)
{
	this->pointDebut = pointDebut;
	this->pointFin = pointFin;

	this->dxActuel = 0;
	this->dxFinal = (pointFin->getX() - pointDebut->getX());
	this->dyActuel = 0;
	this->dyFinal = (pointFin->getY() - pointDebut->getY());
}

Ligne::~Ligne()
{
	delete this->pointDebut;
	delete this->pointFin;
}

Point* Ligne::getPointDebut()
{
	return this->pointDebut;
}

Point* Ligne::getPointFin()
{
	return this->pointFin;
}

void Ligne::AffichageLigne(RenderWindow &mainWin)
{
		sf::VertexArray line(sf::Lines, 2);
		line[0].position.x = this->pointDebut->getX();
		line[0].position.y = this->pointDebut->getY();
		line[1].position.x = this->pointFin->getX();
		line[1].position.y = this->pointFin->getY();
		mainWin.draw(line);
}

void Ligne::AffichageProgressifLigne(RenderWindow &mainWin, int fps)
{
		sf::VertexArray line(sf::Lines, 2);
		line[0].position.x = this->pointDebut->getX();
		line[0].position.y = this->pointDebut->getY();

		line[1].position.x = this->pointDebut->getX() + dxActuel;
		line[1].position.y = this->pointDebut->getY() + dyActuel;

		dxActuel += dxFinal/(fps/2);
		dyActuel += dyFinal/(fps/2);
		mainWin.draw(line);
}

bool Ligne::AffichageComplet()
{
	if(dyActuel >= dyFinal)
	{
		return true;
	}
	return false;
}