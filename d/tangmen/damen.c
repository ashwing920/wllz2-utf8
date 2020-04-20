      
inherit ROOM;
#include <ansi.h>

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
        set("short","唐家堡");
        set("long", @LONG
下了画舫，抬头一望，赫然见到“唐家堡”三个大字。你已经来到了
神秘而声名显赫声名显赫的唐门。高大的门让你不由得不仰视，大门口是
两个威武雄壮的铜狮，两旁是笔力遒劲的对联(distich)。
LONG
);
        set("no_steal",1);
        set("exits", ([
                "south" : __DIR__"zhaobi",
        ]));
        set("objects", ([
                CLASS_D("tangmen")+"/tang_buping" : 1,
                CLASS_D("tangmen")+"/master_tangmen" : 1,
                __DIR__"npc/dizi" : 2,
        ]));
        set("item_desc", ([
                "distich" : HIY "\n百                   一\n" 
                                "\n年                   腔\n"           
                                "\n世                   热\n"
                                "\n家                   血\n"
                                "\n传                   可\n"
                                "\n千                   快\n"
                                "\n古                   意\n"
                                "\n风                   恩\n"
                                "\n流                   仇\n" NOR,  
        ]));

        set("outdoors", "tangmen");
        setup();
    
}
void init()
{
        add_action("do_yell", "yell");
}

void check_trigger()
{
        object room;

        if(!query("exits/enter") ) {
        if( !(room = find_object(__DIR__"huafang")) )
                room = load_object(__DIR__"huafang");
        if( room = find_object(__DIR__"huafang") ) {
        if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"huafang");
                room->set("exits/out", __FILE__);
                message("vision", "一座画舫缓缓地驶了过来，唐菱将一块踏脚板搭上堤岸，以便乘客上下。\n", this_object() );
                message("vision", "唐菱将一块踏脚板搭上堤岸，形成一个向上的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board",10);
            }
            else
                message("vision", "只听得江面上隐隐传来：“别急嘛，这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "画舫上唐菱嘻嘻一笑：等着你呢，快上船吧。\n",this_object() );
}


void on_board()
{
        object room;

        if( !query("exits/enter") ) return;

        message("vision", "唐菱把踏脚板收了起来，竹篙一点，扁舟向湖心驶去。\n",this_object());

        if( room = find_object(__DIR__"huafang") ){
        room->delete("exits/out");
        message("vision", "唐菱把踏脚板收起来，说了一声“坐稳喽”，竹篙一点，扁舟向\n湖心驶去。\n", room );
        }
        delete("exits/enter");

        remove_call_out("arrive");
        call_out("arrive",10);
}

void arrive()
{
        object room;
        if( room = find_object(__DIR__"huafang") ){
        room->set("exits/out", __DIR__"fufeng");
        message("vision", "唐菱说道“到啦，上岸吧”，随即把一块踏脚板搭上堤岸。\n",room );
        }
        remove_call_out("close_passage");
        call_out("close_passage",10);
}

void close_passage()
{
        object room;
        if( room = find_object(__DIR__"huafang") ) {
        room->delete("exits/out");
        message("vision","唐菱收起跳板，把画舫驶向湖心。\n", room);
        room->delete("yell_trigger"); 
        }
}

int do_yell(string arg)
{
        if( !arg || arg=="" ) return 0;
        if( arg=="boat" ) arg = "船家";
        if((int)this_player()->query("neili") < 300 )
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",this_player());
        else if( (int)this_player()->query("neili") > 600 )
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传了出去。\n", this_player());
        else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",this_player());
        if( arg=="船家"){
        check_trigger();
        return 1;
}
        else
        message_vision("江面上远远传来一阵回声：“" + arg +"～～～”\n", this_player());
        return 1;
}

void reset()
{
        object room;

        ::reset();
        if( room = find_object(__DIR__"huafang") )
                room->delete("yell_trigger"); 
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "唐门") && dir == "south" &&
                objectp(present("tang buping", environment(me))))
           return notify_fail("唐不平喝道：你不是唐门弟子，不得入内。\n");
                
        return ::valid_leave(me, dir);
}

