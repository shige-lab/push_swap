# push_swap
# for 42tokyo
42tokyoの課題で与えられた数値をソートするプログラムを作りました。

流れ
・n個の乱数(同数は無効)を引数で受ける。
・引数が有効な数字だけであるかを確認し、そうでなかった場合はプログラムを終了する。
・構造体でスタックaとbを持ち、ひとまずaに全ての乱数を挿入する。
・11個の専用の命令のみでスタックを操作(コマンドは最後に説明(英語))し、最短でもソートを試みる。
・専用の命令を実施するごとに命令を出力する。

使用可能関数
・write
・read
・malloc
・free
・exit

bashで実行可能
実行ファイル名 push_swap(makeで作成可能)
以下のコマンドで100個の乱数を引数に取ることが出来る。
ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG
以下のコマンドで命令の実行回数が確認できる。
ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG | wc -l
正確にソートできているかは以下のコマンドで確認できる(make checkerで実行ファイルcheckerを作成可能)。
ARG=$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $ARG ./checker $ARG

11個の専用の命令(課題文からの引用)
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.