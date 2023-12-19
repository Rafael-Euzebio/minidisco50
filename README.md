# minidisco50

#### Video Demo: https://youtu.be/SSHuR9TGqjU

#### Description:

My final project for CS50x in 2023, a terminal music player in C.

## Installation
1. Clone the repo  
`https://github.com/Rafael-Euzebio/minidisco50.git`

2. Enter into the directory  
`cd minidisco50`

3. Install  
`make install`  

*Note: If you don't want to install the program globally, run:*
```
make
cd bin
./minidisco50 [Path]
```

## Usage
`minidisco50 [Path]`  
Where `Path` is the exact path to your song file

### Playback Control
| Key| Description |
|--------- | --------- |
| `p`  | Pause playback |
| `l`  | Toggle loop|
| `r`  | Restart song|
| `n`  | Play next song from playlist|
| `q`  | Quit|

## Playlists
minidisco50 can handle playlists in .m3u files

A playlist can be created or updated with `./minidisco50 [-a or --add] [songs] [playlist.m3u]`  
It can be read with `./minidisco50 [-r or --read-playlist] [playlist.m3u]`

## Folders
minidisco50 can play all song files in a folder (as long as they are `.wav`, `.ogg` or `.flac` files)

`minidisco50 (-f or --folder) [path]`

## Roadmap

- [x] Playback control (Play, Pause, Loop and Restart)
- [x] Read and write to playlists in `.m3u` files
- [x] Song queue (Play all songs in a folder)
- [ ] ~~Search for songs recursively with partial filename~~
    - As of 2023-12-12 it was decided this feature will **not** be implemented

