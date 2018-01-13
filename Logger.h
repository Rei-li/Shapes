// ---------------------------------------------------------------------------
#pragma once
#ifndef LoggerH
#define LoggerH
#include <string>
// ---------------------------------------------------------------------------
#endif

class Logger {
	static std::string _fileName;

public:
	static void WriteInfo(std::string message);

private:
	static const std::string GetCurrentDateTime();

};
