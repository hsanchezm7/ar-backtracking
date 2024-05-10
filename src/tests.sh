#!/bin/bash

# Verifica que se haya proporcionado un argumento
if [ $# -ne 1 ]; then
    echo "Uso: $0 <número>"
    exit 1
fi

# Guarda el argumento en una variable
iterador=$1

# Inicia un bucle con el iterador proporcionado como argumento
for (( i=1; i<=$iterador; i++ )); do
    echo "Bucle $i:"
    # Llama a programa1 con el valor actual de i como argumento
    user_time=$( { time -p ./gen "$i" | ./greedy; } 2>&1 | grep user )
    echo $user_time
done

