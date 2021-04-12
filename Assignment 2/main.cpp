#include <iostream>
#include "StageManager.h"

int main()
{
	changeStage(0);
	running = true;

	while (running)
		PlayStage(stage);

	return 0;
}