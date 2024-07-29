#include <iostream>

int main(void)
{
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            for (int k = 0; k < 256; k++)
            {
                std::cout << "\033[48;2;" << k << ";" << j << ";" << i << "m ";
            }
            std::cout << "\n";
        }
    }
    return 0;
}