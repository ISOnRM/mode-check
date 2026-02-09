### Installation:
```bash
git clone https://github.com/ISOnRM/mode-check.git
cd mode-check
make
make install-user
```

### Usage:
```bash
mode-check -h

mode-check --help

mode-check \<filename\>
```
### Output:
```
$ umask
0077
$ touch test_me_i_am_rwxr-xr--
$ mode-check test_me_i_am_rwxr-xr--
(/home/mark/Polygon/test_me_i_am_rwxr-xr--)'s mode: 0600/rw-------
$ chmod -v 754 test_me_i_am_rwxr-xr-- 
mode of 'test_me_i_am_rwxr-xr--' changed from 0600 (rw-------) to 0754 (rwxr-xr--)
$ mode-check test_me_i_am_rwxr-xr-- 
(/home/mark/Polygon/test_me_i_am_rwxr-xr--)'s mode: 0754/rwxr-xr--
```