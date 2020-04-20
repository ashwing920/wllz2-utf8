// qishe.c 凌云棋社
// Design By Robert 蝴蝶君 Email:robert_st@263.net 

inherit ROOM;

void create()
{
        set("short", "凌云棋社");
        set("long", @LONG
这里是桃源城最出名的「凌云棋社」。这里宁静得连根针掉在地上都
听得见，只是偶而发出「啪嗒」的声响。你看看四周，这间棋社装饰得十
分豪华，只见棋社的正中央，龙飞凤舞的写着一个「棋」字。字体苍劲有
力，显然是出自于名家的手中。棋社的中央，放着几张桌子，桌子上放着
一个个棋盘，有两个老人正在对弈，引得众人围在桌子旁观看。
LONG
);

        set("exits", ([
		"west"  : __DIR__"roads5",
        ]));
        set("objects", ([
                                CLASS_D("xiaoyao")+"/fanbl" : 1,
		"/clone/misc/qipan": 1,
        ]) );
        setup();
 
       
}
