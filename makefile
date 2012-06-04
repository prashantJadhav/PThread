
EXECUTABLE := thread 
INCLUDE=/media/songs/linnnux/worm/inc
INCLUDEFLAG:= -I $(INCLUDE)
logObj:=/media/songs/linnnux/worm/src/Logger.o


all : $(EXECUTABLE)

$(EXECUTABLE) : thread.o Mutex.o ThreadPool.o TestPool.o FileOperations.o #WorkerThread.o
		#g++ -shared -lcurl -ldl -o $(EXECUTABLE) WebCraw.o /media/songs/linnnux/worm/src/Logger.o 
		g++  $(INCLUDEFLAG) -g -lcurl -lpcrecpp -lhtmlcxx -o $(EXECUTABLE) thread.o Mutex.o ThreadPool.o FileOperations.o /media/songs/linnnux/worm/src/Logger.o thread_main.cpp 

thread.o :  
	   #g++ $(INCLUDEFLAG) -c WebCrawlerPlugin.cpp -o WebCraw.o
	   g++ $(INCLUDEFLAG) -c PThread.cpp  -o thread.o  -std=c++0x

Mutex.o :
	  g++ $(INCLUDEFLAG) -c Mutex.cpp -o Mutex.o  -std=c++0x 

FileOperations.o :
	  g++  $(INCLUDEFLAG) -c FileOperations.cpp -o FileOperations.o

ThreadPool.o :
	g++  $(INCLUDEFLAG) -c ThreadPool.cpp -o ThreadPool.o 

#WorkerThread.o :
#	g++ $(INCLUDEFLAG) -c WorkerThread.cpp -o WorkerThread.o

clean : 
	rm -rf *.so *.o ${EXECUTABLE}
      
# g++  HtmlParsing.cpp -o tst -lpcrecpp  -std=c++0x

