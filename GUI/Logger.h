#pragma once

#include <string>

namespace DS {

	enum LogType
	{
		ERROR,
		WARNING,
		HINT,
		WAIT,
		DEBUG
	};

	interface class ILogger
	{
		void Log(LogType lt, System::String^ message);
	};

	ref class Logger
	{
	private:
		static ILogger^ ilog_;
	public:

		static void Error(std::string message);
		static void Warning(std::string message);
		static void Hint(std::string message);
		static void Wait(std::string message);
		static void Debug(std::string message);

		static void Error(System::String^ message);
		static void Warning(System::String^ message);
		static void Hint(System::String^ message);
		static void Wait(System::String^ message);
		static void Debug(System::String^ message);

		static void initialize(ILogger^ ilog);
	};

}
