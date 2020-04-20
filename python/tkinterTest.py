import tkinter
import turtle

class Application(tkinter.Frame):

    def __init__(self, master = None):

        super().__init__(master)
        self.master = master
        self.pack()
        self.createWidgets()

    def createWidgets(self):
        
        self.Square = tkinter.Button(self)
        self.Square["text"] = "Square"
        self.Square["command"] = self.drawSquare
        self.Square.pack(side="left")

        self.quit = tkinter.Button(self, text="QUIT", fg="red",
                              command=self.master.destroy)
        self.quit.pack(side="right")

    def drawSquare(self):
        print("OLA")

class Miojo(tkinter.Canvas):

    def __init__(self, master = None):

        super().__init__(master)
        self.master = master



root = tkinter.Tk()
app = Application(master=root)
app.mainloop()