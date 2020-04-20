//chufang.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
        set("short","厨房");
        set("long",@LONG
这是华山剑派的厨房，一位华山小师妹正在烧饭。整个房间弥漫着饭
菜香。你可以向小师妹要(serve) 些吃的喝的。墙上贴着一张启事(note)。
LONG
);
        set("exits",([
                "east" : __DIR__"garden",
        ]));
        set("item_desc",([
                "note" : "一粥一饭，当思来之不易。\n",
        ]));
        set("objects",([
                __DIR__"npc/girldizi" : 1,
        ]));
        set("ricewater", 5);
        setup();
}
int valid_leave(object me, string dir)
{
        if(( present("soup", me) || present("rice", me))
        && present("xiao shimei",environment(me)))
        return notify_fail("小师妹瞪了你一眼: 吃不了要兜着走啊? \n");
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
        object me;
        object food;
        object water;
        me=this_player();
 
        if( !present("xiao shimei",environment(me))) 
                return notify_fail("小师妹不在了，你叫了半天也没人理会。\n");
        if (me->query("family/family_name") != "华山剑派")
                return notify_fail("小师妹道：你不是华山剑派弟子，不能拿取食物。\n");
        if(present("rice",this_player()) ) 
                return notify_fail("小师妹道：吃完了再拿，别浪费食物。\n");
        if(present("rice",this_object()) ) 
                return notify_fail("小师妹道：吃完了再拿，别浪费食物。\n");
        if(query("waitting"))
                return notify_fail("小师妹说道：食物已经完了，等我再烧一些吧！\n");
        if (query("ricewater")>0)
        {
                message_vision("小师妹连声答应，给$N一碗黄米饭和一碗鲜菇汤。\n",me);
                food=new(__DIR__"obj/rice");
                water=new(__DIR__"obj/soup");
                food->move(me);
                water->move(me);
                add("ricewater",-1);
        }
        else {
                message_vision("小师妹对$N歉声道：嗨，吃的喝的都没了。\n",me);
                remove_call_out("do_reset");
                call_out("do_reset",300);
                set("waitting",1);
        }

        return 1; 
}
void do_reset()
{
        if(!this_object()) return;
        set("ricewater",5);
        set("waitting",0);
}
