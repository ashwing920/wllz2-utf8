// Design By BMW add from 2000.4.3

#include <ansi.h>
#include <login.h>
inherit CHAT_ROOM;

void create()
{
        set("short",HIR"☆凝儿房☆"NOR);        
        set("long",@LONG 
这是一间非常华丽的睡房。在房的正中央是一张用$HIW$千年寒冰$NOR$做成的睡
床！睡床的四周都是用屏风围着，透过屏风望去，可以看见睡床透着寒气
床的左边有块非常漂亮的牌子，上面写着“$HIR$誓言$NOR$”(sign)。四周的墙上挂
着一些字画，其中有一副是逍遥亲手写的。字墨都还没干呢！(shi）逍遥
最喜欢在困的时候往床上一躺！可以增加功力和消除疲劳。床边还摆着一
个非常大的镜子(jingzi)。

LONG
);
        set("sleep_room",1);
        set("no_kill",1);
        set("no_steal",1);
        set("no_magic",1);
        
        set("item_desc",([
                "sign": HIW"
下雨的天空突然雷声轰隆隆有谁知道我心痛爱情有独钟偏偏它是$HIY$痴人
梦$NOR$$HIW$我实在不该对她心动爱上一个不该去爱的人我总是$HIG$加倍包容
牺牲$NOR$$HIW$明知不可能还勉强自己要去撑越撑心越闷越闷心越冷$HIC$你知道我心里只爱你一个人
$HIW$你的态度我不能平衡你给的爱太深我忍不住想问到底那里比不上他灰暗的
天空不见昨日灯朦胧你到底在想什么爱依稀结束怎么说你都不清楚活得好
像风中蜡烛你知道我心里只爱你一个人你的态度我不能平衡如果你的爱需
要两个人来分$HIR$我想我不愿意再等$NOR$
                
\n"NOR,

                
"shi":"$HIY$看你$HIY$惹的祸，$HIC$凝儿
$HIC$是帮凶。$NOR$\n",
                
"jingzi":"你一看镜子：原来$HIW$逍遥寻欢$NOR$正在看着你呢！轻声的到
：来我$HIY$家$NOR$想干什么坏事呢？
嘿嘿！该不是想$HIR$…………$NOR$。$HIW$逍遥寻欢$NOR$踢了一下你的$HIM$八月十五$NOR$。\n",
]));

        set("exits",([
                "out"    :__DIR__"workroom",
                "robert" :"/u/robert/workroom",
                "enter" :"/u/bmw/chatroom",

        ]));
                
        setup();
        }