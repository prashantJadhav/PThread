#ifndef __FILE_OPERATIONS__
#define __FILE_OPERATIONS__

#include <fstream>
#include <vector>

#include "Logger.h" 
#include "Mutex.h"

namespace Pthread{

class FileOperations
{

	private:
		static bool instanceFlag;
		static FileOperations *fileOperations;
		std::string report;
		std::string reportDir;
		std::string m_htmlBuffer;
	public :
		FileOperations();
		FileOperations(std::string);
		~FileOperations();
		void print2File();
		static void print2File(void *);
		void write2File(std::string,std::string);
		void print2File(std::string,std::vector<std::string>);
		void printXmlFile();
		//std::string getHtmlBuffer();
		inline void setHtmlBuffer(std::string str)
		 {
			m_htmlBuffer=str;
		 }
		void setReportFile(std::string);
		std::string getReportDir();
		std::string getReportFile();
		Logger *log;
		static void readFile(void *);
		void reaad(void *);
		//void string2Write(std::string);


		static FileOperations* getInstance(std::string);
		std::ofstream reportFile;
		std::ifstream file; 
		Mutex *m_mutex ;

		inline std::string getHtmlBuffer()
		{
			return m_htmlBuffer;
		}
};
}//
#endif
