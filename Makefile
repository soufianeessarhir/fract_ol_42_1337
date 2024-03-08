NAME = fractol
SOURCES = main.c\
		  utils.c\

#BSOURCES =  
    
    

OBJECTS = $(SOURCES:.c=.o)
#B_OBJECTS = $(BSOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM =rm -f


all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS)  -lmlx -framework OpenGL -framework AppKit -o  $(NAME) 

#bonus: $(B_OBJECTS)
#$(AR) $(NAME) $(B_OBJECTS)

%.o : %.c 
	$(CC) $(CFLAGS) -Imlx -c $< 

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all