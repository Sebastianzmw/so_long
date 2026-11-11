# so_long

A small 2D top-down game in C using MiniLibX, 42's graphics library. Written at 42 Kuala Lumpur (2024).

Collect every item on the map, then reach the exit. Move with W/A/S/D or the arrow keys. The move count is printed after each move.

## Features
- Loads maps from `.ber` files (`1` wall, `0` floor, `P` player, `C` collectible, `E` exit)
- Checks that the map is rectangular, closed by walls and has exactly one player and one exit
- Uses a **flood fill** to confirm every collectible and the exit can be reached before the game starts
- Directional player sprites; ESC or closing the window quits the game and frees the map

## Build
MiniLibX isn't included in this repo. Put the macOS version of MiniLibX in `mlx/`, then:
```sh
make
./so_long maps/map1.ber
```
