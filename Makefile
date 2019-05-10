CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic -std=c++17 -o consolefire
LDFLAGS=
LDLIBS= -lncurses
SRC = fire.cc consolefire.cc
OBJ = ${SRC:.cc=.o}
EXEC = consolefire

all: ${EXEC}

${EXEC}:${OBJ}
	${CXX} ${CXXFLAGS} ${LDLIBS} ${SRC}

clean:
	${RM} consolefire ${OBJ}
