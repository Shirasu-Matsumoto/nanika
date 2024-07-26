#include <iostream>
#include <cstring>
#include <ctime>

bool detect_c(char** __detecting_array_, int __detecting_array_size_, const char* __detecting_index_)
{
    for (int i = 0; i < __detecting_array_size_; ++i) {
        if (std::strcmp(__detecting_array_[i], __detecting_index_) == 0) {
            return true;
        }
    }
    return false;
}

void help(void)
{
    const char *HelpMenu = "\n\033[1m何を祐天寺 Help\033[0m\nUsage: 何を祐天寺 [-i | /i | -? | -h | /? | /h]\n       何を祐天寺 Value [Value]\n\n -i, /i: You input values on the prompt.\n -?, -h, /?, /h: Call this help.\n Value: You input values on the command line.\n";
    std::cout << HelpMenu;
}

int main(int argc, char** argv)
{
    int for_train_num;
    int type_train_num;

    if (argc > 1)
    {
        if (detect_c(argv, argc, "-?") || detect_c(argv, argc, "/?") || detect_c(argv, argc, "-h") || detect_c(argv, argc, "/h"))
        {
            help();
            return 0;
        }
        else if (detect_c(argv, argc, "-i") || detect_c(argv, argc, "/i"))
        {
            std::cout << " >> ";
            std::cin >> for_train_num;
            std::cout << " >> ";
            std::cin >> type_train_num;
        }
        else if (argc > 2)
        {
            for_train_num = std::atoi(argv[1]);
            type_train_num = std::atoi(argv[2]);
        }
        else
        {
            for_train_num = std::atoi(argv[1]);
            type_train_num = std::atoi(argv[1]);
        }
    }
    else
    {
        srand(time(nullptr));
        for_train_num = rand();
        type_train_num = rand();
    }

    const char* for_list[] = {"西武球場前", "飯能", "小手指", "所沢", "練馬", "小竹向原", "小川町", "森林公園", "川越市", "和光市", "池袋", "渋谷", "武蔵小杉", "日吉", "菊名", "横浜", "元町・中華街", "新横浜", "西谷", "海老名", "湘南台"};
    const char* type_list[] = {"\033[1;37;44m各駅停車", "\033[1;37;42m準急", "\033[1;37;41m急行", "\033[1;37;41m特急", "\033[1;37;41m通勤特急"};

    const char* for_train = for_list[for_train_num % 21];
    const char* type_train = type_list[type_train_num % 5];

    if (type_train != "\033[1;37;44m各駅停車")
    {
        std::cout << "\033[1m[通過] ";
    }

    std::string consoleout = std::string(type_train) + "\033[0m\033[1m " + std::string(for_train) + " 行き\033[0m";
    std::cout << consoleout << std::endl;

    return 0;
}