import numpy as np


def cipher():
    size = int(input("Tamaño de la retícula cuadrada\n"))
    dir = int(input("Dirección de la rotación:\nsentido de las manecillas del reloj=0\nsentido contrario=1\n"))

    count = 0
    print('Celdas')
    for i in range(size):
        for j in range(size):
            print(count, '\t', end="")
            count += 1
        print()
    holes = input(
        "Ingrese las celdas en las que hay hoyos (Arriba se ve la matriz con las celdas). ej 0 1 2 3 \n")
    holes = [int(x) for x in holes.split()]
    message = input("Mensaje a cifrar\n")

    if dir:
        axes = (0, 1)
    else:
        axes = (1, 0)
    message = message.upper()
    message = message.replace(" ", "")

    pos_message = 0

    grille_rot = np.array([x in holes for x in range(size * size)])

    grille_text = np.array(["" for x in range(size * size)])

    grille_rot = grille_rot.reshape(size, size)
    grille_text = grille_text.reshape(size, size)
    for k in range(4):
        for i in range(size):
            for j in range(size):
                if pos_message >= len(message):
                    break
                if grille_rot[i][j] and grille_text[i][j] == "":
                    grille_text[i][j] = message[pos_message]
                    pos_message += 1
        grille_rot = np.rot90(grille_rot, k=1, axes=axes)

    print("Texto cifrado: ")
    for i in range(size):
        for j in range(size):
            print(grille_text[i][j], end="")
        print(end=" ")


def decipher():
    size = int(input("Tamaño de la retícula cuadrada:\n"))
    dir = int(input("Dirección de la rotación:\nsentido de las manecillas del reloj=0\nsentido contrario=1\n"))

    count = 0
    print('Celdas')
    for i in range(size):
        for j in range(size):
            print(count, '\t', end="")
            count += 1
        print()
    holes = input(
        "Ingrese las celdas en las que hay hoyos (Arriba se ve la matriz con las celdas). ej 0 1 2 3 \n")
    holes = [int(x) for x in holes.split()]
    message = input("Mensaje a decifrar:\n")

    if dir:
        axes = (0, 1)
    else:
        axes = (1, 0)
    message = message.upper()
    message = message.replace(" ", "")
    if len(message) < size * size:
        message += 'X' * (size - len(message))

    grille_rot = np.array([x in holes for x in range(size * size)])
    grille_text = np.array([message[x] for x in range(size*size)])

    grille_rot = grille_rot.reshape(size, size)
    grille_text = grille_text.reshape(size, size)

    plain_text = ""

    for k in range(4):
        for i in range(size):
            for j in range(size):
                if grille_rot[i][j]:
                    plain_text += grille_text[i][j]
                    grille_text[i][j] = ""
        grille_rot = np.rot90(grille_rot, k=1, axes=axes)

    print("Texto decifrado: ")
    for i in range(size):
        for j in range(size):
            print(plain_text[i*size+j], end="")
        print(end=" ")


mode = input("Modo: \nCifrar=0 \nDecifrar=1\n")

if mode == '0':
    cipher()
else:
    decipher()
