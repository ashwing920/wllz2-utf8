// util.c
#include <localtime.h>
#include <ansi.h>
object get_object(string name)
{
    object ob;
    if (ob = find_object(name))
        return ob;
    return load_object(name);
}

string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                           HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                           HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                           BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                           NOR, BOLD });
                           
        if( !str || !stringp(str) ) return 0;
        i = sizeof(color);
        while( i-- ) {
                str = replace_string(str, color[i], "");
        }
        return str;
}
varargs string appromix_time(int n, int flag)
{
        string s;
        string os;
        int odd;
        int bn;

        if( n <= 0 )
                return flag ? "马上就" : "马上";

        bn = 1;
        if( n < bn * 60 ) {
                // bn 单位是秒钟
                s = "秒钟";
                odd = 0;
        } else
        if( bn *= 60, n < bn * 60 ) {
                // bn 单位是分钟
                s = "分钟";
                os = "秒钟";
                odd = n % bn;
                n /= bn;
        } else
        if( bn *= 60, n < 24 * bn ) {
                // bn 单位是小时
                s = "小时";
                os = "分钟";
                odd = (n % bn) / 60;
                n /= bn;
        } else
        if( bn *= 24, n < 30 * bn ) {
                // bn 单位是天
                s = "天";
                os = "小时";
                odd = (n % bn) / (60 * 60);
                n /= bn;
        } else
        if( n < 365 * bn ) {
                // bn 单位是天
                s = "个月";
                os = "天";
                odd = (n % (30 * bn)) / bn;
                n /= 30 * bn;
        } else {
                // bn 单位是天
                s = "年";
                os = "个月";
                odd = (n % (365 * bn)) / (bn * 30);
                n /= 365 * bn;
        }

        s = chinese_number(n) + s;
        if( odd )
                s += "零" + chinese_number(odd) + os;

        if( flag ) s += "以后";
        return s;
}