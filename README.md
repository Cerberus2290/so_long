<h1 align="center">✋ BEWARE ✋</h1>

## If you are a 42 Student, do not copy/paste this project, it will be considered cheating and you will be grated -42.

# 42 Wolfsburg Cursus 
## So Long
## And thanks for all the fish!

# Summary

## This project is a very small 2D game. <br>Its purpose is to make you work with textures, sprites, <br>and some other very basic gameplay elements.

# Contents

1. [Introduction](#intro)
2. [Objectives](#objectives)
3. [Mandatory Part](#manda)
4. [Bonus Part](#bonus)
5. [Example](#example)

# <a name="intro">Introduction</a>

| Introduction | ![Logo_Monolith_small](https://user-images.githubusercontent.com/120580537/209333599-dc44418d-8ee7-42b6-8a4a-7ff328778d87.png) |
| ----- | ----- |
| Being a developer is a great thing for creating your own game.<br>But a good game needs some good assets. In order to create 2D games, you will have <br>to search for tiles, tilesets, sprites, and sprite sheets.<br>Fortunately, some talented artists are willing to share their works on platforms like: <br>[itch.io](https://itch.io/game-assets/free/tag-sprites)<br>In any case, try to respect other people’s work. |

<p align="right">
 <a href="https://github.com/Cerberus2290/so_long#-beware-">back to top</a>
</p>

# <a name="objectives">Objectives</a>

| Objectives | ![Logo_Monolith_small](https://user-images.githubusercontent.com/120580537/209333599-dc44418d-8ee7-42b6-8a4a-7ff328778d87.png) |
| ----- | ----- |
| It’s time for you to create a basic computer graphics project! |
| **so long** will help you improve your skills in the following areas: window management,<br>event handling, colors, textures, and so forth. |
| You are going to use the school graphical library: **the MiniLibX!**<br>This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events. |
| The other goals are similar to every other goal for this first year: being rigorous, level<br>up in **C** programming, use basic algorithms, do some information research, and so forth. |

<p align="right">
 <a href="https://github.com/Cerberus2290/so_long#-beware-">back to top</a>
</p>

# <a name="manda">Mandatory Part</a>

## III.1 - The "so_long" program

| Mandatory part | ![Logo_Monolith_small](https://user-images.githubusercontent.com/120580537/209333599-dc44418d-8ee7-42b6-8a4a-7ff328778d87.png) |
| ----- | ----- |
| **Program name** | so_long |
| **Turn in files** | Makefile, *.h, *.c, maps, textures |
| **Makefile** | NAME, all, clean, fclean, re |
| **Arguments** | A map in format *.ber |
| **External functs.** | * open, close, read, write, malloc, free, perror, strerror, exit <br> * All functions of the math library (-lm compiler option, man man 3 math) <br> * All functions of the MiniLibX <br> * ft_printf and any equivalent **YOU** coded |
| **Libft authorized** | Yes |
| Description | You must create a basic 2D game in which a dolphin escapes Earth after eating some fish. <br> Instead of a dolphin, fish, and the Earth, you can use any character, any collectible and any place you want. |

Your project must comply with the following rules:

* You **must** use the *MiniLibX*. Either the version available on the school machines, or installing it using its sources.
* You have to turn in a *Makefile* which will compile your source files. It must not relink.
* Your program has to take as parameter a map description file ending with the **.ber** extension.

## III.2 - Game

* The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
* The **W**, **A**, **S**, and **D** keys must be used to move the main character.
* The player should be able to move in these **4 directions**: up, down, left, right.
* The player should *not* be able to move into walls.
* At every move, the current **number of movements** must be displayed in the shell.
* You have to use a **2D view** (top-down or profile).
* The game doesn’t have to be real time.
* You can create the world you want!

## :information_source: <br> If you prefer, you can use ZQSD or the arrow keys on your keyboard to move your main character.<br> :information_source:
