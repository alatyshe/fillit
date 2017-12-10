OFILES = src/ft_read_doc.o src/ft_massives_xy.o src/ft_finnal_massive.o\
		src/doing_massive.o src/ft_structures.o src/ft_putstr.o src/main.o

NAME = fillit

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OFILES)
	gcc -o $(NAME) $(OFILES)

main.o: src/main.c
	gcc -c $(FLAGS) main.c

ft_read_doc.o: src/ft_read_doc.c
	gcc -c $(FLAGS) ft_read_doc.c

ft_massives_xy.o: src/ft_massives_xy.c
	gcc -c $(FLAGS) ft_massives_xy.c

ft_finnal_massive.o: src/ft_finnal_massive.c
	gcc -c $(FLAGS) ft_finnal_massive.c

doing_massive.o: src/doing_massive.c
	gcc -c $(FLAGS) doing_massive.c

ft_structures.o: src/ft_structures.c
	gcc -c $(FLAGS) ft_structures.c

ft_putstr.o: src/ft_putstr.c
	gcc -c $(FLAGS) ft_putstr.c

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
