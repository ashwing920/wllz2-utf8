// TIE@FY3

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "椎捣狱");
	set("long", @LONG
迎面就是几个巨人，手持大椎，几个巨大的类似捣药碗似的东西里面
似乎有惨叫之声传来，定睛细看，原来是囚犯被放进去，由巨人捣为肉泥
，看了这许多惨状，你镇定了许多。“善恶到头终须报”，早知今日，何
必当初啊。定了定神，你毅然地走向车崩狱。
LONG
);
	set("exits", ([
		"up" : __DIR__"moai",
		"down" : __DIR__"chebeng",
	]) );
	set("death",1);
	setup();
	replace_program(ROOM);
}

