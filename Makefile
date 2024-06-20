CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -O2

# raylib directory (adjust this to your setup)
RAYLIB_DIR = /opt/homebrew/Cellar/raylib/5.0
INCLUDES = -I$(RAYLIB_DIR)/include
LIBS = -L$(RAYLIB_DIR)/lib -lraylib -lm -lpthread -ldl -framework OpenGL -framework OpenAL -framework IOKit -framework CoreVideo

# Source files
SRCS = src/snake.c src/drawGrid.c
SRCS = src/snake.c src/linkedList.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = snake_game

# Default target
all: $(TARGET)

# Link object files to create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Phony targets
.PHONY: all clean run
