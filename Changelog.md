# Changelog


## 2.1.1 (2023-12-18)
### Bugfixes
- Fixed song actions (ui) being printed twice

## 2.1.0 (2023-12-18)
### Feature
- Read folders
    - Play all songs within a folder `./minidisco (-f or --folder) [path]`
        - This feature does **not** works recursively

## Minor Fixes 
- Functions which makes use of dynamic memory allocation now check for errors on allocating memory

## 2.0.0 (2023-12-06)
### Feature
- Playlists
    - Create Playlists: `./minidisco50 (-a or --add) [songs] [playlist.m3u]`
    - Read Playlists: `./minidisco50 (-r or --read-playlist) [playlist.m3u]`

## 1.1.0 (2023-11-29)
### Feature
- Main playback actions
    - Pause  
    - Loop   
    - Restart
- Playback actions indicators: bc91229 
    
## 1.0.0 (2023-11-25)
### Feature
- Play song by giving its path to the program
    - `minidisco50 [Path]`
