#include "strategies.h"
#include <stdlib.h> 


void Context::setStrategy(Strategy new_strategy)
{
	strategy = &new_strategy;
}

int Context::executeStrategy() {
	return strategy->execute();
}

int BasicStrategy::execute() {
	int dice = rand() % 100;
	if (dice < 0.5) return 0;
	else return 1;
}

int J1losingStrategy::execute() {
	int dice = rand() % 100;
	if (dice < 0.75) return 0;
	else return 1;
}

int J2losingStrategy::execute() {
	int dice = rand() % 100;
	if (dice < 0.25) return 0;
	else return 1;
}