
main : main.o SpeechInput.o SpeechOutput.o  \
       SemanticAnalysis.o Logger.o BookSearcher.o PersonalAssistant.o \
			 CharacterSegmentation.o CharacterRecognition.o
	g++ main.o SpeechInput.o SpeechOutput.o  \
	    SemanticAnalysis.o Logger.o BookSearcher.o PersonalAssistant.o \
			CharacterSegmentation.o CharacterRecognition.o \
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

BookSearcher.o : common.h BookSearcher.h BookSearcher.cpp
	g++ -c BookSearcher.cpp

PersonalAssistant.o : common.h PersonalAssistant.h PersonalAssistant.cpp
	g++ -c PersonalAssistant.cpp

CharacterSegmentation.o : common.h CharacterSegmentation.h CharacterSegmentation.cpp
	g++ -c CharacterSegmentation.cpp

CharacterRecognition.o : common.h CharacterRecognition.h CharacterRecognition.cpp
	g++ -c CharacterRecognition.cpp

#DataBaseInput.o : DataBaseInput.h DataBaseInput.cpp
	#g++ -c DataBaseInput.cpp
#
#Database.o : Database.h Database.cpp
	#g++ -c Database.cpp
#
#Disk.o : Disk.h Disk.cpp
	#g++ -c Disk.cpp
#
#
#CameraInput.o : CameraInput.h CameraInput.cpp
	#g++ -c CameraInput.cpp
#
#MonitorImageOutput.o : MonitorImageOutput.h MonitorImageOutput.cpp
	#g++ -c MonitorImageOutput.cpp
#

clean : 
	rm ../bin/main main.o SpeechInput.o SpeechOutput.o  \
	        SemanticAnalysis.o Logger.o BookSearcher.o PersonalAssistant.o \
					CharacterSegmentation.o CharacterRecognition.o
