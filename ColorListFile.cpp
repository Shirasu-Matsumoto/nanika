#include <fstream>

int main(void)
{
    std::ofstream ofs("ColorList.txt");
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            for (int k = 0; k < 256; k++)
            {
                ofs << "\033[48;2;" << k << ";" << j << ";" << i << "m ";
            }
            ofs << "\033[0m\n";
        }
    }
    return 0;
}