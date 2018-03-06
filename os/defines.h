#ifndef _DEFINES_H_INCLUDED_
#define _DEFINES_H_INCLUDED_

#define NULL ((void *) 0)  // NULLポインタの定義
#define SERIAL_DEFAULT_DEVICE 1  // 標準のシリアルデバイス

// intは16bitを想定 16bit CPU使用のため
// ビット幅固定の整数型
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;

typedef uint32 kz_thread_id_t;  // スレッドID
typedef int (*kz_func_t) (int argc, char *argv[]);  // スレッドID
typedef void (*kz_handler_t) (void);  // 割り込みハンドラの型

#endif
