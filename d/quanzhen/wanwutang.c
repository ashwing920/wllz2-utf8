// wanwutang.c 万物堂
//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
        set("short", "万物堂");
        set("long", @LONG
这里是全真七子之五王处一的居所。房间不大，收拾的素雅整洁，墙
上挂着一萧一琴和一些字画，小靖上摆放着宣纸和徽墨狼毫，不知道主人
是要练字还是绘画。
LONG
);
        set("exits", ([
                "south" : __DIR__"huizhentang",
        ]));
        set("objects",([
                CLASS_D("quanzhen")+"/wangchuyi" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
