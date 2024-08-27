# Sudoku-Maker
 ## Intro
 With this project, I intend to explore some options to solve/generate a sudoku from scratch through an algorithm.  
 The main approach towards making/solving a sudoku remains fairly similar in the two approaches I took, though there are differences in efficiency.  

 ## Naive Approach
 This approach is very fitting, as it was my first idea of how to solve a sudoku. It is a very bruteforce approach where you go over every cell in the sudoku individually and recursively and assign it a number if needed.  
 Doing this recursively will allow it to roll back to previous instances if it reaches a dead end and you won't need to manually contain each instance through member variables.  

### Steps
To do this, you'll need to:  
- Create a recursive function that has the entire available sudoku and the index of the cell you're currently checking.  
- Check if the current cell is assigned or not. If not, assign it a random value from 1-9 and keep checking if the value is valid, until it is.  
- If you run out of numbers to test and none were valid, return to start backtracking.  
- Call the recursive function with the edited sudoku and the first next index. If you're at the end, you currently have a solved sudoku!  

### Big O
The Big O notation for this approach is O(9^(NxN)), with N being the size of the grid (in this and most cases 9) and the constant 9 referring to the amount of possible numbers (1-9).  
This means that for all NxN -> 9x9 -> 81 cells, you need to check all 9 options in combination with oneanother.  

## Backtracking Approach
With this approach, we'll take the same direction as with the Naive Approach, but we'll be a bit more considerate to our memory by first looking ahead to find our next empty cell and only THEN adding a recursive stack.  
This will not make a massive difference (it won't even make any difference to the Big O notation) but it will in general be more efficient due to a notable decrease in recursive calls.  

### Steps
To do this, you'll need to:  
- Create a recursive function that has the entire available sudoku.  
- Check for the first next empty cell.  
-  If there is one, assign a number between 1-9 and keep checking if it's valid, until it is.  
-  If you run out of numbers to test and none were valid, return false to start backtracking.  
-  If there is none, you currently have a solved sudoku!  
- Call the recursive function with the edited sudoku (unless it is already solved).  

### Big O
The Big O notation for this approach is still O(9^(NxN)), just like the previous approach. The big difference here is in the size of your recursive call stack. 

## Conclusion
The conclusion will be more for myself rather than anything else, since the latter approach is objectively better than the former and there's little to learn there. I, however, have enjoyed the journey in understanding the general approach in solving sudoku's and some of the ways there are to improve on it. Though I have only skimmed the surface on what you can do with this, I implore you to check out my source if you so wish. They have helped me wrap my head around this topic with far clearer explanations and visualisations and even explore some more improved approaches to this problem.

## Source
https://www.geeksforgeeks.org/sudoku-backtracking-7/
