LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CC = g++
SOURCES = main.cpp Body.cpp Cadrsbuffer.cpp Controlling.cpp Entity.cpp Field.cpp File.cpp Interface.cpp Map.cpp Script.cpp State.cpp Tilemap.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = Test

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBS) -L /home/mmark/.local/lib/SFML-2.5.1/lib

.cpp.o:
	$(CC) -c $< -o $@ -I /home/mmark/.local/lib/SFML-2.5.1/include

clean:
	rm -f Test
	rm -f *.o
