## Introduction
The topic of my semester project is a game called _**Remember me**_. The main goal of the game is to improve people's memory in an entertaining way. There is a grid of square and some of them will blink for a while. The user has click those tiles that have blinked and of course it has to be done in the right order. The faster you do it the more points you will obtain. There is a system of scores so people could compete with each other. All scores are saved in a file, and they are loaded during program execution. I have also implemented an animation system so that transitions look a little bit smoother and it's been made in such a way so it can be reused.

## Internal specification
The necessary part of internal specification was to cover four different types of programming techniques. Below I listed those which have been used during development of the game and I described them briefly.
* **inheritance and polymorphism** - One of the most powerful things in object oriented programming. It's been used in state machine. The class *StateManager* contains a map of classes which derive from *State* class and depending on the time it renders the right state on the screen, checks user inputs and updates all objects. Another usage of inheritance we can find in animation system. There exists class *Animation* which derives from class *Timer* and another class called *FadeoutAnimation* which derives from *Animation*.
* **templates** - They can be find in the animation system. Templates were necessary to add in order to animate different values. At the beginning there were different classes for different types of variables, but I figured out that it isn't right to rewrite same code twice. There are two template classes *Animation* and *FadeoutAnimation*.
* **I/O streams** - In order to keep our best scores in a file I had to use some kind of libraries that allow to save data into file. I decided to use *fstream* library, because it's simple to use.

<p align="center"><img src="/inages/structure.png" alt="Game structure"></p>


## External specification
The program was written to work on UNIX based systems, but it can be run on Windows too. I used *CMake* to make it multi platform. To run the project you have to open a terminal in the directory of the project and then type `cmake .`. After that you can either type `make` or open *Visual Studio* project. These steps aren't sufficient in order to run it, you have to also install *Allegro 5* library which you can get [here](https://github.com/liballeg/allegro5) or install using *NuGet* package manager. Once you've done it you should be able to run the program.

<p align="center"><img src="/images/build.png" alt="Build process"></p>

## Tests
I have played the game a lot of times but only once I achieved score greater than 700. It's really challenging to end the game with high score. Below I would like to include a few screenshots representing the look of the game.

<p align="center"><img src="/images/test1" alt="Game"></p>
<p align="center"><img src="/images/test2" alt="Highest scores"></p>
<p align="center"><img src="/images/test3" alt="Main menu"></p>


## Conclusions
The project took a lot of time to finish. During development I encountered a few problems but I have managed to solve them. The operators overloading turned out to be a pretty friendly thing and in the future I am going to use it a lot. The next time I will develop a game I will probably choose a different graphics library, because *Allegro 5* hasn't been written using OOP. However, I can truly say that I'm glad of the outcome, but next time I will better plan the structure at the beginning.



