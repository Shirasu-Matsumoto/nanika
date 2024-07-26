/**
 * @file RecycleBinGenerator.cpp
 * @author matsumoto-
 * @attention フォルダやファイルの置き換えをしてしまう可能性がございますのでご注意ください。
 * @brief ごみ箱ジェネレーター
 * Windows 11 Pro / gcc 13.2.0 によってコンパイルしました。-> RecycleBinGenerator.exe
 */

// 必要なヘッダファイルのインクルードをします。
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <fileapi.h>

/** 
 * @fn
 * @brief ごみ箱フォルダを作成します。
 * @param sernum 連番
 * @param dir 生成するディレクトリパス
 * @return 戻り値はありません。
 */
void mkrb(int sernum, std::string dir)
{
    // ファイル名、フォルダ名を登録します。
    std::string outfolderstr = dir + "\\" + "gomi" + std::to_string(sernum);
    std::string outfilestr = outfolderstr + "\\desktop.ini";
    // フォルダを作成します。
    std::filesystem::path outfolder = outfolderstr;
    std::filesystem::create_directory(outfolder);
    // ファイルを作成、書き込みします。
    std::ofstream outfile(outfilestr);
    outfile << "[.ShellClassInfo]\nCLSID={645FF040-5081-101B-9F08-00AA002F954E}\nLocalizedResourceName=@%SystemRoot%\\system32\\shell32.dll,-8964";
    outfile.close();
    // ファイルにシステム、隠しファイル属性を、フォルダにシステムファイル属性を付与します。
    SetFileAttributesA(outfilestr.c_str(), FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_SYSTEM);
    SetFileAttributesA(outfolderstr.c_str(), FILE_ATTRIBUTE_SYSTEM);
}

/**
 * @fn
 * @brief メインのプロセスです。
 * @param dirpath 生成するディレクトリのパスです。
 * @param num 開始値です。For文の引数でも利用します。
 * @param end 終了値です。
 * @return 正常終了した場合、0を返します。
 */
int main(int argc, char** argv)
{
    // 初期化をします。
    int num;
    int end;
    std::string dirpath;
    if (argc > 3)
    {
        // 引数を代入します。
        dirpath = argv[1];
        num = atoi(argv[2]);
        end = atoi(argv[3]);
    }
    else
    {
        // 生成するパスと開始値と終了値の入力を求めます
        std::cout << "生成するパス >> ";
        std::cin >> dirpath;
        std::cout << "開始値 >> ";
        std::cin >> num;
        std::cout << "終了値 >> ";
        std::cin >> end;
    }
    // 間のディレクトリが存在しない場合、作成します。
    if (!std::filesystem::exists(dirpath))
    {
        std::filesystem::create_directories(dirpath);
    }
    // 生成を開始します。
    for(num; num < end + 1; num++)
    {
        mkrb(num, dirpath);
    }
    return 0;
}