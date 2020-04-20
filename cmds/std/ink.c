// ink.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string *txt;

        if( !arg ) 
                return notify_fail("指令格式：ink <签名>\n");
        if(arg=="none") {
                if (me->query("ink") && me->query("inkdone") && !wizardp(me)){
                        write("你已经有了自己的签名，签名不能再更改了。\n");
                        return 1;
                }
                me->delete("ink");
                write("签名档删除完毕。\n");
                return 1;
        }

        if(arg=="-s") {
        if(me->query("ink"))
                write(me->query("ink") + "\n");
                else
                write("你还没有自己的签名。\n");
                return 1;
        }
        else if (me->query("ink") && me->query("inkdone") && !wizardp(me)){
                write("你已经有了自己的签名，签名不能再更改了。\n");
                return 1;
        }

        txt = explode(arg, "\n");
        if( (!wizardp(me) && sizeof(txt) > 8) || sizeof(txt) > 20 )
                return notify_fail("请将您对自己的签名控制在八行以内。\n");

        arg = implode(txt, "\n") + "\n";

        me->set("ink",convert_color(arg)+NOR);
        write("Ok.\n");
        return 1;
}

int help()
{
   write(@TEXT
指令格式：ink <签名>
          ink -s  可以看自己的签名。

这个指令让你设定自己的签名，当你post文章时，会自动留下你的签名，
通常当你的签名超过一行时可以用 to ink 的方式来输入。你如果希望在
签名中使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：

$BLK$ - 黑色       $NOR$ - 恢复正常颜色
$RED$ - 红色       $HIR$ - 亮红色
$GRN$ - 绿色       $HIG$ - 亮绿色
$YEL$ - 土黄色     $HIY$ - 黄色
$BLU$ - 深蓝色     $HIB$ - 蓝色
$MAG$ - 浅紫色     $HIM$ - 粉红色
$CYN$ - 蓝绿色     $HIC$ - 天青色
$WHT$ - 浅灰色     $HIW$ - 白色
 
其中系统自动会在字串尾端加一个 $NOR$。

签名一旦设定，可以用 ink -s 看并作相应调整，
但是一旦 post 过就不能更改了，请注意。
TEXT
   );
   return 1;
}

