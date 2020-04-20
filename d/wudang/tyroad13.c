// tyroad13.c 桃园小路
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;
string* npcs = ({
	"little_monkey",
	"monkey",
	"little_monkey",
	"little_bee",
	"bee",
	"little_bee",
});
			
void create()
{
	int i = random(sizeof(npcs));
		
	set("short", "桃园");
	set("long", @LONG
眼前豁然开朗，你轻松地走在桃园的小路上。两边是桃树林(tree)，
树上盛开着粉红的桃花，红云一片，望不到边。不时有蜜蜂「嗡嗡」地飞
过，消失在在花丛中；几只猴子在树上互相追逐着，叽叽喳喳地争抢桃子
。远处是高高的天柱峰(feng)。
LONG
);
	set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"gyroad1",
		"west" : __DIR__"tyroad12",
	]));
	
	set("item_desc", ([
		"tree" : "这是一片桃林，上面结满了水蜜桃，引得人哈喇子都掉下来了。\n"
	]));
	set("objects", ([
		CLASS_D("wudang") + "/shouyuan" : 1,
		__DIR__"npc/"+npcs[i] : 1
	]));
	set("taocount",2);
	setup();
}
void init()
{
	add_action("do_zhai","zhai");
}
int do_zhai(string arg)
{	
	object tao;
	if( !arg || arg=="" ) 
		return notify_fail("你想摘什么？\n");
	if( arg=="tao"||arg=="taozi" ) {
		if(query("taocount") > 0){
		message_vision("$N桃树上摘下一个熟透的水蜜桃。\n",this_player());
		tao = new(__DIR__"obj/mitao");
		tao->move(this_player());
		add("taocount",-1);
		return 1;
	}else
	message_vision("你这么着急呀？桃还没熟呢。\n" , this_player());
	remove_call_out("do_tao");
	call_out("do_tao",60);
		return 1;		 
	}
	return 0;
}
void do_tao()
{
	set("taocount",2);
}
