#once again, C++ is a nuisance to deal with large numbers such
#as a 1000 digit fibonacci number

fn_1, fn_2 = 1, 1 #set initial fib values
counter = 2 #keep track of the term

while (len(str(fn_1)) < 1000): #cast the integer to a string and use len to count digits
    fn_1 = fn_2 + fn_1
    fn_2 = fn_1 - fn_2
    counter += 1

#exits loop after the 1000 digits number is found and counter is value of the term
print counter

