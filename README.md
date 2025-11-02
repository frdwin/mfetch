# mfetch - Minimal Info Fetcher

`mfetch` is just another information fetcher, yet blazingly fast, made with love in C (C23).

It is very minimal and only works on *GNU/Linux*.

You don't get a ascii art by default, but you can tell `mfetch` to get one from a file (maximum of 8 lines).

We think this will give you more freedom to choose your preferred ascii art.

![mfetch screenshot](https://private-user-images.githubusercontent.com/84289565/508723231-8dd5a514-6f4f-4ae0-8cb5-e4f631800f44.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NjIwOTkyNDcsIm5iZiI6MTc2MjA5ODk0NywicGF0aCI6Ii84NDI4OTU2NS81MDg3MjMyMzEtOGRkNWE1MTQtNmY0Zi00YWUwLThjYjUtZTRmNjMxODAwZjQ0LnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNTExMDIlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjUxMTAyVDE1NTU0N1omWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWRmZjE4MTg2MjFkMTg2MDc2MTNkNjRhODViNDFjNTczODkzODk5N2IzMmQyM2I3ODBkNmQ3ZGNjMGQ3NTNkYTgmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.VvnBzmm9kQSBCqnvcTpO8HAaybN0jFLbSd0-pBmZ1Q4)
![mfetch screenshot](https://private-user-images.githubusercontent.com/84289565/508723209-5aa9887e-ac60-4c9e-983d-d972b479ca8d.png?jwt=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3NjIwOTkyNDcsIm5iZiI6MTc2MjA5ODk0NywicGF0aCI6Ii84NDI4OTU2NS81MDg3MjMyMDktNWFhOTg4N2UtYWM2MC00YzllLTk4M2QtZDk3MmI0NzljYThkLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFWQ09EWUxTQTUzUFFLNFpBJTJGMjAyNTExMDIlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjUxMTAyVDE1NTU0N1omWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWFiMjQyYjZkNWExODE1NmY3NGUxMDlhNzE3ZTBhM2ZhNThmNWJhMTcxNTJiYzU4NmIxNzhlOWMxNDJjMzk2MTEmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0In0.sbB0Nz8U10ZDA05I-JSaimHDDMlFBwXRLW_JEKlqm6k)

## Configuration

You can configure `mfetch` editing `src/config.h` file.

## Build
First, install libsqlite3-dev in your distro's package manager.
Then, clone this repo and install mfetch.

```bash
$ sudo apt install libsqlite3-dev
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

## Usage
```
$ mfetch -h
```
## Supported distros
<details>
<summary>Click here.</summary>

- Debian
- Ubuntu
- PopOS!
- Void
- RedHat
- Fedora
- AlmaLinux
</details>
