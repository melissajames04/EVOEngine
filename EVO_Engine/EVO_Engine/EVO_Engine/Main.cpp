
#include "EVOEngine.h"

int main(int argc, char* args[]) {

	EVO_ENGINE::EVOEngine::GetInstance()->Initialize();
	EVO_ENGINE::EVOEngine::GetInstance()->Run();

	return 0;
}