CC = g++

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS = -Wall -Wextra

CPPFLAGS = -IParticles/inc

SRC = 	Particles/main.cpp \
	Particles/src/Particle.cpp \
	Particles/src/ParticlesManager.cpp \
	Particles/src/Spawner.cpp

NAME = Particles.out

RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS)

clean:
	$(RM) $(NAME)

.PHONY: all clean