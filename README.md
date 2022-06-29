# **so_long | 42sp**
![Game sample](assets/exemple.gif)

## Introduction
This project is a very small 2D game. Its purpose is to make you work with textures, sprites, and some other very basic gameplay elements. 

In this project, the goal is for the player to collect all the collectibles on the map before going to an exit. However, the game must follow a set of rules which are described bellow.

## Rules
The executable `so_long`/`so_long_bonus` will receive a `.ber` filetype map as the only argument, otherwise, the game must exit with a `Error\n` message. Also, if any of the following checks fail, the game must end with an `Error\n` followed by a custom message:
- The map must be rectangular.
- There must be at least one collectable (`C`), one exit, and one player on the map.
- The map must be surrounded by walls (`1`'s).
- Only the following characters are valid: "`01CPE`" where `0` indicates the floor area, `1` walls, `C` collectables, `P` Player, and `E` an exit. (except if we add enemies as bonus, which we can use any caracter in order to represent it. Im using `S` to indicate slimes and `.` to indicate the score area).

## How it works
To handle the graphic part of the project, we are using a library called **[MinilibX](https://github.com/42Paris/minilibx-linux)** (A simple X-Window programming API, designed for students, suitable for X-beginners). Despite its leak issues and limitations, is pretty fun to work with.

Feel free to ask me how the code works. In summary, im using gnl and split to create a matrix that represents the map, some functions which scan the whole matrix and validates the map, and some hooks that MinilibX provide us in order to control game events.

## Installation
#### **Linux**
In order to play the game, we should have MinlibX and [LIbft](https://github.com/ichmi/libft). But you should not worry about it, just run `make` or `make bonus` to generate the game binary. However, you need to install the following packages to be able to display and manage windows using [X11](https://en.wikipedia.org/wiki/X_Window_System) (Debian-based distros):
```bash
apt-get install gcc clang make xorg libxext-dev libbsd-dev
```

Now you can build the game, just make it:
```bash
make
./so_long <map>  # ./so_long maps/42_exemple_1.ber
```

I suggest that you play it using the full featured game (+bonus):
```bash
make bonus
./so_long_bonus <map> # ./so_long_bonus maps/monsters.ber
```

#### **WSL (Windows Subsystem for Linux)**
To make it work in Windows, a third-party app is required to run Linux GUI apps inside a Windows operating system. Im currently using [VcXsrv](https://sourceforge.net/projects/vcxsrv/) Windows X Server for that purpose. Just be sure to check the _Disable access control_ option while installing and starting it. Please, dont forget to ensure VcXsrv has both firewall permissions (Private/Public), otherwise, you wont be able to display a Linux window using your WSL.

After that, just set up the `DISPLAY` environment variable in your WSL as follow:
```bash
# You can insert it into your dotfile (.zshrc/.bashrc, etc)
export DISPLAY=$(ip route | awk '/^default/{print $3}'):0.0

# You can run xeyes program to test it
xeyes
```

After that, you can install the required packages into your WSL and make it:
```bash
apt-get install gcc clang make xorg libxext-dev libbsd-dev

make bonus
./so_long_bonus <map> # ./so_long_bonus maps/monsters.ber
```

### Summary
This has been my favorite project so far, was pretty fun to create a basic computer graphics project. It helped me to improve window management, event handling, colors, textures, along with other skills.

Ooh, and I made all sprites avaiable in the game as well. ^-^

👨🏻‍🚀 "_thanks for all the fish!_" 🐟
