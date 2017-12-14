#include "cell.h"


void Cell::setRow(int arow)
{
	this->row = arow;
}

int Cell::getRow()
{
	return this->row;
}

void Cell::setCol(int acol)
{
	this->col = acol;
}

int Cell::getCol()
{
	return this->col;
}

void Cell::setBlock(int ablock)
{
	this->block = ablock;
}

int Cell::getBlock()
{
	return this->block;
}

void Cell::setValue(int avalue)
{
	this->value = avalue;
}
		
int Cell::getValue()
{
	return this->value;
}

void Cell::setFlag(int aflag)
{
	this->flag = aflag;
}

int Cell::getFlag()
{
	return this->flag;
}

