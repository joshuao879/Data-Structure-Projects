"""def HelloWorld():
    print("Hello World")

def Greeting(name):
    print("Hi " + name)

HelloWorld()
Greeting("Josh")

def Sum(num1, num2):
    print(num1 + num2)

def returnSum(num1, num2):
    return (num1 + num2)

sum = returnSum(12,12)

print(sum)




def plusOne(digits):
    i = 0
    for i in digits:
        if i == len(digits) - 1:
            digits[i] = digits[i]+1
            return digits
            
"""

position_index = int(input("Choose an index position: "))

#row1[position_index]

def display(row1,row2,row3):
    print(row1)
    print(row2)
    print(row3)

def user_choice():
    
    choice = 'WRONG'
    acceptable_range = range(0,10)
    within_range = False

    while choice.isdigit() == False or within_range == False:
        choice = input("Please enter a number (0-10): ")

        if choice.isdigit() == False:
            print("Sorry that is not a digit!")

        if choice.isdigit() == True:
            if int(choice) in acceptable_range:
                within_range = True
            else:
                print("sorry, you are out of acceptable range (0-10)")

    return int(choice)
    
user_choice()
