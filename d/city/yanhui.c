// 芙蓉宴会厅.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

#include <ansi.h>

inherit ROOM;

varargs static void
create_food(string nmstr, string* idlist, string longstr)
{
        object obj;

        obj = new("/clone/food/food");
        obj->set_name(nmstr, idlist);
        if (longstr)
                  obj->set("long", longstr);
        else
                  obj->set("long", GRN+"一盘热气腾腾, 香喷喷的"+nmstr+"。\n"+NOR);
        obj->move(this_object());
}

varargs static void
create_water(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new("/clone/food/water");
        obj->set_name(cup, idlist);
        if (longstr)
                  obj->set("long", longstr);
        else
                  obj->set("long", YEL+"一瓶可口的" + nmstr + "。\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

varargs static void
create_wine(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new("/clone/food/wine");
        obj->set_name(cup, idlist);
        if (longstr)
                  obj->set("long", longstr);
        else
                  obj->set("long", RED+"一杯醇正的" + nmstr + "。\n" + NOR);
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

void create()
{
        set("short", HIW"宴会厅"NOR);
        set("long", @LONG
这里是巫师用来招待上宾的宴会厅，每当喜庆节日，巫师们就会在这
里设下鸿门宴，招待上宾以及天下群雄。只见宴会厅上气势宏伟，金壁辉
煌。大厅四壁柱子上盘绕的金龙，散发着耀眼的金光。你脚踩着红色的地
毯，直入眼帘的，就是大厅中间的那张圆形的大理石桌了。
LONG );
        set("exits", ([
                "down" : __DIR__"zxlpath",
        ]));
        set("no_sleep_room",1);
        setup();
        set("no_user", 1);
}
void init()
{
        object me = this_player();

        if(wizardp(me)){
                add_action("do_order", "order");
        }
}
int do_order(string arg)
{
        object me, env;
        object* oblist;
        string mesg;
        int idx;

        me = this_player();
        env = this_object();
        mesg = query("order_owner");
        if(mesg && (arg == "end") && (mesg == me->query("id"))) {
                mesg = "宴会大厅的宴会结束了！！！\n";
                message("channel:chat", HIR+"【宴会大厅】"+mesg+NOR, users() );
                delete("order_owner");
                delete("order_type");
                oblist = all_inventory(env);
                for(idx=0; idx<sizeof(oblist); idx++) {
                        if (!objectp(oblist[idx]))
                                continue;
                        if (userp(oblist[idx]))
                                continue;
                        destruct(oblist[idx]);
                }
                return 1;
        }
        if (mesg)
                return notify_fail("这里已经被人包租了。\n");
        
        if(!wizardp(me))
                return notify_fail("只有巫师才可以在这里宴请宾客。\n");
        if(!arg)
                return notify_fail("你要摆什么宴？\n");
        if( arg != "all" && arg != "end")
                return notify_fail("宴会类型错误！\n");
        if(arg == "all") {
                mesg = me->name() + "现在在醉仙楼宴会大厅举行鸿门宴，宴请天下群雄！！！\n";
                message("channel:chat", HIC+"【宴会大厅】"+mesg+NOR, users() );
                message("channel:chat", HIR+"【宴会大厅】"+mesg+NOR, users() );
                message("channel:chat", HIG+"【宴会大厅】"+mesg+NOR, users() );
                set("order_owner", me->query("id"));
                set("order_type", arg);
                call_out("start_order",1);
        }
        return 1;
}
void start_order()
{
        object me, env;
        object* oblist;
        int idx;
        env = this_object();
        
        if(!query("order_owner") 
        ||!query("order_type")) return;
        
        oblist = all_inventory(env);
        for(idx=0; idx<sizeof(oblist); idx++) {
                if (!objectp(oblist[idx])) continue;
                if (userp(oblist[idx])) continue;
                destruct(oblist[idx]);
        }

        create_water(HIR"轩尼诗ＸＯ"NOR, ({ "xo" }), HIR"轩尼诗ＸＯ"NOR);
        create_water(HIW"金奖白兰地"NOR, ({ "drunk" }), HIW"金奖白兰地"NOR );
        create_water(HIB"百事"HIW"可乐"NOR, ({ "cola" }),HIB"百事"HIW"可乐"NOR);
        create_water(HIY"新奇士"NOR, ({ "sunkist" }),HIY"新奇士"NOR);
        create_water(HIR"可口可乐"NOR, ({ "cocacola" }),HIR"可口可乐"NOR);
        create_water(HIG"健力宝"NOR, ({ "jianli bao" }),HIG"健力宝"NOR);
        create_water(HIG"雪碧"NOR,({ "xue bi" }),HIG"雪碧"NOR);
        create_water(HIG"七喜"NOR,({ "7up" }),HIG"七喜"NOR);
        create_water(HIW"乐百氏鲜奶"NOR, ({ "le baishi" }),HIW"乐百氏鲜奶"NOR);
        create_water(HIG"嘉士伯啤酒"NOR, ({ "beer" }),HIG"嘉士伯啤酒"NOR);
        create_water(HIB"蓝带啤酒"NOR, ({ "beer" }),HIB"蓝带啤酒"NOR);
        create_water(HIG"喜力啤酒"NOR, ({ "beer" }),HIG"喜力啤酒"NOR);
        create_water(HIR"百威啤酒"NOR, ({ "beer" }),HIR"百威啤酒"NOR);
        create_water(HIY"太阳啤"NOR, ({ "beer" }),HIY"太阳啤"NOR);
        create_water(HIG"青岛啤酒"NOR, ({ "beer" }),HIG"青岛啤酒"NOR);
        create_water(HIG"海珠啤酒"NOR, ({ "beer" }),HIG"海珠啤酒"NOR);
        create_food(HIY"德州扒鸡"NOR, ({ "chicken" }) );
        create_food(HIC"香片蒸鱼"NOR, ({"fish"}) );
        create_food(YEL"咖喱饭"NOR, ({"rice"}) );
        create_food(RED"蚝油肉片"NOR, ({"fish meat","meat"}) );
        create_food(RED"羊肉串"NOR, ({ "mutton" }) );
        create_food(HIR"重庆火锅"NOR, ({ "chafing dish","dish" }) );
        create_food(YEL"粉蒸肉"NOR, ({ "meat" }) );
        create_food(HIW"四喜豆腐"NOR, ({ "bean curd" }) );
        create_food(YEL"叫花鸡"NOR, ({ "chicken" }) );
        create_food(HIG"碧螺春卷"NOR, ({ "spring","roll" }) );
        create_food(HIC"香片蒸鱼"NOR, ({"fish"}) );
        create_food(RED"羊肉串"NOR, ({ "mutton" }) );
        create_food(HIY"花枝饭卷"NOR, ({"rice"}) );
        create_food(HIR"鱼香肉丝"NOR, ({"fish meat","meat"}) );
        create_food(RED"麻辣火锅"NOR, ({ "chrafing dish","dish" }) );
        create_food(HIY"北京烤鸭"NOR, ({ "duck" }) );
        create_food(HIW"白斩鸡"NOR, ({ "chicken" }) );
        create_food(YEL"粉蒸肉"NOR, ({ "meat" }) );
        create_food(HIR"麻婆豆腐"NOR, ({ "bean curd" }) );
        create_food(RED"蚝油肉片"NOR, ({"fish meat","meat"}) );
        create_food(YEL"咖喱饭"NOR, ({"rice"}) );
        create_food(HIW"麻辣手撕鸡"NOR, ({"chicken"}) );
        create_food(HIR"干煸尤鱼"NOR, ({"fish"}) );
        create_food(HIY"东北水饺"NOR, ({ "dumpling" }) );
        remove_call_out("start_order");
        call_out("start_order",120);
}
int valid_leave(object me, string dir)
{
        object *inv;
        int i;
        inv = all_inventory(me);

        if (me->query("id") == query("order_owner"))
                return notify_fail(RED + "先用 order end 结束宴会后才能离开。\n" + NOR);

        for( i = 0; i < sizeof(inv); i ++ )
                if(inv[i]->query("is_order_food"))
                return notify_fail("你不能带走这里的食物。\n");
        return ::valid_leave(me, dir);
}

