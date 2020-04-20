
inherit ROOM;

void create()
{
	set("short","心意堂");
	set("long",@LONG
这里是心意堂。堂前最明显的就是一幅气势逼人的猛虎下山图，据说
是当年江南四大才子之一唐寅所赠。
LONG
);

	set("exits",([
		"north" : __DIR__"tianjing",
		"south" : __DIR__"changlang1",
	]));
	setup();
}




