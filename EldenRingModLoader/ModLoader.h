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
	std::string m_configPath = getenv("INI_PATH") ? getenv("INI_PATH") : "mod_loader_config.ini";
	std::string m_modFolder = getenv("MODS_PATH") ? getenv("MODS_PATH") : ".\\mods";
	std::string m_logPath = getenv("LOG_PATH") ? getenv("LOG_PATH") : "mod_loader_log.txt";
	std::unique_ptr<Logger> m_logger;
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