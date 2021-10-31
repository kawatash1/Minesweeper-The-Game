[[Русский]](https://github.com/kawatash1/SaperTheGame/blob/main/README-ru.md)

The **Minesweeper** console game written in C++ has a slightly different implementation from the original version.


Specifications
---
* Code writing with Visual Studio 2019
* Gameplay is done by keyboard input


How to play
---
Upload the file [Minesweeper.cpp](https://github.com/kawatash1/SaperTheGame/blob/main/Saper.cpp) and open it with any code editor. Next, run the program with the button `run`.

### Rules of the game
The goal of the Minesweeper game is to open empty cells without opening any containing a mine.

The game starts by entering the position of any cell on the field. After that, it will open and a number will be displayed. This number indicates the number of mines in adjacent cells. Several adjacent numbered cells can indicate the same mines, and this allows you to accurately identify dangerous cells. If there are no mines either in the cell itself or in the cells adjacent to it, then a zone with empty cells in the radius opens.

For convenience, mine slots can be marked with flags.

The game is won as soon as all cells that do not contain mines are open.


### Addition

If the first cell opened by the user turns out to be an empty cell, then 8 more cells will open around it. This will also work if you enter the position of an already open cell with the "0". This feature will help you progress faster in the game. Also, in case of a controversial option (when it is impossible to know for sure where the mine is located), an announcement function is provided, the task of which is to notify the user whether he has set the flag correctly. Thus, if the player has not guessed correct position, and there was no announcement, he can simply change the position of the flag set earlier to another one.
