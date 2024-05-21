# Tic Tac Toe!

This game is made by [@Tam-vir](https://github.com/Tam-vir) using C++

# A Short Explanation Of The Code-

How does this work?

A Game class is defined inside which there's a 2D vector called `board` which has the data for each cells. The class also has some public functions like `void drawBoard()`, `void takeInput()`, `bool checkWinner()` and `bool playableMove()`;

The `drawBoard()` function is mainly a nested for loop printing all the elements inside the `board` vector. Which is almost like pattern printing. The `#ifdef` you see there is basically for enabling cross-platform support for coloring the $\color{red}{X}$ and $\color{cyan}{O}$. Windows doesn't support ANSI color codes so I had to check whether the program is compiled in windows or other OS and use colors based on that.

The `takeInput()` function takes use input from `main()` function. `playbaleMove()` checks if the cell that user has inputed has already been played in. `checkWinner()` checks whether there is a winnder or not before every move is played.

inside the `int main()` function the 
