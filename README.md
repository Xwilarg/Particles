## Particles
A small particule renderer made with the SFML

| Linux          | Windows     |
| -------------- | ------------ |
| [![Build Status](https://travis-ci.org/Xwilarg/Particles.svg?branch=master)](https://travis-ci.org/Xwilarg/Particles) | [![Build status](https://ci.appveyor.com/api/projects/status/jj47bntivyosii9n/branch/master?svg=true)](https://ci.appveyor.com/project/Xwilarg/particles/branch/master) |

## Controls

Left click: Add walls<br/>
Right click: Remove walls<br/>
Escape: Display debug infos

## Configuration file

Each elements of the configuration file must be separated by one empty space, empty lines and lines starting by '#' are ignored.<br/>
The file must be called config.txt and be placed near the executable.<br/>
The first line must contain the width and the height of the window.<br/>
Each other lines correspond to a particule spawner, for each of them you must provide the following arguments:<br/>
- X and Y of the spawner
- Color of the particles spawned
- Spawn rate in ms

An example of the file is available [here](https://github.com/Xwilarg/Particles/blob/master/Particles/config.txt).

## How to use from sources

### Linux
Download the SFML and run 'make'


### Windows (Visual Studio)
Download the SFML and link the libraries following the [SFML tutorial](https://www.sfml-dev.org/tutorials/2.5/start-vc.php) then open the solution and launch the project
