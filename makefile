
CXX = g++
CXXFLAGS = -std=c++0x
LDFLAGS = -lboost_date_time

OBJS = Main.o Game.o Character.o InputValidation.o Barbarian.o BlueMen.o HarryPotter.o Medusa.o Vampire.o

SRCS = Main.cpp Game.cpp Character.cpp InputValidation.cpp Barbarian.cpp BlueMen.cpp HarryPotter.cpp Medusa.cpp Vampire.cpp

Headers = Game.hpp Character.hpp InputValidation.hpp Barbarian.hpp BlueMen.hpp HarryPotter.hpp Medusa.hpp Vampire.hpp

game: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) $(HEADERS) -o $@

$(OBJ): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o = .cpp)

clean:
	rm $(OBJS) game
