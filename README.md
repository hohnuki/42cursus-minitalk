# minitalk

## 説明
このminitalkはUNIXのsignalを使用して、メッセージのやり取りを行うサーバーとクライアントを作成する課題です。

## 課題要件
gcc または Clang
GNU Make

## 実行方法
```
git clone https://github.com/hohnuki/minitalk
cd minitalk
make
```

server side
```
./server
waiting...
```

client side
```
./client [SERVER_PID] [ANY_MESSAGE]
```

