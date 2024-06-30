#pragma once
#include <fstream>
#include <iostream>
#include <filesystem>
#include <Windows.h>
#include <libloaderapi.h>
#include <string>
#include <memory>

#include "Logger.h"
#include "ini.h"

namespace fs = std::filesystem;
using namespace mINI;

class ModLoader
{
public:
	void LoadMods();

private:
	// Logger m_logger{ "Mod Loader" };
	std::unique_ptr<Logger> m_logger; // Changed to a smart pointer
	std::string m_modFolder = ".\\mods";
	std::string m_logPath = "mod_loader_log.txt";
	DWORD m_loadDelay = 5000;
	bool m_showTerminal = false;
	INIStructure m_ini;

	void ReadConfigFile();
	void StartLogger();
	std::vector<std::pair<int64_t, std::string>> FindModsAndReadLoadOrders();
	void LoadDllMods();
	void OpenTerminal();
	void OnLoadingDone();
};