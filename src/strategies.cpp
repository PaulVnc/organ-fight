#include "strategies.h"
#include <stdlib.h> 


void Context::setStrategy(std::unique_ptr<Strategy> new_strategy)
{
	strategy = std::move(new_strategy);
}

int Context::executeStrategy() {
	return strategy->execute();
}

int BasicStrategy::execute() {
	int dice = rand() % 100;
	if (dice < 50) return 0;
	else return 1;
}

int J1losingStrategy::execute() {
	int dice = rand() % 100;
	if (dice < 75) return 0;
	else return 1;
}

int J2losingStrategy::execute() {
	int dice = rand() % 100;
	if (dice < 25) return 0;
	else return 1;
}