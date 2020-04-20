//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: qianfoan.c 千佛庵

inherit ROOM;

void create()
{
	set("short","千佛庵");
	set("long",@LONG
此处是洪椿坪千佛庵。山间小坪坝，四面层峦叠障，峰环岭护；两侧
深谷幽岚，溪涧玲叮。坪上古木扶疏，亭亭如盖，山阴沁透，白雾飘游，
极为幽静清凉。此处常见雨雾霏霏，林中迷迷蒙蒙，乃山中雾气所为。正
所谓「山行本无雨，空翠湿人衣」。这就是誉为奇观的「洪椿晓雨」。此
处殿美景幽，气象新异，令人心醉。沿途南上是「九十九道拐」，北下经
黑龙江栈道至清音阁。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"southwest" : __DIR__"jsjdg1",
		"enter"	 : __DIR__"qfadadian",
		"north"	 : __DIR__"heilong2",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if(dir == "southwest"){
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		me->add("qi",-10);
	if(((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
		tell_object(me,"你沿九十九道拐又向上爬了一阵，觉得好累。\n");
	}
	return 1;
}

