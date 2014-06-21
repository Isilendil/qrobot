
main : main.o SpeechInput.o SpeechOutput.o  \
       SemanticAnalysis.o Logger.o
	g++ main.o SpeechInput.o SpeechOutput.o  \
	    SemanticAnalysis.o Logger.o \
			-L"../lib" -lqcontroller \
			-o ../bin/main -pthread -std=c++0x; \
	export LD_LIBRARY_PATH="../lib":$$LD_LIBRARY_PATH

main.o : common.h main.cpp
	g++ -c main.cpp -pthread -std=c++0x

SpeechInput.o : common.h SpeechInput.h SpeechInput.cpp
	g++ -c SpeechInput.cpp

SpeechOutput.o : common.h SpeechOutput.h SpeechOutput.cpp
	g++ -c SpeechOutput.cpp

SemanticAnalysis.o : common.h SemanticAnalysis.h SemanticAnalysis.cpp
	g++ -c SemanticAnalysis.cpp

Logger.o : common.h Logger.h Logger.cpp
	g++ -c Logger.cpp


#DataBaseInput.o : DataBaseInput.h DataBaseInput.cpp
	#g++ -c DataBaseInput.cpp
#
#DataBaseOutput.o : DataBaseOutput.h DataBaseOutput.cpp
	#g++ -c DataBaseOutput.cpp
#
#DiskInput.o : DiskInput.h DiskInput.cpp
	#g++ -c DiskInput.cpp
#
#DiskOutput.o : DiskOutput.h DiskOutput.cpp
	#g++ -c DiskOutput.cpp
#
#CameraInput.o : CameraInput.h CameraInput.cpp
	#g++ -c CameraInput.cpp
#
#MonitorImageOutput.o : MonitorImageOutput.h MonitorImageOutput.cpp
	#g++ -c MonitorImageOutput.cpp
#

clean : 
	rm ../bin/main main.o SpeechInput.o SpeechOutput.o  \
	        SemanticAnalysis.o Logger.o
