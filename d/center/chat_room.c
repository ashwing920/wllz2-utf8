// chat_room.c 

#include <ansi.h>

inherit CHAT_ROOM;

static string *player;

string *query_player()
{
	return player;
}

void create()
{
	set("short", "聚义厅");
	set("long", @LONG
这里是英雄楼的聚义厅，聚义厅中铺设豪华，大厅中央铺设着一层红
色地毯。中央有一对茶几，两旁则各有一排椅子，是平时提供给侠客英雄
们商议江湖中事的地方。聚义厅正中挂着一副字画，上面龙飞凤舞的写着
一个“义”字。正气凛凛，让人不得不肃然起敬。楼上据说是一些世外高
人们所居住的地方，一般武林侠客是无法上去的。
LONG
);
	player = ({});
	set("exits", ([
		"up"   : "/d/wizard/wizard_room",
		"down" : __DIR__"yingxionglou",
		"1"    : __DIR__"chat_room_1",
		"2"    : __DIR__"chat_room_2",
		"3"    : __DIR__"chat_room_3",
		"4"    : __DIR__"chat_room_4",
		"5"    : __DIR__"chat_room_5",
		"east":  "/d/wizard/towiz_room",
		"west": __DIR__"zhongyi",
	]) );                   
	set("restrict_action",1);
	::create();
}
void init()
{
	add_action("do_look","look");
	add_action("do_create","create");
	add_action("do_enter","enter");
}
int do_create(string arg)
{
	object me,room,myroom;
	me = this_player();
	
	if(!arg || arg =="")
		return notify_fail("你要建立什么？\n");
	
	if(arg == "room"){
		if((int)me->query_skill("idle-force",1) < 100)
			return notify_fail("你的发呆神功不足，无权在这里建立临时的聊天室。\n");
		if(query("rooms/"+ me->query("id")))
			return notify_fail("你已经建立聊天室了。\n");
		room=new("/clone/misc/temproom");
		room->set("item_desc/paizi",me->name(1)+"的聊天室，欢迎光临。\n");
		room->set("master",me->query("id"));
		room->set("master_name",me->name(1));
		set("rooms/"+ me->query("id"),me->name(1)+"的聊天室");
		player += ({ me->query("id")});
		me->set_temp("chat_room",room);
		room->create();
		me->move(room);
		return 1;
	}
	if(arg == "cancel"){
		if(!query("rooms/"+ me->query("id")))
			return notify_fail("目前你还没有创造聊天室。\n");
		if(objectp(myroom = me->query_temp("chat_room"))){
			tell_object(me,"你的聊天室已经清理掉了。\n");
			player -= ({ me->query("id")});
			destruct(myroom);
			delete("rooms/"+ me->query("id"));
			return 1;
		}
	}
}
int do_enter(string arg)
{
	object me,chat_room,obj;
	mapping room;
	string *key,str,room_name;
	int i;

	me = this_player();

	if(!mapp(room = query("rooms"))) 
		return notify_fail("目前这里还没有聊天室。\n");

	str = "目前的聊天室有：\n";
	str+= HIC"≡"HIY"───────────────────────────────"HIC"≡\n"NOR;

	key= keys(room);
	for(i=0;i<sizeof(key);i++){
		str += sprintf(WHT"　%-30s 主持人：%s\n"NOR,room[key[i]],capitalize(key[i]));
	}
	str += HIC"≡"HIY"───────────────────────────────"HIC"≡\n"NOR;

	if(!arg){
		write(str);
		return 1;
	}

	if(undefinedp(room[arg]))
		return notify_fail("没有这间聊天室存在。\n");

	if(!obj = find_player(arg))
		return notify_fail("没有这间聊天室存在。\n");

	if(objectp( chat_room = obj->query_temp("chat_room"))){
		room_name = obj->name(1) +"的聊天室";
		tell_object(me, "你快步向" + room_name + "走去。\n");
		if(chat_room->query("lock") && chat_room->query("master") != me->query("id")){
			message_vision("只听见“哐”的一声，$N一头撞到门板上，仔细一看，"+ room_name +"大门已经上锁了。\n",me);
			return 1;
		}
		message("vision", me->name() +"向" + room_name + "飘然而去。\n", environment(me), ({me}));
		me->move(chat_room);
		message("vision",me->name()+"从外面走了进来。\n",environment(me),me);
		return 1;
	}
	else {
		write("这个聊天室已经不存在了。\n");
		if(query("rooms/"+ arg))
			delete("rooms/"+ arg);
		return 1;	
	}
}
int do_look(string arg)
{
	if(arg == "up" && !wizardp(this_player())){
		tell_object(this_player(),"你伸长了脖子向上望去，却什么也看不到。\n");
		return 1;
	}
	return 0;
}
int valid_leave(object me, string dir)
{
	if( dir == "up" && !wizardp(me) && wizhood(me) != "(immortal)")
		return notify_fail("那里只有世外高人才能进去。\n");
	return ::valid_leave(me, dir);
}
void reset()
{
	int i;

	if(sizeof(query("rooms")) == 0)
		delete("rooms");
	
	for(i=0;i<sizeof(player);i++){
		if(!find_player(player[i]))
			delete("rooms/"+ player[i]);
	}

}
