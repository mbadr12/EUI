#include<stdio.h>

#define	DEBUG		1
#define INFO		2
#define WARNING		3
#define ERROR		4

/* choose your Log Level
* DEBUG	
* INFO	
* WARNING	
* ERROR	
*/
#define LOG_LEVEL DEBUG
void LogDebug(char* LogMessage,char* FileName,u32 LineNum);
void LogInfo(char* LogMessage,char* FileName,u32 LineNum);
void LogWarning(char* LogMessage,char* FileName,u32 LineNum);
void LogError(char* LogMessage,char* FileName,u32 LineNum);
void main(void)
{
	#if LOG_LEVEL==DEBUG
	LogDebug("Debug","Debug File",35);
	#elif LOG_LEVEL==DEBUG
	LogInfo("Info","Info File",21);
	#elif LOG_LEVEL==WARNING
	LogWarning("Warning","Warning File",22);
	#elif LOG_LEVEL==ERROR
	LogError("Error","Error File",2);
	#else
		#error "Wrong Log level"
}
void LogDebug(char* LogMessage,char* FileName,u32 LineNum)
{
	printf("Log Message: %s\n",LogMessage);
	printf("File name: %s\n",FileName);
	printf("Line number: %u\n",LogMessage);
}
void LogInfo(char* LogMessage,char* FileName,u32 LineNum)
{
	printf("Log Message: %s\n",LogMessage);
	printf("File name: %s\n",FileName);
	printf("Line number: %u\n",LogMessage);
}
void LogWarning(char* LogMessage,char* FileName,u32 LineNum)
{
	printf("Log Message: %s\n",LogMessage);
	printf("File name: %s\n",FileName);
	printf("Line number: %u\n",LogMessage);
}
void LogError(char* LogMessage,char* FileName,u32 LineNum)
{
	printf("Log Message: %s\n",LogMessage);
	printf("File name: %s\n",FileName);
	printf("Line number: %u\n",LogMessage);
}