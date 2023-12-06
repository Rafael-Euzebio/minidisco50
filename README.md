# minidisco50
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


## Roadmap

- [x] Playback control (Play, Pause, Loop and Restart)
- [x] Read and write to playlists in `.m3u` files
- [ ] Song queue (Play all songs in a folder)
- [ ] Search for songs recursively with partial filename

