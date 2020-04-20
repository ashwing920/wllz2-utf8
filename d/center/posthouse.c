
// posthouse.c - 驿站

inherit ROOM;

void create()
{
        set("short", "侠客驿");
        set("long", @LONG
这里是负责桃源城城官府文书跟军令往来的侠客驿，驿站的官员顺便
接一些百姓的信件，方便各地之间的通信。一个信差愁眉不展，似乎显得
十分烦躁。驿站大门口上悬著一块木牌（sign）。
LONG
);
        set("exits", ([
                "west"  : __DIR__"roads7",
        ]));
        set("item_desc",([
                "sign": @TEXT

驿站内现有大批信件等待送出，请向驿站老板询问。

TEXT
        ]));
        set("no_fight",1);
        set("objects", ([
                __DIR__"npc/officer": 1,
        ]) );
        setup();
}
int valid_leave(object me,string dir)
{
        object mail_box;
        if( objectp(mail_box = present("mailbox", me) ) ) {
                tell_object(me, "驿站站长把你的邮箱收了回去。\n");
                destruct(mail_box);
        }
        return ::valid_leave(me, dir);
}       

