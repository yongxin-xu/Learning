lex myscanner.l
gcc myscanner.c lex.yy.c -o myscanner -ll
./myscanner < config.in