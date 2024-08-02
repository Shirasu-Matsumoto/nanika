#include <iostream>
#include <cstring>
#include <ctime>
#include <random>

int sizeof_c(char **__sizeof_char_)
{
    int i = 0;
    while (__sizeof_char_[i] != __null)
    {
        i++;
    }
    return i;
}

bool detect_c(char **__detecting_array_, const char *__detecting_index_)
{
    int __detecting_array_size_ = sizeof_c(__detecting_array_);
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

int main(int argc, char **argv)
{
    int for_train_num;
    int type_train_num;
    int property_num;
    int property_list_num;
    int operation_num_num;
    int operation_alphabet_num;
    int last_train_num;

    if (argc > 1)
    {
        if (detect_c(argv, "-?") || detect_c(argv, "/?") || detect_c(argv, "-h") || detect_c(argv, "/h"))
        {
            help();
            return 0;
        }
        else if (detect_c(argv, "-i") || detect_c(argv, "/i"))
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
        std::random_device IntRand{};
        int for_train_num_rand = IntRand();
        int type_train_num_rand = IntRand();
        int property_list_num_rand = IntRand();
        int operation_alphabet_num_rand = IntRand();
        int operation_num_num_rand = IntRand();
        int last_train_num_rand = IntRand();
        for_train_num = std::abs(for_train_num_rand);
        type_train_num = std::abs(type_train_num_rand);
        property_list_num = std::abs(property_list_num_rand);
        operation_alphabet_num = std::abs(operation_alphabet_num_rand);
        operation_num_num = std::abs(operation_num_num_rand);
        last_train_num = std::abs(last_train_num_rand);
    }

    const char *operation_alphabet_list[] = {"S", "K", "M", "T", "G"};
    const char *for_list[] = {"西武秩父", "吾野", "西武球場前", "飯能", "小手指", "保谷", "所沢", "石神井公園", "練馬", "小竹向原", "寄居", "みなみ寄居〈ホンダ寄居前〉", "小川町", "武蔵嵐山", "森林公園", "川越市", "上福岡", "朝霞台", "志木", "和光市", "池袋", "渋谷", "武蔵小杉", "日吉", "菊名", "横浜", "元町・中華街", "新横浜", "西谷", "海老名", "湘南台"};
    const char *type_list[] = {"\033[1;37;44m各駅停車", "\033[1;37;42m準急", "\033[1;37;41m急行", "\033[1;37;41m特急", "\033[1;37;41m通勤特急", "\033[1;7mS-TRAIN", "\033[1m回送", "\033[1m試運転", "\033[1m検測"};
    const char *property_list[] = {"\033[36m4, 5号車Q SEAT", "\033[33mフルカラー LED", "\033[36m車内防犯カメラ", "\033[31m前面黄帯", "\033[36mドア開閉ランプ有り", "\033[36m抗菌・抗ウイルス座席シートCLEANSE", "\033[36mローレル賞プレート", "\033[36mドアチャイム低音", "\033[31m東上線開業110周年記念ヘッドマーク", "\033[32m注意喚起ドアステッカー貼付方法変更", "\033[36m優先席増設", "\033[32mつり革広告", "\033[36mLCD更新", "\033[31mShibuya Hikarie号", "\033[31menjoy! WEST 東海道・山陽新幹線ラッピングトレイン", "\033[36m床部木目調", "\033[31mみなとみらい線開業20周年記念トレイン", "\033[31m1号車キユーピー", "\033[31mSDGsトレイン"};

    const char *operation_alphabet = operation_alphabet_list[operation_alphabet_num % 5];
    const int operation_num = operation_num_num % 99;
    const char *for_train = for_list[for_train_num % 31];
    const char *type_train = type_list[type_train_num % 9];
    std::string property_res_list;

    std::string last_train;
    if (last_train_num % 20 == 1)
    {
        last_train = " - 最終電車";
    }

    if (property_list_num % 5 != 0)
    {
        property_res_list = "\n";
    }

    for (int i = 0; i < property_list_num % 5; i++)
    {
        property_num = rand();
        const char *property = property_list[property_num % 19];
        property_res_list = property_res_list + " " + property;
    }
    
    switch (type_train_num % 9)
    {
        case 0:
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            std::cout << "\033[1m[通過] \033[0m";
            break;
        case 6:
        case 7:
        case 8:
            if (rand() % 2)
            {
                std::cout << "\033[1m[通過] \033[0m";
            }
            break;
        default:
            break;
    }

    std::cout << "\033[1m" << operation_alphabet << operation_num << " " << type_train << "\033[0m\033[1m " << for_train << " 行き\033[0m" << last_train << property_res_list << " \033[0m\n";

    return 0;
}