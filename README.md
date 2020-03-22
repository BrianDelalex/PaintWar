# PROJECT

PaintWar is A Epitech JAM project.

The purpose of this project is to create a video game. (explain later)

## INSTALL

There is no toolchain for cross-compiling. The project is using your host compiler, libraries and tools.

Dependencies list:
  * `g++` [dowload](https://ftp.gnu.org/gnu/gcc)
  * `make` [download](https://ftp.gnu.org/gnu/make)
  * `sfml` [clone](https://github.com/SFML/SFML)

## BUILD

There is 2 parts: the server & the client.

`make TARGET=client` will build the client.

`make TARGET=server` will build the server.

## RUN

You must at least run the server and configure it. 

`./PaintWar-server.bin $PORT`

Where $PORT is the port which will be open for communication. (Defaulting to *53000* if empty).

Then run where you want some client and configure also the networking.

`./PaintWar-client.bin $USERNAME $SERVER-IP $PORT`

Where arguments:
  * $USERNAME:  is the username that you want to have.
  * $SERVER-IP: is the host target IP.
  * $PORT:      is the host target port allocated for the server (Defaulting to *53000* if empty).

(A runtime description will be provide here)

## EPILOGUE

The project has been built/minded/designed in 48H and with 5 collaborators.
