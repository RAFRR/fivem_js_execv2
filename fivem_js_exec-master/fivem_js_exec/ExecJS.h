#pragma once
#include <string>
#include <functional>
#include <Windows.h>
#include <string>
#include <thread>
#include "CustomAPI.h"


extern uint64_t citizenV8Base;
extern uint64_t grabbedClass;

enum MemoryAddresses {
	RunFileInternalAddr = 0x36390,
	LoadSystemFileInternalAddr = 0x35250,
	V8Instance = 0x72D38,
};

using RunFileInternal_t = int(*)(uint64_t, char*, std::function<int(char*, uint64_t)>);
using LoadSystemFileInternal_t = int(*)(uint64_t, char*, uint64_t);

namespace Exec {
	extern void runFile(std::string file);
	extern void init();
}