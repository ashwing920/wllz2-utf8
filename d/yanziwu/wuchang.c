inherit ROOM;

int do_strike(string arg);

void create()
{
        set("short","练武场");
        set ("long",@LONG
这里是练武场，慕容家的弟子、家丁在这里练习武功，在练武场的一
角，有一个专门用来练武的木桩(zhuang)，许多弟子都围在这里练功。
LONG);
        set("exits",([
                "west" : __DIR__"yanziwu",
                "east" : __DIR__"jianfang",
        ]));
        set("item_desc", ([
                "zhuang" : "这是一个木桩，能够抵御各种攻击，许多弟子正在左右击打它。\n",
        ]));
        set("objects",([
                __DIR__"npc/guanjia" : 1,
                "/d/shaolin/npc/mu-ren": 5,
        ]));
        setup();
}
void init()
{
        add_action("do_strike", "strike");      
        add_action("do_strike","hit");
        add_action("do_strike","ji");
        add_action("do_strike","da");
}

int do_strike(string arg)
{
        object me;
        int jingcost, maxlevel, level;

        me = this_player();

        if ( !living(this_player()) || arg != "zhuang" ) return 0;
        if ( (level = me->query_skill("parry", 1)) < 30 )
                return notify_fail("凭你现在的招架功夫，无法打击木桩来增长。\n");

        maxlevel = 120;

        if (me->query("family/family_name")!="慕容世家") maxlevel = 50;
                if (level >= maxlevel)
                        return notify_fail("你对着木桩来回地打击，但是打击木桩已经无法使你的基本招架提高了。\n");
        if((level * level * level) / 10 > me->query("combat_exp"))
                        return notify_fail("你对着木桩来回地打击，但是由于你经验不足，已经无法领会到当中奥妙了。\n");
        
                jingcost = level / 4 + random(level / 4);
                if (me->query("jing") <= jingcost) {
                        write("你太累了，已经没有力气击打木桩了！\n");
                        return 1;
                }
                me->receive_damage("jing", jingcost);
                write("你对着木桩来回地打击，觉得对你的基本招架有所促进。\n");
                if (!random(5)) tell_room(this_object(),
                        me->name() + "正在来回地击打木桩。\n", ({ me }));
                        me->improve_skill("parry", me->query("int"));   
                return 1;
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "慕容世家") && dir == "east" &&
        objectp(present("guanjia", environment(me))))
        return notify_fail("管家喝道，那是本门重地，不得乱闯！\n");

        return ::valid_leave(me, dir);
}
