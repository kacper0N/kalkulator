# Kompilator i flagi
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Domyślny cel 'all'
all: calculator

# Kompilacja kalkulatora
calculator: calculator.c
	$(CC) $(CFLAGS) -o calculator calculator.c

# Cel czyszczenia plików binarnych
clean:
	rm -f calculator
