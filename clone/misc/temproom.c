// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

#include <ansi.h>

inherit CHAT_ROOM;

string *ctitle =({
	"作风问题","生活习惯","江湖事迹","婚姻大事","雷锋精神","恩怨事非","男女关系",
	"儿女私情","喋血江湖",
});
void create()
{
	set("short","聊天室");
	set("desc",@LONG
这里是武林列传提供给玩家聊天使用的聊天室，聊天室里粉刷一新，
一张八仙桌摆设在聊天室的正中，边上还放着几把红木制的椅子。聊天
室的四面角落都放着一盆盆栽，点缀之下，显得格外典雅。聊天室门上
挂着一块牌子(paizi)，上面好像写了些什么。
LONG);
	set("title",sprintf(HIW"关于%s同志的%s展开会议。\n"NOR,
		query("master_name")?query("master_name"):"某某",
		ctitle[random(sizeof(ctitle))]));
	set("long",sprintf("%s\n    目前话题：%s\n",
		query("desc"),query("my_title")?query("my_title"):query("title")));
	set("exits", ([
		"out": "/d/center/chat_room",
	]) );
	set("virtual_room",1);
	set("restrict_action",1);
	::create();
}
void init()
{
	add_action("do_lock","lock");
	add_action("do_say","say");
	add_action("do_block","block");
	add_action("do_kickout","kickout");
	add_action("do_change","change");
	add_action("do_yaoqing","yaoqing");
	add_action("do_sign","sign");
}
int do_yaoqing(string arg)
{
	object me,ob;
	int t;
	
	me = this_player();
	
	t = (int)me->query_temp("time/chatroom");

	if((string)me->query("id") != query("master"))
		return notify_fail("你不是聊天室的主人，没有授权不能邀请其他人进入。\n");

	if(!arg)
		return notify_fail("你想要邀请谁到你的聊天室来？\n");

	if(!objectp(ob = find_player(arg))
		|| !me->visible(ob))
		return notify_fail("这个玩家不在游戏中，邀请失败。\n");

	if(ob == me)
		return notify_fail("你就别瞎折腾了，怎么能邀请自己呢？\n");

	if( t && t > time())
		return notify_fail("你刚刚发出邀请，还是等一下再说吧。\n");

	if(environment(ob) == environment(me))
		return notify_fail(ob->name()+"不正在你身边嘛？\n");
	
	me->set_temp("time/chatroom",time()+60);

	write("你邀请"+ ob->name() +"到你的聊天室来。\n");
	tell_object(ob,sprintf(HIM"\n%s邀请你到%s的聊天室去，请到英雄楼聚义厅(enter %s)进入。\n\n"NOR,
		me->name(),gender_pronoun(me->query("gender")),me->query("id")));
	

	return 1;
}
int do_lock(string arg)
{
	object me;
	me = this_player();
	
	if(!arg)
		return notify_fail("你要关闭还是开启聊天室？指令格式：lock off / on 。\n");

	if(query("master") != me->query("id"))
		return notify_fail("你不是聊天室的主人，不能进行操作。\n");
	
	if(arg == "off"){
		if(query("lock"))
			return notify_fail("聊天室目前已经锁住了，无法让他人进入了。\n");
		message_vision(HIM"$N凌空一指，只见聊天室的大门“哐”的一声关上，锁住了。\n"NOR,me);
		set("lock",1);
		return 1;
	}
	if(arg == "on"){
		if(!query("lock"))
			return notify_fail("聊天室并没有上锁。\n");
		message_vision(HIM"$N轻轻一推，把聊天室的大门打开了。\n"NOR,me);
		delete("lock");
		return 1;
	}
}
int do_say(string arg)
{
	object me;
	string type,color;
	
	me = this_player();
	if(stringp(color = (string)me->query("env/chat_color")))
		type = "$"+ color +"$";
	else
		type = "$CYN$";
	
	if(!arg) return 0;

	if(arg && arg != ""){
		if((string)me->query_temp("block_say/"+ query("master"))){
			write("你刚想说话，却发现嘴巴被贴的严严实实的，透不过气来。\n");
			return 1;
		}
			
		write(convert_color(type) + "你说道：" + arg + "\n"NOR);
		message("sound",convert_color(type) + me->name() + "说道："+ arg + "\n" NOR,environment(me), me);
		return 1;
	}
}
int do_block(string arg)
{
	object me,obj;
	me = this_player();
	
	if(!arg)
		return notify_fail("你要剥夺谁的发言权？指令格式：block <玩家id>\n");

	if(query("master") != me->query("id"))
		return notify_fail("你不是聊天室的主持人，不能剥夺他人说话的权利。\n");
	
	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("你要剥夺谁说话的权利？\n");

	if(obj == me)
		return notify_fail("剥夺自己的发言权，只要不说话就可以了。\n");
	
	if(obj->query_temp("block_say/"+ me->query("id"))){
		message_vision(HIM"$N从$n嘴上扯下一块胶布，上面还沾了一些口水......\n"NOR,me,obj);
		tell_object(obj,me->name()+"恢复了你说话的权利。\n");
		obj->delete_temp("block_say/"+ me->query("id"));
		return 1;
	}
	else {
		obj->set_temp("block_say/"+ me->query("id"),1);
		message_vision(HIM"$N拿起一块胶布，把$n的嘴巴贴得严严实实的。\n"NOR,me,obj);
		tell_object(obj,"你说话的权利被"+ me->name() +"剥夺了。\n");
		return 1;
	}
}
int do_kickout(string arg)
{
	object me,obj;
	me = this_player();
	
	if(!arg)
		return notify_fail("你要将谁赶出聊天室？\n");
	
	if(query("master")!= me->query("id"))
		return notify_fail("你不是聊天室的主持人，不能驱赶其他玩家。\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("你要将谁赶出聊天室？\n");
		
	if(obj == me)
		return notify_fail("你不能驱赶自己离开聊天室。\n");
	
	message_vision(HIM"$N对着$n狠狠的踢了一脚，把$n踢出了聊天室。\n"NOR,me,obj);
	obj->move("/d/center/chat_room");
	message_vision(WHT"只听见“啪”的一声，$N被人从聊天室里踢了出来，重重的摔在地上，好狼狈啊。\n"NOR,obj);
	return 1;
}
int do_change(string arg)
{
	object me;
	string tmp;

	me = this_player();
	
	if(!arg)
		return notify_fail("你要将聊天话题设置成什么？\n");

	if(query("master") != me->query("id"))
		return notify_fail("你不是聊天室的主持人，不能更改标题。\n");

	tmp = clean_color(arg);	
	if(strlen(tmp) > 42 )
		return notify_fail("你设置的聊天话题太长了。\n");
	
	message_vision("$N将目前的讨论话题修改为："+ convert_color(arg) +"。\n"NOR,me);
	set("my_title",arg+"\n"NOR);
	create();
	return 1;
}
int do_sign(string arg)
{
	object me;
	string msg;
	me = this_player();
	
	if(query("master") != me->query("id"))
		return notify_fail("你不是聊天室的主人，不能更改聊天室的牌子。\n");
	
	if(!arg || arg == "")
		return notify_fail("你要在牌子上写什么？\n");
	
	msg = clean_color(arg);
	if(strlen(msg) > 42)
		return notify_fail("你真罗嗦，写那么多信息干什么？\n");
	
	message_vision("$N龙飞凤舞的在聊天室的牌子上写了一些字。\n",me);
	set("item_desc/paizi",arg +"\n"NOR);
	return 1;
}
	
void reset()
{
	object *inv;
	object *obj;

	if(query("master") && !find_player(query("master"))){
		inv = all_inventory(this_object());
		obj = filter_array(inv, (: $1->is_character() :), this_object());
		tell_object(obj,HIC"聊天室的主人已经不在了，聊天室也自动关闭了。\n"NOR);
		obj->move("/d/center/chat_room");
		destruct(this_object());
	}
	else
		return;
}
