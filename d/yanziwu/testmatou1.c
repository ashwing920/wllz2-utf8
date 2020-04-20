                                  inherit ROOM;
#include <ansi.h>  

mapping *sign=({
        ([ 
                "name":"琴韵小筑",
                "id":"mr",
                "file":__DIR__"duchuan",
                "value":500
        ]),
        ([
                "name":"燕子坞",
                "id":"yanziwu",
                "file" :__DIR__"zhou",
                "value":1000
        ]),
});
string look_sign();

int do_go(string);

void create()
{
        set("short", "码头");
        set("long",@LONG
这里是慕容家的家仆和丫鬟出入太湖的水上码头，只见人们来来往往
，一个个风尘仆仆，码头边的老船夫见到你走过来，马上笑呵呵的迎了上
去。价格表(sign)。
LONG 
);
        set("outdoors","yanziwu");
        set("exits",([
                "north" : __DIR__"shiqiao",
        ]));
        set("item_desc", ([
                "sign" : (: look_sign :)
        ]));
        setup();
}
void init()
{
        add_action("do_go", "qu");
}
string look_sign()
{
        object ob = this_player();
        string str="过湖乘船命令为qu mr ／ qu yanziwu\n";
        int i=sizeof(sign);

        if (ob->query("family/family_name") != "慕容世家") i--;
        while (i--) {
                str += sign[i]["name"];
                str += "(" + sign[i]["id"] + ") ";
                str += MONEY_D->price_str(sign[i]["value"]) + "\n";
        }

        return str;
}

void do_move(object ob, int i)
{
        ob->move(sign[i]["file"]);
}

int do_go(string arg)
{
        object ob=this_player();
        int i=sizeof(sign);

        if (!arg) return 0;
        if (ob->is_busy() || ob->is_fighting())
                return notify_fail("你正忙着呢！\n");
        if (ob->query("family/family_name") != "慕容世家") i--;
        while(i--) {
        if (arg == sign[i]["id"]) {
                if(ob->query("family/family_name") != "慕容世家"){
        switch (MONEY_D->player_pay(ob, sign[i]["value"])) {
                case 0:
                        return notify_fail("穷光蛋，一边呆着去！\n");
                case 2:
                        return notify_fail("有零钱吗？\n");
        }
        
        message_vision("$N在口袋里翻来覆去地找船钱。\n", ob);
        ob->start_busy(3);
        message_vision("\n$N把钱交给船家，船家领$N上了一条小舟。\n\n",ob);
        }
          else
                {
                message_vision("\n船家对$N说道：原来是慕容家的人，快请上船。\n",ob);
                message_vision("$N走上了小船。\n",ob);
        }
                call_out("do_move", 3, ob, i);
                return 1;
                }
        }
        return notify_fail("你要去哪里？\n");
}
