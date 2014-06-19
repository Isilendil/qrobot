
main : main.o SpeechInput.o SpeechOutput.o
	g++ main.o SpeechInput.o SpeechOutput.o -o main -pthread -std=c++0x

main.o : main.cpp
	g++ -c main.cpp -pthread -std=c++0x

SpeechInput.o : SpeechInput.h SpeechInput.cpp
	g++ -c SpeechInput.cpp

SpeechOutput.o : SpeechOutput.h SpeechOutput.cpp
	g++ -c SpeechOutput.cpp

clean : 
	rm main main.o SpeechInput.o
