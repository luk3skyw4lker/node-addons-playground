#include "ExClass.h"

ExClass::ExClass(double value)
{
	this->value = value;
}

double ExClass::getValue()
{
	return this->value;
}

double ExClass::addValue(double valueToAdd)
{
	this->value = this->value + valueToAdd;

	return this->value;
}