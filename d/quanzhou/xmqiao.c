// xmqiao.c 新门吊桥
#include <localtime.h>
inherit ROOM;

int exit(int);

void create()
{
        set("short", "新门吊桥");
        set("long", @LONG
这是泉州西面的一座吊桥，从傍着晋河而建的城楼大门上以两个滑轮
维系。日出放下吊桥，日落绞起。西出城门便是乱石岗，经常有土匪出没
，没事还是别出城的好。南面有家瓷铺。
LONG
);
        set("outdoors", "quanzhou");
        setup();
}
void init()
{
        int t;          // time of the day in minutes
        mixed *local;

        local = localtime(time());
		write(sprintf("%4d年%2d月%2d日%2d时%2d分%2d秒\n",local[LT_YEAR],local[LT_MON]+1,local[LT_MDAY],local[LT_HOUR],local[LT_MIN]+1,local[LT_SEC]+1));
        t = local[2]*60 + local[1];

        set("exits", (: exit :));
}

int exit(int mode)
{
        int t, t1, t2, t3;              // time of the day in minutes
        mixed *local;
        object room;

        local = localtime(time());
        t = local[2]*60 + local[1];
        if ( !( room = find_object(__DIR__"luanshi")) )
                room = load_object(__DIR__"luanshi");
		write(sprintf("testtime:%d\n",t));
        set("exits/east", __DIR__"xinmen");
        set("exits/south", __DIR__"taoci");
        set("exits/north", __DIR__"datiepu");
        set("exits/west", __DIR__"luanshi");
        room->set("exits/east", __DIR__"xmqiao");

        if ( ( t >= 1260 && t < 1440 ) || ( t >= 0 && t < 300 ) ) {
                delete("exits/west");
                room->delete("exits/east");
        }
        if ( mode == 2 ) {
                message("vision","吊桥缓缓地绞了起来。\n",this_object());
                delete("check");
        }
        else if ( mode == 1 ) {
                message( "vision","吊桥缓缓地绞了起来。\n",this_object());
                delete("check");
        }

        t1 = t - 1260;
        t2 = t - 300;

        if ( t2 > t1 && t2 < 0 ) {
                t3 = -t2;
                mode = 1;
        }
        else if ( t2 > t1 && t2 > 0 && t1 < 0 ) {
                t3 = -t1;
                mode = 2;
        }
        else {
                t3 = 1440 - t + 300;
                mode = 1;
        }
        if ( !query("check") ) {
                call_out("exit", t3, mode);
                add("check", 1);
        }
        return 1;
}
