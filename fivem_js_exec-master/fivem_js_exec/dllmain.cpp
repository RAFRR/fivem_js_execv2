#include "ExecJS.h"

/* Credits: 
	alcantara99
	krasnoludXD
	rafrr
*/

int main() {
	Exec::init();

	while ( true ) {
		if (GetAsyncKeyState(VK_NUMPAD8)) {
			Exec::runFile("C:\\memes\\skid.js");
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}


bool DllMain(HMODULE hModule, DWORD  call_reason, LPVOID lpReserved){
	if (call_reason == DLL_PROCESS_ATTACH)
		std::thread(main).detach();

	return true;
}

