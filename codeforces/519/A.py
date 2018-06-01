inpL=[]
inpL+=list(str(input()))
inpL+=list(str(input()))
inpL+=list(str(input()))
inpL+=list(str(input()))
inpL+=list(str(input()))
inpL+=list(str(input()))
inpL+=list(str(input()))
inpL+=list(str(input()))
white = (inpL.count("Q") * 9) + (inpL.count("R") * 5) + (inpL.count("B") * 3) + (inpL.count("N") * 3) + inpL.count("P")
black = (inpL.count("q") * 9) + (inpL.count("r") * 5) + (inpL.count("b") * 3) + (inpL.count("n") * 3) + inpL.count("p")
if white>black:
    print("White")
elif white<black:
    print("Black")
else:
    print("Draw")