#include "FileOperations.h"
#include "PThread.h"

#include<iostream>

using namespace Pthread;
using namespace std;

bool FileOperations::instanceFlag=false ;
FileOperations* FileOperations::fileOperations=NULL ;
//FileOperations::print2File


FileOperations::FileOperations()
 {
	cout<<"FileOperations::CTOR"<<endl;

	log=log->getInstance("webCrawler");

	log->Write2Log("INFO","FileOperations::FileOperations");

	reportDir="./Reports/";
	
	m_mutex =new Mutex();



	
 }

FileOperations::FileOperations(string report)
 {

	
	reportDir="./Reports/";
	
	//reportFile=report;

	std::string reportName=reportDir+report;

	reportFile.open(reportName.c_str(),ios::app);
}

FileOperations::~FileOperations()
{
	 log->Write2Log("INFO","~FileOperations::FileOperations");
	reportFile.close();
}

/*
@author: Pashant

string to get the isntance
*/

FileOperations* FileOperations::getInstance(std::string str)
 {
	if(!instanceFlag)
	{
		//fileOperations = new FileOperations(str);
		fileOperations = new FileOperations(str);

		instanceFlag=true;
		return fileOperations;
	}
	else
	{
		return fileOperations;
	}
}

void FileOperations::setReportFile(std::string str)
 {
	report = str;
 }

std::string FileOperations::getReportFile()
 {
	return report;
 }

std::string FileOperations::getReportDir()
 {
	return reportDir ;
 }

void FileOperations::print2File(void *args)
 {
	cout<<"FileOperations::print2File"<<endl;

	FileOperations *fo=(FileOperations *)args;

//	cout<<"hi="<<fo->getHtmlBuffer();

	fo->write2File(fo->getReportFile(),fo->getHtmlBuffer());
}

/*@document
 this non static function is used to write tt othe file 
1) get file nam 
2) get file fgontaent 
3) check if file is not present 
4) if present write to the file with the thread id
5) else creat the file for first time use 
*/
void FileOperations::write2File(std::string fileName,std::string fileContents)
 {
        cout<<"FileOperations::write2File"<<endl;
	

	std::string reportName=reportDir+fileName;

        reportFile.open(reportName.c_str(),ios::app);

	 //reportFile.open("./tank");
         if(reportFile.is_open())
          {
               cout<<"Continuing with prog"<<endl;
          }
         else
         {
               cout<<"creating the file before writing to it "<<endl;
         }

	reportFile<<"("<<PThread::getID()<<")"<<fileContents<<endl;
	reportFile<<"hiii="<<fileContents<<endl;

}


/*void FileOperations::print2File(std::string reportName,std::string reportBuffer)
{
	
	//og->Write2Log("INFO","FileOperations::print2File");
	reportFile<<"================================================================================================================="<<endl;
	reportFile<<"<BR><B>the Page : "<<reportName<<"contails below link</B>"<<endl;
	reportFile<<reportBuffer<<endl;
}
*/
void FileOperations::print2File(std::string reportName,std::vector<std::string> tmpVec)
{

	vector<string>::iterator it= tmpVec.begin();
        //og->Write2Log("INFO","FileOperations::print2File");
        reportFile<<"================================================================================================================="<<endl;
        reportFile<<"<BR><B>the Page : "<<reportName<<"contails below link</B>"<<endl;
	for(;it!=tmpVec.end();it++)
	{

         	reportFile<<"<br>Link="<<*it<<endl;
	}
}

/*documentation
author prashant
 Function to read teh file ocntineusly and display its contents
*/
void FileOperations::readFile(void *args)
{
	cout<<"FileOperations:;readFile"<<endl;

	//FileOperations *fo=new FileOperations();

//	FileOperations *fileOperation=dynamic_cast<FileOperations *>(args); 

	 FileOperations *fileOperation = (FileOperations *)args;
	//Mutex mmutex =new Mutex();

	
	fileOperation->m_mutex->lock();
	fileOperation->reaad(NULL);
	cout<<"iiiiiiiiiii";

	//FileOperations::read();
	fileOperation->m_mutex->unlock();

}

void FileOperations::reaad(void *args)
 {

	//take the reference of the class objet tht is paased

	//FileOperations *fileOperation = (FileOperations *)args ;

	cout<<"FileOperations::reaad"<<endl;	

	try
	{
		string STRING ;
		file.open("./tst");
		if(file.is_open())
		 {
			cout<<"Continuing with prog"<<endl;
		 }
		else
		 {
			cout<<"ëting"<<endl;
			throw "File Not found Exception";
			//return ;
		}

		while(!file.eof())
	 	{

			//cout<<"kooool"<<endl;
		 	getline(file,STRING); // Saves the line in STRING.
	        	cout<<STRING<<endl; // Prints our STRING.
		}

		file.close();
	}
	catch(...)
	{
		cout<<"xcepption caught"<<endl;
		//return ;
	}
 }



