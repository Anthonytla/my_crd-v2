##
## ETNA PROJECT, 30/03/2021 by la_t
## my_crd
## File description:
##      Makefile
##

CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c11
DFLAGS = -g -fsanitize=address

SRC = src/main.c src/my_getnbr.c src/my_map_init.c src/my_map_insert.c src/my_map.c src/my_map_remove.c src/my_putchar.c src/my_putnbr.c src/my_readline.c src/my_str_to_word_array.c

OBJ = $(SRC:.c=.o)

TARGET = my_crd

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

debug: $(OBJ)
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJ) -o $(TARGET)

clean:
	$(RM) $(OBJ) *~

fclean: clean
	$(RM) $(TARGET)

re: fclean all
