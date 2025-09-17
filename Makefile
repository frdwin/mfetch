# Variables
CC = gcc
CFLAGS = -Wall -Wextra
SRC = src/kernel.c src/os.c src/mfetch.c src/pkgs.c src/shell.c src/uptime.c src/user.c
OBJ = $(SRC:.c=.o)
TARGET = mfetch
INSTALL_DIR = /usr/bin

# Compile executable file
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compile object files
%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Install
install: $(TARGET)
	install -m 755 $(TARGET) $(INSTALL_DIR)

clean:
	rm -f $(OBJ) $(TARGET)

uninstall:
	rm -f $(INSTALL_DIR)/$(TARGET)

# Execute Makefile without args
.PHONY: all install clean uninstall
all: $(TARGET) install
