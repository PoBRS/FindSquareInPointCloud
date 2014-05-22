#include "Point.h"
//namespace SFML

/**
Constructeur de PontsComparator
*/
PointsComparator::PointsComparator()
{

}

/**
Destructeur de PointsCompartor
*/
PointsComparator::~PointsComparator()
{

}

/**
Red�finition de l'operateur () avec deux points.
@param _point1 R�f�rence d'un point
@param _point2 R�f�rence d'un point
@return boolean Le r�sultat de la comparaison "<" entre le _point1 et le _point2.
*/
bool PointsComparator::operator() (const Point& _point1, const Point& _point2) const
{
	return isApproximativelySmaller(_point1 ,_point2);
}

/**
Compare la valeur entre deux points. Sert � effectuer une comparaison moins s�v�re qu'avec Point
lorsque des Points n'ont pas �t� associ�s � un Square.
@param _comparedPointA R�f�rence d'un point
@param _comparedPointB R�f�rence d'un point
@return boolean Le r�sultat de la comparaison "<" approximative entre le _point1 et le _point2.
*/
bool PointsComparator::isApproximativelySmaller(const Point& _comparedPointA, const Point& _comparedPointB) const
{
	
	if (_comparedPointA == _comparedPointB)
	{
		return false;	
	}
	if (isFloatApproximativelyEqual(_comparedPointA.getX(), _comparedPointB.getX(), 0.2))
	{
		if (isFloatApproximativelyEqual(_comparedPointA.getY(), _comparedPointB.getY(), 0.2))
		{
			return false;
		}

		if ((_comparedPointA.getX() > _comparedPointB.getX()) && ((_comparedPointA.getY() < _comparedPointB.getY())))
		{
			return true;
		}
		if ((_comparedPointA.getX() < _comparedPointB.getX()) && ((_comparedPointA.getY() > _comparedPointB.getY())))
		{
			return false;
		}
	}
	if(_comparedPointA.getX() < _comparedPointB.getX())
	{
		return true;
	}
	if(_comparedPointA.getX() > _comparedPointB.getX())
	{
		return false;
	}

	if (_comparedPointA.getX() == _comparedPointB.getX())
	{
		if(_comparedPointA.getY() == _comparedPointB.getY())
		{
			return false;
		}
		if(_comparedPointA.getY() < _comparedPointB.getY())
		{
			return true;
		}
		if(_comparedPointA.getY() > _comparedPointB.getY())
		{
			return false;
		}
	}
	return false;
}

/**
	Fonction qui compare deux floats pour savoir s'ils sont presque �gales.
	@param[in] _value1 La premi�re valeur.
	@param[in] _value2 La deuxi�me valeur.
	@param[in] _allowedDifference Le jeu de diff�rence que l'on accepte entre les deux float pour puissent �tre consid�r�s �gaux.
	@return boolean Le r�sultat de la comparaison "==" approximative entre le _point1 et le _point2.
*/
 bool PointsComparator::isFloatApproximativelyEqual(const float _value1, const float _value2, const float _allowedDifference) 
{
	float value1 = _value1;
	float value2a = _value2 + _allowedDifference;
	float value2b = _value2 - _allowedDifference;
		
	if (_value1 == _value2)
	{
		return true;
	}
	if((value1 >= (value2b)) && (value1 <= (value2a)))
	{
		return true;
	}
	return false;
}

