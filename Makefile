# El compilador: gcc para programas en C, define como g++ para C++
CC = g++
# Opciones de compilación
CFLAGS = 
# Directorios de los archivos fuente y archivos binarios
src = src
bin = bin
# El nombre del ejecutable
TARGET = greedy


# Construir todos los objetivos
all: $(bin)/$(TARGET)

# Construir el objetivo
$(bin)/$(TARGET): $(src)/$(TARGET).cpp | $(bin)
	$(CC) $(CFLAGS) -o $(bin)/$(TARGET) $(src)/$(TARGET).cpp

# Ejecutar el objetivo
run:
	./$(bin)/$(TARGET)

# Limpiar los archivos generados
clean: 
	$(RM) $(bin)/*

# Crear el directorio bin si no existe
$(bin):
	mkdir -p $(bin)
