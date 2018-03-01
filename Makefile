##
## Makefile for Makefile in /home/bechad_p/rendu/cpp_nibbler
## 
## Made by Pierre Bechade
## Login   <bechad_p@epitech.net>
## 
## Started on  Thu Mar 26 11:16:22 2015 Pierre Bechade
## Last update Sat Apr 25 15:24:11 2015 Pierre Bechade
##

CXX		=	g++

RM		=	rm -f

CXXFLAGS	=	-W -Wall -Werror -pthread -std=c++11

CXXFLAGS	+=	-I./project/plazza/.
CXXFLAGS	+=	-I./project/pizza/.
CXXFLAGS	+=	-I./project/reception/.
CXXFLAGS	+=	-I./project/kitchen/.
CXXFLAGS	+=	-I./project/communication/.
CXXFLAGS	+=	-I./project/mlock/.

CXXFLAGS	+=	-I./project/IMutex/.
CXXFLAGS	+=	-I./project/IThread/.
CXXFLAGS	+=	-I./project/INamePipes/.

NAME		=	plazza

SRCS		=	project/main.cpp				\
			project/plazza/plazza.cpp			\
			project/pizza/pizza.cpp				\
			project/reception/reception.cpp			\
			project/kitchen/kitchen.cpp			\
			project/communication/communication.cpp		\
			project/mlock/mlock.cpp

OBJS		=	$(SRCS:.cpp=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			$(CXX) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			fclean clean all
