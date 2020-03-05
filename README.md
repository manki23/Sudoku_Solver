# Sudoku_Solver
Solver réalisé dans le cadre d'une colle de la piscine C de 42.

## Téléchargement
```
git clone https://github.com/manki23/Sudoku_Solver.git ; cd Sudoku_Solver
```

## Utilisation
Ce solver de sudoku en C prends en entrée 9 chaines de charactères, une par ligne du sudoku,
avec des ```.``` pour représenter des cases vides.

Ainsi, pour solver ce sudoku :

![Sudoku_Picture](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/220px-Sudoku-by-L2G-20050714.svg.png "Sudoku example")


Il faut entrer ceci :
```
./sudoku "53..7...." "6..195..." ".98....6." "8...6...3" "4..8.3..1" "7...2...6" ".6....28." "...419..5" "....8..79"
```

La solution se présente de cette façon :
```
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```
