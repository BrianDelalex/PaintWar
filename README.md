# PROJECT

PaintWar is A Epitech JAM project.

The purpose of this project is to create a video game. (explain later)

## INSTALL

There is no toolchain for cross-compiling. The project is using your host compiler, libraries and tools.

Dependencies list:
  * `g++`  (dev under 9.2.1) [download](https://ftp.gnu.org/gnu/gcc)
  * `make` (dev under 4.3)   [download](https://ftp.gnu.org/gnu/make)
  * `sfml` [clone](https://github.com/SFML/SFML)

## BUILD

There is 2 parts: the server & the client.

`make TARGET=client` will build the client.

`make TARGET=server` will build the server.

## RUN

You must at least run the server and configure it. 

`./PaintWar-server.bin $PORT`

Where arguments:
  * $PORT: is the port which will be open for our server. (Defaulting to *53000* if empty).

Then run where you want some client and configure also the networking.

`./PaintWar-client.bin $USERNAME $SERVER-IP $PORT`

Where arguments:
  * $USERNAME:  is the username that you want to have.
  * $SERVER-IP: is the host target IP.
  * $PORT:      is the host target port allocated for the server.

Use arrows for move and space bar to fire (bullets are invisible).

## EPILOGUE

The project has been minded/designed/built in 48H and with 5 collaborators.

No follow up, without ambition, just fun.

Feel free to fork, use, improve.