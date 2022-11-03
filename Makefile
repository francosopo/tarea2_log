parteUno:
	gcc -Wall -pedantic -std=c99 -O -g parte_uno.c -lm

parteDos:
	gcc -Wall -pedantic -std=c99 -O -g parte_dos.c -lm

parteTres:
	gcc -Wall -pedantic -std=c99 -O -g parte_tres.c -lm
.PHONY: parteUno parteDos parteTres
