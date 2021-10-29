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



Addition
---
At the beginning of the game, if the player manages to immediately open an empty cell, then 8 more cells will open around it. Also, if you enter an already open cell with the value "0", the numbers around it will also open. Данная функция поможет быстрее продвинуться в прохождении игры. Также на случай спорного варианта (когда бомба может находится в нескольких местах и нельзя узнать наверняка, и в таких случаях обычно открывается дополнительная зона) присутствует функция оглашения: правильно ли пользователь поставил флаг. Таким образом, если пользователь не угадал, и оглашения не было, можно просто поменять позицию поставленного ранее флага. 
