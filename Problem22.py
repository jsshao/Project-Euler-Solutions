from string import ascii_uppercase

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

