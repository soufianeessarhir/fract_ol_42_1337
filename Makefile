NAME = fractol
BNAME = bonus_fractol

SOURCES = main.c utils.c ft_atod.c utils1.c evants.c\

BSOURCES = main_bonus.c utils_bonus.c ft_atod_bonus.c utils1_bonus.c evants_bonus.c\

OBJECTS = $(SOURCES:.c=.o)
B_OBJECTS = $(BSOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%_bonus.o: %_bonus.c fractol_bonus.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c $<

bonus: $(BNAME)

$(BNAME): $(B_OBJECTS)
	$(CC) $(B_OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(BNAME)


clean:
	$(RM) $(OBJECTS) $(B_OBJECTS)

fclean: clean
	$(RM) $(NAME) $(BNAME)

re: fclean all