import random
import sys

def crearAristas(size): # size es un entero
    f = open(f"{size}.txt", "w")
    linea = [str(random.randint(0, 2**14)) for i in range(0, size*3)]
    linea = "\n".join(linea)
    f.write(linea)
    f.close()


crearAristas(int(sys.argv[1]))
