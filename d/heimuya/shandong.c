//shandong.c

inherit ROOM;

void create()
{
        set("short", "山洞");
        set("long", @LONG
这是令狐冲和盈盈曾经居住的地方，洞里点着盏油灯，借着微弱灯光
。看到洞里摆设着几张石椅石床，角落竖着一块(石碑)，布置得极之简朴
，都是就地取材由洞内石块加工而成，但在这绝壁中开凿出这样一个山洞
确实不易。
LONG
);
        set("objects",([
                CLASS_D("riyue")+"/yingying" : 1,
        ]));
        set("exits", ([ 
                "south" : __DIR__"shandong2",
                "north" : __DIR__"dashikuai",
        ]));
        setup();
        replace_program(ROOM);
}
