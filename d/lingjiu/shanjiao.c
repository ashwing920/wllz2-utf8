// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "缥缈峰山脚");
	set("long",@LONG
这里是缥缈峰山脚, 抬头上望, 缥缈峰耸入云天, 峰顶白云缭绕, 宛
若仙境. 白云深处隐约可见琼楼玉宇, 那就是令江湖人物闻名丧胆的『灵
鹫宫』。听说宫中住着一些武艺高强的女侠, 而且只收女弟子为徒。
LONG
);
	set("outdoors", "lingjiu");
	set("exits", ([
		"westup" : __DIR__"ya",
		"southdown" : "/d/xingxiu/tianroad2",
	]));
	set("objects",([
		__DIR__"npc/jiuyi" : 1,
	]));
	setup();
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg) 
{
        int valid;
                
        if( !arg || (arg != "door" && arg != "gaochangmigong") )
                return 0;
        
        arg = "gaochangmigong";
        valid = FUBEN_D->valid_enter(this_player(), arg); 
        if( valid >=1 )
                FUBEN_D->enter_fuben(this_player(), arg);
        else {
                if( valid == 0 )
                        write("您实战经验不足，进副本恐有不测，还是先历练一下再来吧。\n");
                else if( valid == -1 )
                        write("您经验太高了，就不要进去欺负那些可怜的小怪物了吧。\n");
                else if( valid == -2 )
                        write("游戏中目前并没有开放该副本，请您核对后再试。\n");
                else if( valid == -3 )
                        write("该副本限制IP多重进入，您已经超过最高上限。\n");
                else if( valid == -4 )
                        write("该副本被巫师关闭，您暂时无法进入。\n");

        }        
        return 1;
}

