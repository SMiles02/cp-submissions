s = list(str(input()))

def turnAllUpper(s):
    for i in range(0, len(s)):
        if s[i] == "a":
            s[i] = "A"

        if s[i] == "b":
            s[i] = "B"

        if s[i] == "c":
            s[i] = "C"

        if s[i] == "d":
            s[i] = "D"

        if s[i] == "e":
            s[i] = "E"

        if s[i] == "f":
            s[i] = "F"

        if s[i] == "g":
            s[i] = "G"

        if s[i] == "h":
            s[i] = "H"

        if s[i] == "i":
            s[i] = "I"

        if s[i] == "j":
            s[i] = "J"

        if s[i] == "k":
            s[i] = "K"

        if s[i] == "l":
            s[i] = "L"

        if s[i] == "m":
            s[i] = "M"

        if s[i] == "n":
            s[i] = "N"

        if s[i] == "o":
            s[i] = "O"

        if s[i] == "p":
            s[i] = "P"

        if s[i] == "q":
            s[i] = "Q"

        if s[i] == "r":
            s[i] = "R"

        if s[i] == "s":
            s[i] = "S"

        if s[i] == "t":
            s[i] = "T"

        if s[i] == "u":
            s[i] = "U"

        if s[i] == "v":
            s[i] = "V"

        if s[i] == "w":
            s[i] = "W"

        if s[i] == "x":
            s[i] = "X"

        if s[i] == "y":
            s[i] = "Y"

        if s[i] == "z":
            s[i] = "Z"

    print(''.join(s))

def turnAllLower(s):
    for i in range(0, len(s)):
        if s[i] == "A":
            s[i] = "a"

        if s[i] == "B":
            s[i] = "b"

        if s[i] == "C":
            s[i] = "c"

        if s[i] == "D":
            s[i] = "d"

        if s[i] == "E":
            s[i] = "e"

        if s[i] == "F":
            s[i] = "f"

        if s[i] == "G":
            s[i] = "g"

        if s[i] == "H":
            s[i] = "h"

        if s[i] == "I":
            s[i] = "i"

        if s[i] == "J":
            s[i] = "j"

        if s[i] == "K":
            s[i] = "k"

        if s[i] == "L":
            s[i] = "l"

        if s[i] == "M":
            s[i] = "m"

        if s[i] == "N":
            s[i] = "n"

        if s[i] == "O":
            s[i] = "o"

        if s[i] == "P":
            s[i] = "p"

        if s[i] == "Q":
            s[i] = "q"

        if s[i] == "R":
            s[i] = "r"

        if s[i] == "S":
            s[i] = "s"

        if s[i] == "T":
            s[i] = "t"

        if s[i] == "U":
            s[i] = "u"

        if s[i] == "V":
            s[i] = "v"

        if s[i] == "W":
            s[i] = "w"

        if s[i] == "X":
            s[i] = "x"

        if s[i] == "Y":
            s[i] = "y"

        if s[i] == "Z":
            s[i] = "z"

    print(''.join(s))



lowerCase = s.count("a")
lowerCase = s.count("b") + lowerCase
lowerCase = s.count("c") + lowerCase
lowerCase = s.count("d") + lowerCase
lowerCase = s.count("e") + lowerCase
lowerCase = s.count("f") + lowerCase
lowerCase = s.count("g") + lowerCase
lowerCase = s.count("h") + lowerCase
lowerCase = s.count("i") + lowerCase
lowerCase = s.count("j") + lowerCase
lowerCase = s.count("k") + lowerCase
lowerCase = s.count("l") + lowerCase
lowerCase = s.count("m") + lowerCase
lowerCase = s.count("n") + lowerCase
lowerCase = s.count("o") + lowerCase
lowerCase = s.count("p") + lowerCase
lowerCase = s.count("q") + lowerCase
lowerCase = s.count("r") + lowerCase
lowerCase = s.count("s") + lowerCase
lowerCase = s.count("t") + lowerCase
lowerCase = s.count("u") + lowerCase
lowerCase = s.count("v") + lowerCase
lowerCase = s.count("w") + lowerCase
lowerCase = s.count("x") + lowerCase
lowerCase = s.count("y") + lowerCase
lowerCase = s.count("z") + lowerCase

upperCase = s.count("A")
upperCase = s.count("B") + upperCase
upperCase = s.count("C") + upperCase
upperCase = s.count("D") + upperCase
upperCase = s.count("E") + upperCase
upperCase = s.count("F") + upperCase
upperCase = s.count("G") + upperCase
upperCase = s.count("H") + upperCase
upperCase = s.count("I") + upperCase
upperCase = s.count("J") + upperCase
upperCase = s.count("K") + upperCase
upperCase = s.count("L") + upperCase
upperCase = s.count("M") + upperCase
upperCase = s.count("N") + upperCase
upperCase = s.count("O") + upperCase
upperCase = s.count("P") + upperCase
upperCase = s.count("Q") + upperCase
upperCase = s.count("R") + upperCase
upperCase = s.count("S") + upperCase
upperCase = s.count("T") + upperCase
upperCase = s.count("U") + upperCase
upperCase = s.count("V") + upperCase
upperCase = s.count("W") + upperCase
upperCase = s.count("X") + upperCase
upperCase = s.count("Y") + upperCase
upperCase = s.count("Z") + upperCase

if upperCase > lowerCase:
    turnAllUpper(s)

else:
    turnAllLower(s)