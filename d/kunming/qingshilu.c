// /d/kunming/qingshilu

inherit ROOM;

void create()
{
        set("short",  "青石路" );
        set("long", @LONG
出了石林，就到了昆明的官道，青石铺成，平坦宽阔，西去不远就是
昆明了。
LONG
);
        set("outdoors", "kunming");
        set("exits", ([
                "west" : __DIR__"qingshilu1", 
                "northeast"  :__DIR__"shilin2",
                "south": __DIR__"xiaoxi",
        ]));
        setup();
        replace_program(ROOM);
}
