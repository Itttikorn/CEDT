def tree():
    height = int(input("Enter height: "))
    for i in range(height):
        print(" "*(height-i-1) + "*"*(2*i+1))

tree()