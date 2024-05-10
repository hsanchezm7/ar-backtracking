# El compilador: gcc para programas en C, define como g++ para C++
CC = g++
# Opciones de compilación
CFLAGS = 
# Directorios de los archivos fuente y archivos binarios
src = src
bin = bin
# El nombre del ejecutable
GREEDY_TARGET = greedy
BACKTRACKING_TARGET = backtracking


# Construir todos los objetivos
all: greedy backtracking

# Construir el objetivo
greedy: $(src)/$(GREEDY_TARGET).cpp | $(bin)
	$(CC) $(CFLAGS) -o $(bin)/$(GREEDY_TARGET) $(src)/$(GREEDY_TARGET).cpp

# Construir el objetivo
backtracking: $(src)/$(BACKTRACKING_TARGET).cpp | $(bin)
	$(CC) $(CFLAGS) -o $(bin)/$(BACKTRACKING_TARGET) $(src)/$(BACKTRACKING_TARGET).cpp

# Ejecutar el objetivo
#run:
#	./$(bin)/$(TARGET)

# Limpiar los archivos generados
clean: 
	$(RM) $(bin)/*

# Crear el directorio bin si no existe
$(bin):
	mkdir -p $(bin)
