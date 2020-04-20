
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","内堂");
	set("long",@LONG
这里是燕子坞的内堂，里面是平时慕容家眷呆的地方，丫鬟和婢女们在这
里伺候着慕容一家。墙面上挂着一幅五寿图，房梁(liang)是用上好的楠木作的。
屋子中间放着一张八仙桌(zhuo)，桌子上摆着水蜜桃和荔枝。
LONG);
	set("exits",([
		"north" : __DIR__"houting",
		"east" : __DIR__"shangyuezhai",
		"west" : __DIR__"jingyinge",
	]));
	set("item_desc",([
		"zhuo":"一张擦拭的干干净净的八仙桌，却留下了几个稀疏的脚印，显然曾经有人跳上过。\n",
		"liang":"一条普通的房梁，好像没有什么特别的地方，是不是要摸索一下呢？\n",
	]));
	set("objects",([
	    __DIR__"npc/obj/mitao" : 2,
	    __DIR__"npc/obj/lizhi" : 2,
	]));
	set("count",1);
	setup();
}
void init()
{
	add_action("do_jump","jump");
	add_action("do_search","mo");
	add_action("do_search","mosuo");
}
int do_jump(string arg)
{
	object me;
	me = this_player();
	
	if(!arg) return 0;
	
	if(arg == "八仙桌" || arg =="zhuo"){
		if(me->query_temp("jump_zhuo")){
			write("你已经在八仙桌上了。\n");
			return 1;
		}
		message_vision("$N轻轻一跃，跳上了八仙桌。\n",me);
		me->set_temp("jump_zhuo",1);
		return 1;
	}
	return 0;
}
int do_search(string arg)
{
	object me,obj;
	me = this_player();
	
	if(!arg) return 0;

	if(!me->query_temp("jump_zhuo")) return 0;

	if(arg == "liang" || arg == "房梁"){
		if(query("count") < 1){
			message_vision("$N站在八仙桌上，对着房梁摸索了半天，什么也没找到，便从桌子上跳了下来。\n",me);
			me->delete_temp("jump_zhuo");
			return 1;
		}
		message_vision("$N伸手摸了摸房梁之上，发现一块方形的硬物，随手揣在怀里，从桌子上跳了下来。\n",me);
		obj = new("/d/yanziwu/npc/obj/yuxi");
		obj->move(me,1);
		CHANNEL_D->do_channel(find_object(MASTER_OB),"rumor",
			sprintf("听说%s在内堂拿到慕容家的%s了！",
				me->name(),obj->name() + HIM));
		add("count",-1);
		me->delete_temp("jump_zhuo");
		return 1;
	}
	return 0;
}
void reset()
{
	set("count",1);
}