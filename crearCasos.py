import random
import string

def generar_cadena(tam):
    """Genera una cadena aleatoria de tamaño 'tam' con caracteres en minúscula."""
    return ''.join(random.choices(string.ascii_lowercase, k=tam))

def generar_pares_de_strings(cantidad, min_len, max_len):
    """Genera una lista de pares de strings con tamaños aleatorios entre min_len y max_len."""
    casos = []
    for tam in range(min_len, max_len, 1):
        for _ in range(cantidad):
            str1 = generar_cadena(tam)
            str2 = generar_cadena(tam)
            casos.append((str1, str2))
    return casos

def guardar_casos(casos, filename):
    """Guarda los casos generados en un archivo."""
    with open(filename, 'w') as f:
        for str1, str2 in casos:
            f.write(f"{str1} {str2}\n")

cantidad = 10  # Cantidad de casos a generar
min_len = 2     # Longitud mínima de las cadenas
max_len = 12    # Longitud máxima de las cadenas
filename = 'casosPruebaTamanos.txt'  # Nombre del archivo donde se guardarán los casos

# Generar los casos
casos = generar_pares_de_strings(cantidad, min_len, max_len)

# Guardar los casos en el archivo
guardar_casos(casos, filename)

print(f"Se han generado {cantidad} casos de prueba y se han guardado en '{filename}'.")