from tkinter import Tk, Label, Button
import os
from PIL import ImageTk, Image

def one_B():
    os.system('g++ one_bar.cpp -o one_b -lglut -lGL -lGLU && ./one_b')

def two_B():
    os.system('g++ two_bars.cpp -o two_b -lglut -lGL -lGLU && ./two_b')

def four_B():
    os.system('g++ four_bars.cpp -o four_b -lglut -lGL -lGLU -lGLEW && ./four_b')


window = Tk()
window.geometry('600x600')
window.title('F-16 radar bars sim')
image = Image.open("FCR+(Fire+Control+Radar)+Display.jpg")  
image = image.resize((400, 400))  

photo = ImageTk.PhotoImage(image)

label = Label(window, image=photo)
label.pack()
one_b = Button(window, text="one B", command=one_B).pack()
two_b = Button(window, text="two B", command=two_B).pack()
four_b = Button(window, text="four B", command=four_B).pack()


window.mainloop()
