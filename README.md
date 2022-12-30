# Altra64

[![Build and release](https://github.com/ariahiro64/altra64/actions/workflows/build-release.yml/badge.svg)](https://github.com/ariahiro64/altra64/actions/workflows/build-release.yml)[![Build docker dev build image](https://github.com/ariahiro64/altra64/actions/workflows/docker-image.yml/badge.svg)](https://github.com/ariahiro64/altra64/actions/workflows/docker-image.yml)

Alternative Everdrive64 menu + ottelo Fork with Game ID Support (N64Digital)

`Altra64` is an open source menu for [Everdrive64](http://krikzz.com/) and ed64+ and is based on a fork of alt64 which was
originally written by saturnu, and released on the
[Everdrive64 forum](http://krikzz.com/forum/index.php?topic=816.0). ariahiro64 forked the Altra64 repo and add new features/bug fixes to it. Now I (ottelo) forked the this repo from ariahiro64 as well and added new things like the Game ID feature for N64Digital HDMI mod (source https://gitlab.com/pixelfx-public/n64-game-id).
![IMG_1239](https://user-images.githubusercontent.com/33122175/210060057-8a74d214-5ab9-48f9-95f8-f99e7f51f136.jpg)


## Setup

1, Format your SD card to fat32.

2, Extract ED64P.zip into the rout of your sd card.

3, Change ALT64.ini To your hearts content.

4, Add leagally obtained ROMs

5, Insert the SD card into the ED64plus and enjoy

## Controls

```
Key settings
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
L+R delete files
```

## Building

If you want to build the menu, you need an n64 toolchain. This is terrible to build, moparisthebest ended up creating a Dockerfile in the docker folder, instructions included in it.

Or if you him and I, you can use the one I built and pushed to ghcr.io, which can be found [here](https://github.com/ariahiro64/altra64/pkgs/container/altra64)

Furthermore adrianopteodoro Automated the build proccess. Builds can be found [here](https://github.com/ariahiro64/altra64/actions)

### Build `Altra64`

To build the R.O.M.

from the projects root directory, with docker installed

```
docker run --rm -v "$(pwd):/build" ghcr.io/ariahiro64/altra64:master make
```

If it all worked, you will find `OS64P.v64` in the `bin` directory.

### Clean `Altra64`

Finally, we can clean the build objects from the project

from the projects root directory

```
docker run --rm -v "$(pwd):/build" ghcr.io/ariahiro64/altra64:master make clean
```

### Big thanks to the countless people who make altra64 possible!!! Enjoy!
