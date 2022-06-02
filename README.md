# Run-Length Encoding

Codificação run-length (ou RLE) é uma forma simples de compressão sem perda de dados onde sequências longas de valores repetidos são armazenadas como um único valor e sua contagem no lugar de sua sequência original.

Por exemplo, para um arquivo .txt com os seguintes caracteres salvos:
~~~
aaaaaaaa bbbbcc dddeeeeeeeeeeeee
~~~
Após a compactação se tornaria:
~~~
aaa5 bbb3cc dddeee10
~~~

O modo de compressão que utilizamos no código é útil para compactar arquivos onde os bytes se repetem em sequência. Por exemplo, um arquivo .txt com muitos caracteres repetidos ou um arquivo .pgm com muitos pixels repetidos.

## Como usar
Copie o codigo e abra no VS Code. Execute a tarrefa de build (Ctrl+Shift+B) para copilar os arquivos .cpp. Ou compile manuamente abrindo a pasta com os arquivos no seu terminal e executando o comando: 
~~~shell
/run-length-encoding$ g++ ./src/rle.cpp ./src/encoding.cpp ./src/decoding.cpp -O2 std=c++17 -o rle.out
~~~
O programa principal, rle.out, roda em dois modos de operação: compactação e descompactação.
- Para compactar um arquivo qualquer, passe os parametros:
~~~shell
$ ./rle -c <nome-do-arquivo-de-entrada> <nome-do-arquivo-de-saida>
~~~
- Para descompactar, passe os parametros:
~~~shell
$ ./rle -x <nome-do-arquivo-de-entrada> <nome-do-arquivo-de-saida>
~~~
