// chemadian.c

inherit ROOM;

void create()
{
	set("short", "车马店");
	set("long", @LONG
这是桃源城的一间马厩，专门贩卖马匹，常年为官府提供不少快马。
这里的马夫们对马匹都好生照看，将它们喂饱饮足，再洗刷得干乾净净，
一直培养到卖给客人和江湖侠士。雨檐下的木柱上钉着一块木牌(sign)。
马厩中堆放著几堆草料，正中有一口泔槽。
LONG
);
        set("item_desc", ([
                "sign": @TEXT
$WHT$
桃源城马厩，日前提供以下马匹贩卖：
$CYN$
紫骝马、大鬃马、黄骠马、烈日马、追风马、千里马
$WHT$
欢迎选购！
$NOR$
TEXT
        ]) );

	set("exits", ([
                "north"	: __DIR__"roade3",
        ]) );

        set("objects", ([
                __DIR__"npc/seller-cmd": 1,
	]) );

	setup();
	replace_program(ROOM);
}
