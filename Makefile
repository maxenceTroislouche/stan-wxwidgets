all: main

MainFrame.o: MainFrame.cpp
	g++ -c MainFrame.cpp `wx-config --cxxflags --libs`

main: App.cpp MainFrame.o
	g++ App.cpp MainFrame.o -o main `wx-config --cxxflags --libs`

clean:
	rm main MainFrame.o