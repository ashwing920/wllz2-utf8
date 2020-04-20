//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com
//Room: jsjdg4.c 九十九道拐

inherit ROOM;

void create()
{
	set("short","九十九道拐");
	set("long",@LONG
这是著名的「九十九道拐」，道路纡曲陡竖，千折百回。据说过去曾
有个百余岁的疯僧至此，见一巨蟒挡路，便念咒驱蟒。但人们得知此处有
巨蟒出没后，便再也无人敢碰这里的草木，并以「龙居」名之。由此东可
至千佛庵，西达九老洞。
LONG
);
	set("outdoors", "emei");
	set("exits",([ 
		"eastdown"  : __DIR__"jsjdg3",
		"southwest" : __DIR__"jldongkou",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
	int c_exp,c_skill;
	me = this_player();
	if(dir == "southwest" ){
		c_exp=me->query("combat_exp");
		c_skill=me->query_skill("dodge",1);
		me->add("qi",-10);
	if(((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	tell_object(me,"你沿九十九道拐又向上爬了一阵，终于爬到老龙洞口，好累人。\n");
}
	return 1;
}

