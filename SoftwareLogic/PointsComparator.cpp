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
Redéfinition de l'operateur () avec deux points.
@param _point1 Référence d'un point
@param _point2 Référence d'un point
@return boolean Le résultat de la comparaison "<" entre le _point1 et le _point2.
*/
bool PointsComparator::operator() (const Point& _point1, const Point& _point2) const
{
	return isApproximativelySmaller(_point1 ,_point2);
}

/**
Compare la valeur entre deux points. Sert à effectuer une comparaison moins sévère qu'avec Point
lorsque des Points n'ont pas été associés à un Square.
@param _comparedPointA Référence d'un point
@param _comparedPointB Référence d'un point
@return boolean Le résultat de la comparaison "<" approximative entre le _point1 et le _point2.
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
	Fonction qui compare deux floats pour savoir s'ils sont presque égales.
	@param[in] _value1 La première valeur.
	@param[in] _value2 La deuxième valeur.
	@param[in] _allowedDifference Le jeu de différence que l'on accepte entre les deux float pour puissent être considérés égaux.
	@return boolean Le résultat de la comparaison "==" approximative entre le _point1 et le _point2.
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

