# R4nd0m6uy's Roguelike
A rogue like platformer totally modable using lua scripting.

# Why this project
I'm developping this little game to challenge my programming. This is why I'm
not using a physic engine.

## Goal
* Draw objects on the screen from a world coordinate
* Collision detection
* Define the world using lua
  * Races (base stats)
  * Classes (stats boost, XP)
  * Melee effects (swors, hammer, ...)
  * Throwing effects (arrows, bullets, ...)
  * Magical effects (spells, potions, ...)
  * Bags (invetory size, weight)
  * ...
* Randomly generated levels
* Background music
* Sound effects
* Lighting

## Inspirations
* [Rogue legacy](http://www.cellardoorgames.com/roguelegacy/)
For the platform 2D action

* [Enter the dungeon](https://store.steampowered.com/app/311690/Enter_the_Gungeon/)
For using guns experience

* [Mintest](https://www.minetest.net/)
For the flexible lua modding

# Compiling

## Prerequists
**TODO**

* SDL2
* ...

## Cloning the repository
Clone the repository and initialize submodules

```sh
git clone <URL> rg-rogue
cd rg-rogue
git submodle update --init
```

## Linux
Using cmake:

```sh
mkdir build && cd build
cmake ..
make
```

## Other systems
**TODO** cmake ?

## Unit tests
To compile the unit tests, you will need [CppUTest](http://cpputest.github.io/)
library and pass the argument when invoking *cmake*

```sh
cmake .. -DCOMPILE_TESTS=ON
```

*CPPUTEST_HOME* variable can be used to locate CppUTest on your system, or will
be searched with pkg-config when not specified:

```sh
CPPUTESTHOME=/opt/cpputest cmake .. -DCOMPILE_TESTS=ON
```

## Data directory
**TODO**

# Conclusion
Let's see where it goes ...

