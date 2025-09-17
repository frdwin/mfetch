# mfetch - Minimal Info Fetcher

`mfetch` is just another information fetcher, made with love in C (C23).

It is very minimal and only works on *GNU/Linux*.

You don't get a ascii art by default, but you can tell `mfetch` to get one from a file (yet to be done).

We think this will give you more freedom to choose your preferred ascii art.

![mfetch screenshot](https://private-user-images.githubusercontent.com/84289565/490510780-701c9bcd-1912-43f5-b72c-4275fcaa89b2.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NTgxMDc4NDgsIm5iZiI6MTc1ODEwNzU0OCwicGF0aCI6Ii84NDI4OTU2NS80OTA1MTA3ODAtNzAxYzliY2QtMTkxMi00M2Y1LWI3MmMtNDI3NWZjYWE4OWIyLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNTA5MTclMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjUwOTE3VDExMTIyOFomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTY4NmQ1ODU5NzRiODhlZTMzZDhjNmVlMmFlNDc5OWQ0ODM5YTU4NzRiMzQ0YjA3MWIxMzMxNWM4NzkzMTVmYjgmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.fJ2jpvN4jK21BO8SqhMTUjJkxQ7kg3ALOxdBL1UU0W4)

## Configuration

You can configure `mfetch` editing `src/config.h` file.

## Build
```bash
$ git clone https://github.com/frdwin/mfetch && cd mfetch
$ make mfetch
$ sudo make install
$ cd .. && rm -rf mfetch
$ mfetch
```

## Uninstall

```bash
$ git clone https://github.com/frdwin/mfetch && cd mfetch
$ sudo make uninstall
$ cd .. && rm -rf mfetch
```

## What's next?

- [ ] Add other distros (only working on Void).
- [ ] Add printing an ascii art from a file.
