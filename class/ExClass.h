#include <stdint.h>

class ExClass
{
public:
	ExClass(double value);
	double getValue();
	double addValue(double valueToAdd);

private:
	double value;
};