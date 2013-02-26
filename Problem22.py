from string import ascii_uppercase

<<<<<<< HEAD
def calculate_score(name, index):
    alpha_score = sum(ascii_uppercase.index(letter)+1 for letter in name)
    return index * alpha_score

def main():
    names_file = open('names.txt')
    names_string = names_file.read()
    names = [name.strip('"') for name in names_string.split(',')] 
    names.sort()
    print sum(calculate_score(name, index+1) for index, name in enumerate(names))
    names_file.close()

main()
=======
#sums up the alphabetical position and multiplies it by index in list
def calcScore(name, index):
    return index * (sum(ascii_uppercase.index(i) + 1 for i in name))

def main():
    f = open ('names.txt')
    Names = f.read() #read in everything as a string
    Names = [i.strip('"') for i in Names.split(',')] #split the input into a list of names
    Names.sort() #sort the list in alphabetical order
    print sum (calcScore(name, index+1) for index, name in enumerate(Names)) #total all the name scores
    f.close()

main()

>>>>>>> 77e530b7b3e4d96a0858afbaf977ae047ab9d3b5
