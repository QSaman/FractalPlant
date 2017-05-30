# FractalPlant
Creating a beautiful fractal using [L-system](https://en.wikipedia.org/wiki/L-system). For rendering I've used [Qt](https://www.qt.io/) framework. You can see the beautiful result in the following image:
  
![Fractal Plant Image](docs/tree_fractal.png)
  
I've used the following recurisve rules:
```
S → X | λ
X → F[−X][X]F[−X]+FX
F → FF
```
`F` means "draw forward", `−` means "turn left 25 degree", and `+` means "turn right 25 degree". `X` does nothing for rednering. `[` means push the current position and angle into stack and `]` means to retreive the top value of stack (pop operation). It is interesting this simple recursive formula can draw a beautiful tree!
## Requirements

1. C++
2. Qt >= 4.0.0
3. qmake

## Bulding the project

You can use Qt creator IDE to make the entire project or use a terminal. In Fedora 25 You need to use the following commands:

```
$ mkdir build
$ cd build
$ qmake-qt5 ..
$ make
$ ./FractalPlantApp
```
