#/bin/bash
clear
read -p "
var="name"
nano $var.asm.in
java cs241.binasm < $var.asm.in > $var.mips.out
xxd -c4 $var.mips.out
