# CPPND: Capstone Robber Game

Capstone project of Laura de Jong in the Udacity C++ Nanodegree Program, build upon the snake starter code of Udaciy in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.


## Instructions

Clone the project repository:
    ```git clone https://github.com/laurasdejong/CppND-Capstone-Robber-Game.git```

Build the project: ```make build```

Run the resulting executable in <yourpath>/CppND-Capstone-Robber-Game/build: ```./robberGame```

For more info see: https://github.com/udacity/CppND-Program-a-Concurrent-Traffic-Simulation

## Game play

The goal of this game is to rob as much gold as possible. The game has two modes. First the robber needs to track its target, after which the game switches to robbing-mode then the robber must decide how much to extort. If the robber asks for more than the target can give, the robber kills the target, and influences future income because of decreased 'town income'(thus, targets wil carry less). However, when the target has the amount the robber asks for, only that amount is transferred to the robber. Each n seconds, the robber has to pay a fee to the 'robbers guild'.

The game ends when either the town is empty, the robber is bankrupt, or the robber has earned enough to declare himself 'robber king'.

## Code structure

<img src="doc/code_structure.png"/>

## Rubric points

### README
| Criteria       |Intended| Displayed in  |
| ------------- |:---:| ---------------:|
| A README with instructions is included with the project|- [x] |this |
| The README indicates which project is chosen.|- [x] |See [Game play](#Game) and [Code structure](#Code)|
| The README includes information about each rubric point addressed.|- [x] |this|
### Compiling and Testing
| Criteria       |Intended| Displayed in  |
| ------------- |:---:| ---------------:|
| The submission must compile and run.|- [x] | See [Instructions](#instructions)|
### Loops, Functions, I/O
| Criteria       |Intended| Displayed in  |
| ------------- |:---:| ---------------:|
| The project demonstrates an understanding of C++ functions and control structures.| | |
| The project reads data from a file and process the data, or the program writes data to a file.| | |
| The project accepts user input and processes the input.| | |
### Object Oriented Programming
| Criteria       |Intended| Displayed in  |
| ------------- |:---:| ---------------:|
| The project uses Object Oriented Programming techniques.| | |
| Classes use appropriate access specifiers for class members.| | |
| Class constructors utilize member initialization lists.| | |
| Classes abstract implementation details from their interfaces.| | |
| Classes encapsulate behavior.| | |
| Classes follow an appropriate inheritance hierarchy.| | |
| Overloaded functions allow the same function to operate on different parameters.| | |
| Derived class functions override virtual base class functions.| | |
| Templates generalize functions in the project.| | |
### Memory Management
| Criteria       |Intended| Displayed in  |
| ------------- |:---:| ---------------:|
| The project makes use of references in function declarations.| | |
| The project uses destructors appropriately.| | |
| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.| | |
| The project follows the Rule of 5.| | |
| The project uses move semantics to move data, instead of copying it, where possible.| | |
| The project uses smart pointers instead of raw pointers.| | |
### Concurrency
| Criteria       |Intended| Displayed in  |
| ------------- |:---:| ---------------:|
| The project uses multithreading.| | |
| A promise and future is used in the project.| | |
| A mutex or lock is used in the project.| | |
| A condition variable is used in the project.| | |
