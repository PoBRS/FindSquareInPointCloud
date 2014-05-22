#pragma once
#include "Point.h"
/**
	Une ligne est compos�e de deux points et permet de cr�er un carr�.
	Cette classe sert � conserver la valeur des points pour l'affichage ult�rieur de vertex.
*/
class Line
{
public:
	Line::Line(void);
	Line::~Line(void);
	Line::Line(Point* _startPoint, Point* _endPoint);
	Point* Line::getStartPoint(void)const;
	Point* Line::getEndPoint(void) const;

	float getDxCurrent(void) const;
	float getDxFinal(void) const;
	float getDyCurrent(void) const;
	float getDyFinal(void) const;

	void setDxCurrent(const float dxCurrent);
	void setDyCurrent(const float dyCurrent);
private:
	Point* endPoint;
	Point* startPoint;

	float dyCurrent;
	float dyFinal;

	float dxCurrent;
	float dxFinal;
};