#include "SquareDisplay.h"

bool SquareDisplay::displayAllRectanglePartially(std::vector<Square*>* _rectangleVector, RenderWindow &mainWin) 
{
	this->fps = 120;
	bool areRectangleDisplayCompleted = false;
	for (std::vector<Square*>::iterator rectangleIterator = _rectangleVector->begin(); rectangleIterator != _rectangleVector->end(); std::advance(rectangleIterator,1))
	{
		areRectangleDisplayCompleted = this->Display(mainWin, *(*rectangleIterator));
	}
	return areRectangleDisplayCompleted;
}

bool SquareDisplay::displayRectangleOneByOne(std::vector<Square*>* _rectangleVector, int* _nbRectangleCompletedDisplay,RenderWindow &mainWin)
{
	this->fps = 120;
	for (unsigned int i = 0; i < _rectangleVector->size(); i++)
	{
		if (i < *_nbRectangleCompletedDisplay)
		{
			this->Display(mainWin, *(_rectangleVector->at(i)));
		}
		else if (i == *_nbRectangleCompletedDisplay)
		{
			bool isRectangleDisplayCompleted = this->Display(mainWin,*(_rectangleVector->at(i)));
			if (isRectangleDisplayCompleted)
			{
				(*_nbRectangleCompletedDisplay)++;
			}
		}

	}
	return (*_nbRectangleCompletedDisplay == _rectangleVector->size()); // true if all displayed. if not: false;

}

void SquareDisplay::LineInstantDisplay(RenderWindow &_mainWin, Line &line)
{
	sf::VertexArray lineToDraw(sf::Lines, 2);
	lineToDraw[0].position.x = line.getStartPoint()->getX();
	lineToDraw[0].position.y = line.getStartPoint()->getY();
	lineToDraw[1].position.x = line.getEndPoint()->getX();
	lineToDraw[1].position.y = line.getEndPoint()->getY();
	_mainWin.draw(lineToDraw);
}
/**
Fonction qui fait l'affichage progressif de la ligne. Aggrandi un peu la longeur de la ligne à afficher.
@param[in] _mainWin Référence sur la fenêtre d'affichage.
@param[in] _fps Le nombre de frame par seconde de la fenêtre.
@param[out] _mainWin la fenêtre d'affichage ajouté du rectangle.
@ToDo Mettre une fonction (voir code pour savoir quoi changer)
*/
void SquareDisplay::LineProgressiveDisplay(RenderWindow &_mainWin, Line &line)
{
	sf::VertexArray lineToDraw(sf::Lines, 2);
	lineToDraw[0].position.x = line.getStartPoint()->getX();
	lineToDraw[0].position.y = line.getStartPoint()->getY();
	lineToDraw[1].position.x = line.getStartPoint()->getX() + line.getDxCurrent();
	lineToDraw[1].position.y = line.getStartPoint()->getY() +line.getDyCurrent();


	if (std::min(std::abs(line.getDxCurrent() + line.getDxFinal()/(this->fps/2)),std::abs(line.getDxFinal())) == std::abs(line.getDxFinal()))
	{
		line.setDxCurrent(line.getDxFinal());
	}
	else
	{
		line.setDxCurrent(line.getDxCurrent() + line.getDxFinal()/(this->fps/2));
	}

	if (std::min(std::abs(line.getDyCurrent() + line.getDyFinal()/(this->fps/2)),std::abs(line.getDyFinal())) == std::abs(line.getDyFinal()))
	{
		line.setDyCurrent(line.getDyFinal());
	}
	else
	{
		line.setDyCurrent(line.getDyCurrent() + line.getDyFinal()/(this->fps/2));
	}

	_mainWin.draw(lineToDraw);
}
/**
Fonction qui indique si la ligne a été complètement afficher.
@return True si la ligne est complètement afficher. False sinon.
*/
bool SquareDisplay::DisplayCompleted(Line &line)
{
	if(line.getDyCurrent() >= line.getDyFinal() && line.getDxCurrent() >= line.getDxFinal() )
	{
		return true;
	}
	return false;
}

