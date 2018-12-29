CC = g++

LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

CFLAGS = -Wall -Wextra

CPPFLAGS = -IParticles/inc

SRC = 	Particles/main.cpp \
	Particles/src/Particle.cpp \
	Particles/src/ParticlesManager.cpp \
	Particles/src/Spawner.cpp

NAME = Particles.out

RM = rm -f

$(NAME): all

all:
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS) $(LDLIBS)

clean:
	$(RM) $(NAME)

.PHONY: all clean