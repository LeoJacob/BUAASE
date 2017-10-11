# sudoku.exe 运行说明

## 生成终局

语法如下

```shell
sudoku.exe -c <数量>
```

其中 `<数量>` 是长度不超过 $7$ 个字符，且值为 $[1, 1000000]$ 内的整数。

生成的不重复终局存储至当前文件夹下的文件 `sudoku.txt` 中，保证

1. 每个终局的左上角数字为 $7$
2. 终局与终局之间空一行
3. 数独的相邻数之间有一个空格，行末没有空格

## 求解数独

语法如下

```shell
sudoku.exe -s <文件路径>
```

其中 `<文件路径>` 指向输入文件。输入文件的格式要求如下：

1. 终局与终局之间空一行
2. 数独的相邻数以空白字符分隔
3. 数独的每个数为 $[0,9]$ 之间的整数，其中 $0$ 表示该位置为空

求解结果存储至当前文件夹下的文件 `sudoku.txt` 中，有解时输出其中一个解，无解时输出 `No Solution!`，每个结果间有一个空行。