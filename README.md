# spim-for-kuis
Fork of [SPIM](http://spimsimulator.sourceforge.net) for KUIS.

## Build & Run
```shell
cd ./spim/
make
make install
./build/bin/spim
```

## Additional Options
### show number of executed instructions
You can see the number of executed instructions with `-show_stats` option.

Example:
```
$ ./build/bin/spim -show_stats -file ../helloworld.s
Loaded: ./build/share/spim/exceptions.s
Hello World
# of executed instructions: 14
```

## License
MIT License. See [LICENSE](LICENSE) for more information.