/**
Fonction qui permet l'affichage d'un rectangle.
@param[in] _mainWin Référence sur la fenêtre d'affichage.
@param[in] _fps Le nombre de frame par seconde de la fenêtre. Si il est a 0, ajoute le rectangle au complet [defaut]
@param[out] _mainWin la fenêtre d'affichage ajouté du rectangle.
@return True si l'ajout du rectangle est complété. False s'il n'est que partiellement ajouté.
@see instantDisplay
@see progressiveDisplay
*/
bool SquareDisplay::Display(RenderWindow& _mainWin, Square &square)
{
	if (this->fps == 0)
	{
		//Affichage d'un coup
		this->SquareInstantDisplay(_mainWin,square);
		return true;
	}
	else
	{
		//Affichage progressif
		return this->SquareProgressiveDisplay(_mainWin,square);
	}

}
/**
Fonction qui fait l'affichage du rectangle de façon progressive. Elle décide quelle fonction d'affichage appeler.
@param[in] _mainWin Référence sur la fenêtre d'affichage.
@param[in] _fps Le nombre de frame par seconde de la fenêtre.
@param[out] _mainWin la fenêtre d'affichage ajouté du rectangle.
@return True si l'ajout du rectangle est complété. False s'il n'est que partiellement ajouté.

*/
bool SquareDisplay::SquareProgressiveDisplay(RenderWindow& _mainWin, Square &square)
{
	Line* line1 = square.getLignesComposition(0);
	Line* line2 = square.getLignesComposition(1);
	Line* line3 = square.getLignesComposition(2);
	Line* line4 = square.getLignesComposition(3);

	if (this->DisplayCompleted(*line1) == false && this->DisplayCompleted(*line2) == false)
	{
		//Supérieur
		this->SquareProgressiveDisplayTop(_mainWin, square);
		return false;
	}
	else if (this->DisplayCompleted(*line3) == false && this->DisplayCompleted(*line4) == false)
	{
		//Inférieur
		this->SquareProgressiveDisplayTop(_mainWin, square);
		this->SquareProgressiveDisplayBottom(_mainWin,square);
		return false;
	}
	else
	{
		//Pour protection: Complet
		this->SquareInstantDisplay(_mainWin, square);
		return true;
	}
}

/**
Fonction qui fait L'affichange instané du rectangle.
@param[in] _mainWin Référence sur la fenêtre d'affichage.
@param[out] _mainWin la fenêtre d'affichage ajouté du rectangle.
@see Line::InstantDisplay
*/
void SquareDisplay::SquareInstantDisplay(RenderWindow& _mainWin, Square &square)
{
	for (int i = 0; i < 4; i++)
	{ 
		Line* lineToDisplay = square.getLignesComposition(i);
		this->LineInstantDisplay(_mainWin,*lineToDisplay);
	}
}
/**
Fonction qui fait l'affichange progressive des deux premières lignes du rectangle.
@param[in] _mainWin Référence sur la fenêtre d'affichage.
@param[in] _fps Le nombre de frame par seconde de la fenêtre.
@param[out] _mainWin la fenêtre d'affichage ajouté du rectangle.
@see Line::PregressiveDisplay
*/
void SquareDisplay::SquareProgressiveDisplayTop(RenderWindow& _mainWin, Square &square)
{
	Line* lineToDisplay1 = square.getLignesComposition(0);
	Line* lineToDisplay2 = square.getLignesComposition(1);
	this->LineProgressiveDisplay(_mainWin, *lineToDisplay1);
	this->LineProgressiveDisplay(_mainWin, *lineToDisplay2);
}
/**
Fonction qui fait l'affichange progressive des deux dernières lignes du rectangle.
@param[in] _mainWin Référence sur la fenêtre d'affichage.
@param[in] _fps Le nombre de frame par seconde de la fenêtre.
@param[out] _mainWin la fenêtre d'affichage ajouté du rectangle.
@see Line::PregressiveDisplay
*/
void SquareDisplay::SquareProgressiveDisplayBottom(RenderWindow& _mainWin, Square &square)
{
	Line* lineToDisplay1 = square.getLignesComposition(2);
	Line* lineToDisplay2 = square.getLignesComposition(3);
	this->LineProgressiveDisplay(_mainWin, *lineToDisplay1);
	this->LineProgressiveDisplay(_mainWin, *lineToDisplay2);
}