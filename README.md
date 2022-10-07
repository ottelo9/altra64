# Altra64

[![Build and release](https://github.com/ariahiro64/altra64/actions/workflows/build-release.yml/badge.svg)](https://github.com/ariahiro64/altra64/actions/workflows/build-release.yml)[![Build docker dev build image](https://github.com/ariahiro64/altra64/actions/workflows/docker-image.yml/badge.svg)](https://github.com/ariahiro64/altra64/actions/workflows/docker-image.yml)

Alternative Everdrive64 menu

`Altra64` is an open source menu for [Everdrive64](http://krikzz.com/) and ed64+ and is based on a fork of alt64 which was
originally written by saturnu, and released on the
[Everdrive64 forum](http://krikzz.com/forum/index.php?topic=816.0).
## Setup

```Format your SD card to fat32.
Extract ED64P.zip into the rout of your sd card.
Change ALT64.ini To your hearts content.
Add leagally obtained ROMs```

## Controls

```Key settings;
L brings up the mempak menu
      B abort
      A backup
      R format
      Z view controller pak
Z about screen
A start rom/directory/mempak
B back/cancel
START start last rom
C-left rom info / mempak content view
C-right rom config  screen
C-up view full filename
C-down Toplist 15
L+R delete files```

## Building

If you want to build the menu, you need an n64 toolchain. This is terrible to build, moparisthebest ended up creating a Dockerfile in the docker folder, instructions included in it.

Or if you trust him, you can use the one he built and pushed to docker hub, [moparisthebest/altra64-dev](https://hub.docker.com/r/moparisthebest/altra64-dev)

Furthermore adrianopteodoro made an updated docker. which can be found here [ghcr.io/adrianopteodoro/altra64:docker](https://github.com/adrianopteodoro/altra64/pkgs/container/altra64)

### Build `Altra64`

To build the R.O.M.

from the projects root directory, with docker installed

``$ docker run --rm -v "$(pwd):/build" moparisthebest/altra64-dev make``

or

``$ docker run --rm -v "$(pwd):/build" ghcr.io/adrianopteodoro/altra64:docker make``

If it all worked, you will find `OS64P.v64` in the `bin` directory.

### Clean `Altra64`

Finally, we can clean the build objects from the project

from the projects root directory

``$ docker run --rm -v "$(pwd):/build" moparisthebest/altra64-dev make clean``

or

``$ docker run --rm -v "$(pwd):/build" ghcr.io/adrianopteodoro/altra64:docker make clean``

### Big thanks to the countless people who make altra64 possible!!! Enjoy!
