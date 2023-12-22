NAME = fractol
SRCS = main.c utils.c render.c init.c math.c events.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror 

%c: %.o
	${CC} ${CFLAGS} -c $< -o $@

all : $(NAME)
$(NAME):	$(OBJS)
			make -C ./mlx
			${CC} ${CFLAGS} ${OBJS} -L./mlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
valgrind:
    valgrind --leak-check=full ./$(NAME)

clean : 
	rm -f ${OBJS}