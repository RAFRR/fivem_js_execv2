#pragma once
#include "ExecJS.h"

uint64_t citizenV8Base = (uint64_t)(CustomAPI::GetModuleA("citizen-scripting-v8"));
uint64_t grabbedClass;
bool grabbed = false;

auto RunFileInternal = (RunFileInternal_t)(citizenV8Base + MemoryAddresses::RunFileInternalAddr);
auto CitizenFX_LoadSystemFileInternal = (LoadSystemFileInternal_t)(citizenV8Base + MemoryAddresses::LoadSystemFileInternalAddr);

namespace Exec {

	int LoadSystemFileInternal(uint64_t destination, char* scriptFile, uint64_t outScript) {
		return CitizenFX_LoadSystemFileInternal(destination, scriptFile, outScript);
	}

	int LoadSystemFile(uint64_t destination, char* scriptFile) {
		return RunFileInternal(destination, scriptFile, std::bind(&LoadSystemFileInternal, destination, std::placeholders::_1, std::placeholders::_2));
	}

	void runFile(std::string file) {
		LoadSystemFile(grabbedClass, const_cast<char*>(file.c_str()));
	}
	
	void init() {
		std::thread([&]() {
			while (grabbed == false) {
				std::this_thread::sleep_for(std::chrono::milliseconds(50));

				uint64_t currentClass = *(uint64_t*)(citizenV8Base + MemoryAddresses::V8Instance);
				if (currentClass != NULL)
				{
					grabbedClass = currentClass;
					grabbed = true;
				}
					
					
			}
		}).detach();
	}
}