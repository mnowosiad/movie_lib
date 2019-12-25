import sys
import Search

from six.moves import urllib

from PyQt5.Qt import QPushButton
from PyQt5.QtCore import *
from PyQt5.QtGui import *
from PyQt5.QtWidgets import QApplication, QWidget, QLineEdit, QMessageBox, QMainWindow



class Base(QMainWindow):

    def __init__(self):
        QMainWindow.__init__(self)
        self.back = QPushButton("BACK", self)
        self.back.resize(0,0)
        self.textbox = QLineEdit(self)
        self.textbox.resize(0, 0)
        self.title = QPushButton("MY MOVIE BASE", self)
        self.export = QPushButton("Export my base to XML", self)
        self.showall = QPushButton("Show my movies", self)
        self.search = QPushButton("Search for a movie", self)
        self.initUI()

    def initUI(self):
        self.setStyleSheet("border-style: outset;"
                           "border-width: 2px;"
                           "border-radius: 7px;"
                           "border-color: #7a7a77;"
                           "background-color: #3b4347;")
        self.setGeometry(100, 200, 400, 485)
        self.setWindowTitle("MY MOVIE BASE")

        self.title.move(10,20)
        self.title.resize(380,80)
        self.title.setStyleSheet("color:#ff00ff;"
                                 "background-color:#140014;"
                                 "border-style: outset;"
                                 "border-width: 2px;"
                                 "border-radius: 7px;"
                                 "font: bold 40px;"
                                 "border-color: #ff00ff;")

        self.export.move(10, 235)
        self.export.resize(380, 50)
        self.export.clicked.connect(self.on_click_export)

        self.showall.move(10, 175)
        self.showall.resize(380, 50)
        self.showall.clicked.connect(self.on_click_show)

        self.search.move(10, 115)
        self.search.resize(380, 50)
        self.search.clicked.connect(self.on_click_search)

        self.back.clicked.connect(self.on_click_back)

        self.options =[self.export, self.showall, self.search, self.back]


        for option in self.options:
            option.setStyleSheet("QPushButton{color:#00ffff;"
                                 "background-color:#001414;"
                                 "border-style: outset;"
                                 "border-width: 2px;"
                                 "border-radius: 7px;"
                                 "font:  20px;"
                                 "border-color: #00ffff;}"
                                 "QPushButton:hover{color:#ffff00;"
                                 "border-color: #ffff00;}"
                                 )

            self.textbox.setStyleSheet("QLineEdit{color:#00ffff;"
                                 "background-color:#001414;"
                                 "border-style: outset;"
                                 "border-width: 2px;"
                                 "border-radius: 7px;"
                                 "font:  20px;"
                                 "border-color: #00ffff;}"
                                 )

        #self.showall.clicked.connect(self.Num)

        #self.show()

    @pyqtSlot()
    def on_click_search(self):
        print("search")
        self.title.resize(0,0)
        self.export.resize(0,0)
        self.showall.resize(0,0)
        self.search.resize(0,0)
        self.textbox.resize(380, 50)
        self.textbox.move(10, 75)
        self.back.move(10, 235)
        self.back.resize(380, 50)
        resp = urllib.request.urlopen('https://www.omdbapi.com/?s=barbie&apikey=ba1f4581')
        print(resp.read())

    def on_click_show(self):
        print("show")


    def on_click_export(self):
        print("export");

    def on_click_back(self):
       self.textbox.resize(0, 0)
       for option in self.options:
          option.clicked.disconnect()

       self.initUI()





app = QApplication(sys.argv)
main = Base()
main.show()
sys.exit(app.exec_())
