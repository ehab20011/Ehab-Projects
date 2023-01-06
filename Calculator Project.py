#Ehabs Calculator

import math
import tkinter as tk #tkinter needed for userinterface
import tkinter.messagebox #import needed to display message boxes in the userinterface application.
from tkinter.constants import SOLID #importing SOLID style option for the button

window = tk.Tk() #Opens up a window pop-up
window.title ('EHABS CALCULATOR') #Title for the calculator
greeting = tk.Label( 
text = "EHABS CALCULATOR", 
fg = "white", #font color
bg = "black", #background color
width = 33, #width
height = 2  #height
) #Adding calculator title to the UI part
greeting.pack() #dispalys the above message^

frame = tk.Frame(master=window, bg="gold", padx=5) #Creates the Framed space where user will enter / answer will be displayed
frame.pack() #Displays the framed white space

entry = tk.Entry(master=frame, relief='solid', borderwidth=5, width=28) #Creates the Space for the user entry inside the framed space.
entry.grid(row=0, column=0, columnspan=3, ipady=2, pady=2) #dimensions for the entry space

def click(number): #Click function for "number"
    entry.insert(tk.END, number) #entry widget allowing user to enter something for "number"

def equals(): #The equals function #This is where the math happens.
    try: #entry widgets for the try part of the equals function
        y = str(eval(entry.get())) #Intialize y to an object that will evaluate the text after retrieving with .get()
        entry.delete(0, tk.END)
        entry.insert(0, y)
    except:
        tkinter.messagebox.showinfo("Error", "Syntax Error") #Display an error message when you type some dumb shit

def clear(): #clear function that will be able to CLEAR memory and the white box text
    entry.delete(0, tk.END) #entry.delete to do this^

#All buttons on the userinterface
#lambda command to take on the click function with an input of whatever number is on the button
#.grid is where the button will be placed on the application window (example: 1, 0 , 2)
#first button frame and functionality
button1 = tk.Button(master=frame, text='1', padx=10,
                     pady=7, width=3, command=lambda: click(1))
button1.grid(row=1, column=0, pady=2)

#second button frame and functionality
button2 = tk.Button(master=frame, text='2', padx=10,
                     pady=7, width=3, command=lambda: click(2))
button2.grid(row=1, column=1, pady=2)

#third button frame and functionality
button3 = tk.Button(master=frame, text='3', padx=10,
                     pady=7, width=3, command=lambda: click(3))
button3.grid(row=1, column=2, pady=2)

#fourth button frame and functionality
button4 = tk.Button(master=frame, text='4', padx=10,
                     pady=7, width=3, command=lambda: click(4))
button4.grid(row=2, column=0, pady=2)

#fifth button frame and functionality
button5 = tk.Button(master=frame, text='5', padx=10,
                     pady=7, width=3, command=lambda: click(5))
button5.grid(row=2, column=1, pady=2)

#sixth button frame and functionality
button6 = tk.Button(master=frame, text='6', padx=10,
                     pady=7, width=3, command=lambda: click(6))
button6.grid(row=2, column=2, pady=2)

#seventh button frame and functionality
button7 = tk.Button(master=frame, text='7', padx=10,
                     pady=7, width=3, command=lambda: click(7))
button7.grid(row=3, column=0, pady=2)

#eigth button frame and functionality
button8 = tk.Button(master=frame, text='8', padx=10,
                     pady=7, width=3, command=lambda: click(8))
button8.grid(row=3, column=1, pady=2)

#ninth button frame and functionality
button9 = tk.Button(master=frame, text='9', padx=10,
                     pady=7, width=3, command=lambda: click(9))
button9.grid(row=3, column=2, pady=2)
#0th button frame and functionality
button0 = tk.Button(master=frame, text='0', padx=10,
                     pady=7, width=3, command=lambda: click(0))
button0.grid(row=4, column=1, pady=2)

#addition button and functionality
buttonadd = tk.Button(master=frame, text="+", padx=10,
                       pady=7, width=3, command=lambda: click('+'))
buttonadd.grid(row=1, column=3, pady=2)

#subtraction button and functionality
buttonsub = tk.Button(master=frame, text="-", padx=10, 
                            pady=7, width=3, command=lambda: click('-'))
buttonsub.grid(row=2, column=3, pady=2)

#multiplication button and functionality
buttonmultiply = tk.Button(master=frame, text="*", padx=10, 
                            pady=7, width=3, command=lambda: click('*'))
buttonmultiply.grid(row=3, column=3, pady=2)
 
#division button and functionality
buttondiv = tk.Button(master=frame, text="/", padx=10,
                       pady=7, width=3, command=lambda: click('/'))
buttondiv.grid(row=4, column=3, pady=2)

#decimal button and functionality
buttondecim = tk.Button(master=frame, text=".", padx=10,
                       pady=7, width=3, command=lambda: click('.'))
buttondecim.grid(row=4, column=2, pady=2)

#clear button and functionality
buttonclear = tk.Button(master=frame, text="CE",
                         padx=10, pady=7, width=3, command=clear) #commands it to clear the white box
buttonclear.grid(row=4, column=0,  pady=2)

#equals button and functionality
buttonequal = tk.Button(master=frame, text="=", padx=10,
                         pady=5, width=12, command=equals)
buttonequal.grid(row=7, column=0, columnspan = 2, pady=2)



window.mainloop() #Dispalys the application

