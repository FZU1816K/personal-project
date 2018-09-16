#pragma once

__declspec(dllexport) void fwrite(std::string finname, std::string foutname); //写入reault.txt
__declspec(dllexport) void CS(std::string finname);  //计算单词频数并排序
__declspec(dllexport) void show(std::string finname);  //显示单词数

