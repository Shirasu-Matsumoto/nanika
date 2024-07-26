const type_list = ["\x1b[1;37;44m各駅停車", "\x1b[1;37;42m準急", "\x1b[1;37;41m急行", "\x1b[1;37;41m特急", "\x1b[1;37;41m通勤特急"];
const for_list = ["西武球場前", "飯能", "小手指", "所沢", "練馬", "小竹向原", "小川町", "森林公園", "川越市", "和光市", "池袋", "渋谷", "武蔵小杉", "日吉", "菊名", "横浜", "元町・中華街", "新横浜", "西谷", "海老名", "湘南台"];
var type_num = Math.floor(Math.random() * type_list.length);
var for_num = Math.floor(Math.random() * for_list.length);
var type_res = type_list[type_num];
var for_res = for_list[for_num];
var passing = "";
if (type_num != 0){passing = "\x1b[1m[通過] "}
var res = passing + type_res + "\x1b[0m \x1b[1m" + for_res + " 行き";
console.log(res);