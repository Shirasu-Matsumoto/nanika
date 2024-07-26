import random

type_list = ["\033[1;37;44m各駅停車", "\033[1;37;42m準急", "\033[1;37;41m急行", "\033[1;37;41m特急", "\033[1;37;41m通勤特急"]
for_list = ["西武球場前", "飯能", "小手指", "所沢", "練馬", "小竹向原", "小川町", "森林公園", "川越市", "和光市", "池袋", "渋谷", "武蔵小杉", "日吉", "菊名", "横浜", "元町・中華街", "新横浜", "西谷", "海老名", "湘南台"]

type_num = random.randint(1, len(type_list) - 1)
for_num = random.randint(1, len(for_list) - 1)

type_res = type_list[type_num]
for_res = for_list[for_num]

if type_res == "\033[1;37;44m各駅停車" :
    passing = ""
else :
    passing = "\033[1m[通過] "

res = passing + type_res + "\033[0m " + "\033[1m" + for_res + " 行き" + "\033[0m"

print(res)