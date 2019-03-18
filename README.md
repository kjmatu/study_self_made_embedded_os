12ステップで作る 組み込みOS自作入門 勉強用リポジトリ
===============

# 概要

[これ](https://www.amazon.co.jp/12%E3%82%B9%E3%83%86%E3%83%83%E3%83%97%E3%81%A7%E4%BD%9C%E3%82%8B%E7%B5%84%E8%BE%BC%E3%81%BFOS%E8%87%AA%E4%BD%9C%E5%85%A5%E9%96%80-%E5%9D%82%E4%BA%95-%E5%BC%98%E4%BA%AE/dp/4877832394)と[ここ](http://kozos.jp/books/makeos/)を使って組込プログラムの勉強する


# 開発環境

+ ホストOS Windows10
+ ビルド環境1
  + クロスコンパイル用ゲストOS Windows Subsystem for Linux (Ubuntu)
  + gcc, binutilsのバージョンは書籍と同一 (gcc-3.4.6, binutils-2.19.1)

+ ビルド環境2
  + 仮想環境 Docker for Windows
  + クロスコンパイル用ゲストOS Ubuntu 18.04
    + gcc 7.3.0
    + binutils 2.30.0
  + [ビルド環境構築用Dockerfile](https://github.com/kjmatu/12step_self_embedded_os_dev_enviroment)

# ディップスイッチ設定

|    | 1  | 2   | 3   | 4   |
|----|----|-----|-----|-----|
|書込| ON | ON  | OFF | ON  |
|実行| ON | OFF | ON  | OFF |

# 注意点

+ WSLでやる場合は、毎回シリアルポートの権限を変える必要がある
``` bash
例
>> sudo chmod 666 /dev/ttyS6
```
+ ポート設定が正しいのに書き込めない場合はリセットすると書き込めるときもある

# メモ

## Chap2
 + ボーレート9600bpsとは、1秒間にON/OFF信号を9600回送っていること(1文字8bitとすると1200文字送れる)
 + レジスタとはCPUに組み込まれている特殊な記憶領域
 + CPUのビット数とは、CPU内部で扱うデータのビット幅のこと
    + 例 32bit CPUとはレジスタのサイズが32bitのこと C言語でいうとint型が32bitであることと同じ
 + データバスとは、数値を転送するためにCPUが持っている入出力ピン
 + アドレスバスとは、アドレスを指定するためにCPUが持っている入出力ピン。アドレスバスを使ってDRAMにアドレスを通知することでメモリの読み書きができる。
    + アドレスバスが32bitということはC言語ではポインタ変数のサイズは32bitであることを意味する
 + 多くの場合はレジスタのビット数がアドレスバスのビット数以上になっている( レジスタビット数 >= アドレスバスビット数 )
 + アドレスバスが32ビットだと0xFFFFFFFF(‭4294967295‬)byte (4GB)のメモリ空間にアクセス可能
