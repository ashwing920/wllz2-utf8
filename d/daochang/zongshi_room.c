// 百人道场
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit CHALLENGE_ROOM;

void create()
{
        set("short","百人道场密室");
        set("long",@LONG
这里是百人道场至上层的密室。只见密室里阴暗潮湿，密不透风。只
有密室两边的几盏油灯，闪烁着微弱的光芒。借着微弱的灯光，你看到密
室中分布着几条出口。
LONG
);
        set("objects",([
                __DIR__"npc/yongzhe":1,
        ]));
        set("exits",([
                "north": __DIR__"mishi_n",
                "east": __DIR__"mishi_e",
                "west": __DIR__"mishi_w",
                "south": __DIR__"mishi_s",
        ]));
        ::create();
}
