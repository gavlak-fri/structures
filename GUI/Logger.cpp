#include "Logger.h"

using namespace std;
using namespace DS;

void Logger::Error(string message)
{
	Error(gcnew System::String(message.c_str()));
}

void Logger::Warning(string message)
{
	Warning(gcnew System::String(message.c_str()));
}

void Logger::Hint(string message)
{
	Hint(gcnew System::String(message.c_str()));
}

void Logger::Wait(string message)
{
	Wait(gcnew System::String(message.c_str()));
}

void Logger::Debug(string message)
{
	Debug(gcnew System::String(message.c_str()));
}

void DS::Logger::Error(System::String ^ message)
{
	if (ilog_ != nullptr)
		ilog_->Log(LogType::ERROR, message);
}

void DS::Logger::Warning(System::String ^ message)
{
	if (ilog_ != nullptr)
		ilog_->Log(LogType::WARNING, message);
}

void DS::Logger::Hint(System::String ^ message)
{
	if (ilog_ != nullptr)
		ilog_->Log(LogType::HINT, message);
}

void DS::Logger::Wait(System::String ^ message)
{
	if (ilog_ != nullptr)
		ilog_->Log(LogType::WAIT, message);
}

void DS::Logger::Debug(System::String ^ message)
{
	if (ilog_ != nullptr)
		ilog_->Log(LogType::DEBUG, message);
}

void Logger::initialize(ILogger ^ ilog)
{
	ilog_ = ilog;
}
