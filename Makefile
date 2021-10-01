CXX = g++
CXXFLAGS = -std=c++14 -MMD -Werror=vla -Wall -Wextra -Wpedantic -g
EXEC = straights
OBJECTS = main.o card.o deck.o player.o table.o controller.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean
