# spim-for-kuis
Fork of [SPIM](http://spimsimulator.sourceforge.net) for KUIS.

## Build & Run
```shell
cd ./spim/
make
make install
./build/bin/spim
```

## Additional options
### Show executed instructions
You can see the executed instructions with `-show_instructions` option.

Example:
```
$ ./build/bin/spim -show_instructions -file ../helloworld.s
Loaded: ./build/share/spim/exceptions.s
[0x00400000]    0x8fa40000  lw $4, 0($29)                   ; 183: lw $a0 0($sp)                # argc
[0x00400004]    0x27a50004  addiu $5, $29, 4                ; 184: addiu $a1 $sp 4              # argv
[0x00400008]    0x24a60004  addiu $6, $5, 4                 ; 185: addiu $a2 $a1 4              # envp
[0x0040000c]    0x00041080  sll $2, $4, 2                   ; 186: sll $v0 $a0 2
[0x00400010]    0x00c23021  addu $6, $6, $2                 ; 187: addu $a2 $a2 $v0
[0x00400014]    0x0c100009  jal 0x00400024 [main]           ; 188: jal main
[0x00400024]    0x34020004  ori $2, $0, 4                   ; 40: li $v0, 4       # syscall 4 (print_str)
[0x00400028]    0x3c041001  lui $4, 4097 [msg]              ; 41: la $a0, msg     # argument: string
[0x0040002c]    0x0000000c  syscall                         ; 42: syscall         # print the string
Hello World
[0x00400030]    0x8f898000  lw $9, -32768($28)              ; 43: lw $t1, foobar
[0x00400034]    0x03e00008  jr $31                          ; 45: jr $ra          # retrun to caller
[0x00400018]    0x00000000  nop                             ; 189: nop
[0x0040001c]    0x3402000a  ori $2, $0, 10                  ; 191: li $v0 10
[0x00400020]    0x0000000c  syscall                         ; 192: syscall                      # syscall 10 (exit)
```

### Show number of executed instructions
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
