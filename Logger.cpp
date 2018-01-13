// ---------------------------------------------------------------------------

#pragma hdrstop

#include "Logger.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
// ---------------------------------------------------------------------------
#pragma package(smart_init)

std::string Logger::_fileName =
	"D:\\Ѕиблиотека\\Study\\3.1\\ќјиѕ_2\\Projects\\Project_1_1\\log.txt";

void Logger::WriteInfo(std::string message) {
	std::ofstream out;
	out.open(_fileName, std::ios::app);
	out << GetCurrentDateTime() << std::endl;
	out << message << std::endl;
	out << std::endl;
	out.close();
}

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string Logger::GetCurrentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	// Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	// for more information about date/time format
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;
}

