LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

CXXFLAGS = -Wall -Wextra -std=c++14

CPPFLAGS = -IParticles/inc

SRC = 	Particles/main.cpp \
	Particles/src/Particle.cpp \
	Particles/src/ParticlesManager.cpp \
	Particles/src/Spawner.cpp

NAME = Particles.out

RM = rm -f

all: $(NAME)

$(NAME):
	$(CXX) -o $(NAME) $(SRC) $(CXXFLAGS) $(CPPFLAGS) $(LDLIBS)

clean:
	$(RM) $(NAME)

.PHONY: all clean