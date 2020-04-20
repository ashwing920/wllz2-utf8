//m_weapon .....xuanbing1.c
//xuanbing.c

inherit ROOM;

void create()
{
	set("short", "玄兵古洞");
	set("long",@LONG
这里是玄兵古洞，四面洞壁之上结满了石英的柱状结晶体，显得十分
漂亮。前方一个巨大的炉子前站着一位长髯老者正看着炉火想着什么心事
，旁边几个彪形大汉正挥舞着锤头敲打着一块似乎总也烧不红的什么金属
。旁边仔细的放着几把刚刚出炉的兵器。那种骇人的杀气竟是从这些兵器
上散发出来的。
LONG
);
	set("exits", ([
		"out" : __DIR__"xuanbing",
	]));
	set("objects" , ([
		   __DIR__"npc/tianjianshi" : 1,

	]) );
	setup();
	replace_program(ROOM);
}
