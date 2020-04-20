inherit ROOM;

void create()
{
        set("short","书房");
        set ("long",@LONG
这里是燕子坞的书房, 天下武功皆荟粹与此, 包罗万象, 屋子南边是
一把坐椅，四周全是一排排高大的书架。好好学习, 必可成为一代高手。
书房的东面是一条长廊，西面是大厅，南面是一间厢房。
LONG);
        set("exits",([
                "west" : __DIR__"dating",
                "north" : __DIR__"zishu",
                "east" : __DIR__"c15-0",
                "south" : __DIR__"xiangfang2",
        ]));
        set("objects", ([
                CLASS_D("murong")+"/deng" : 1,
        ]));
        setup();
}
void init()
{
        add_action("do_sit", "sit");
        add_action("do_zhuan", "zhuan");
}
int do_sit(string arg)
{
        object me;
        me=this_player();
                
        if (!arg) return 0;
        if (arg !="chair") return 0;
        if (arg=="chair"){
                write("你坐在椅子上，真是悠闲自得。你看到书架微微的摇晃了一下。\n");
                this_player()->set_temp("marks/坐1", 1);
                return 1;
        }
}
int do_zhuan(string arg)
{
        object me;
        me=this_player();
        
        if (me->query_temp("marks/坐1")){
                message("vision", me->name() + "试着转了一下书架，突然书架向后一转，你的面前出现了一个夹壁。\n",environment(me), ({me}) );
                message("vision", me->name() + "突然身影一闪，不见了。\n",environment(me), ({me}) );
                me->move(__DIR__"jiabi");
                message("vision", me->name() + "从外面钻了过来。\n",environment(me), ({me}) );
                this_player()->delete_temp("marks/坐1");
                return 1;
        }
}
