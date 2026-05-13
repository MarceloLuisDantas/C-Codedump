from random import randint

def main() :
    file = 0
    while file != 10 :
        f1 = open("./file{}.txt".format(file + 1), "w")
        words = 0
        while (words != 10000) :
            num1 = randint(0, 200)
            f1.write("{} ".format(num1))
            words += 1
        file += 1
    

main()