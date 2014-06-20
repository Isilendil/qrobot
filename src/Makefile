
#main : main.o SpeechInput.o SpeechOutput.o TouchInput.o ActionOutput.o \
       #ShellInput.o ShellOutput.o LightOutput.o \
			 #DataBaseInput.o DataBaseOutput.o DiskInput.o DiskOutput.o \
			 #CameraInput.o MonitorImageOutput.o EyesImageOutput.o
	#g++ main.o SpeechInput.o SpeechOutput.o TouchInput.o ActionOutput.o \
	    #ShellInput.o ShellOutput.o LightOutput.o \
			#DataBaseInput.o DataBaseOutput.o DiskInput.o DiskOutput.o \
			#CameraInput.o MonitorImageOutput.o EyesImageOutput.o \
			#-o main -pthread -std=c++0x
main : main.o SpeechInput.o SpeechOutput.o \
       SemanticAnalysis.o
	g++ main.o SpeechInput.o SpeechOutput.o \
	    SemanticAnalysis.o \
			-o main -pthread -std=c++0x

main.o : main.cpp
	g++ -c main.cpp -pthread -std=c++0x

SpeechInput.o : SpeechInput.h SpeechInput.cpp
	g++ -c SpeechInput.cpp

SpeechOutput.o : SpeechOutput.h SpeechOutput.cpp
	g++ -c SpeechOutput.cpp

SemanticAnalysis.o : SemanticAnalysis.h SemanticAnalysis.cpp
	g++ -c SemanticAnalysis.cpp

#TouchInput.o : TouchInput.h TouchInput.cpp
	#g++ -c TouchInput.cpp
#
#ActionOutput.o : ActionOutput.h ActionOutput.cpp
	#g++ -c ActionOutput.cpp
#
#ShellInput.o : ShellInput.h ShellInput.cpp
	#g++ -c ShellInput.cpp
#
#ShellOutput.o : ShellOutput.h ShellOutput.cpp
	#g++ -c ShellOutput.cpp
#
#LightOutput.o : LightOutput.h LightOutput.cpp
	#g++ -c LightOutput.cpp
#
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
#EyesImageOutput.o : EyesImageOutput.h EyesImageOutput.cpp
	#g++ -c EyesImageOutput.cpp
#
clean : 
	rm main main.o SpeechInput.o SemanticAnalysis.o
