int getc(FILE *stream);//read the next character from stream and return it as an unsigned char cast to a int ,or EOF on end of file or error.
用法介绍：
在C语言中，用函数getc从文件读取字符。
用 法: int getc(FILE *stream);
从文件指针stream指向的文件流中读取一个字符，并把它作为函数值返回给整型变量ch，并把位置标识符往前移动。
如果读取失败或者到了文件结束标志返回EOF(-1)