// chat_room.c 

#include <ansi.h>

#define SAVE_FILE	DATA_DIR +"sign"

inherit F_SAVE;
inherit ROOM;

string query_save_file()
{
	return SAVE_FILE;
}
string *name = ({ });
void create()
{
	seteuid(ROOT_UID);
	set("short", "忠义堂");
	set("long", @LONG
这里是英雄楼的忠义堂，堂中有一块硕大的大理石石碑(sign)，披着
一道红色的锦缎。石碑上面密密麻麻的刻着烫金的人名，这些都是热心于
武林列传建设发展的荣誉玩家的名字。端庄肃穆，不禁让人肃然起敬。
LONG
);
	restore();
	set("exits",([
		"east": __DIR__"chat_room",
	]));
	set("restrict_action",1);
        set("chat_room", 1);
        set("restrict_enter_room", 1);
	set("restrict_fly_room",1);
        set("restrict_action", 1);
        set("no_sleep_room",1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_spells", 1);
        set("no_steal", 1);
        set("no_beg",1);
	setup();
}
void init()
{
	add_action("do_sign","sign");
	add_action("do_look","look");
}
int do_sign(string arg)
{
	object me;
	
	me = this_player();

	if(!wizardp(me) || wizhood(me) != "(admin)")
		return notify_fail("你没有权利在这里写字。\n");
	
	if(!arg || arg == "")
		return notify_fail("你要在石碑上写什么？\n");

	message_vision("$N手持金笔，龙飞凤舞的在石碑上写下了「"+ arg +"」的大名。\n",me);

	if(!file_size(SAVE_FILE) < 0) 
		name = ({ arg });
	else 
		name += ({ arg });

	if(save()){
		tell_object(me,"名字记录成功。\n");
		restore();
	}
	return 1;
}
int do_look(string arg)
{
	object me;
	string str;
	int i;
	
	me = this_player();

	if(!arg || arg != "sign") return 0;
	if(!file_size(SAVE_FILE) < 0){
		write("石碑上的锦缎还没有揭开，你什么也看不到。\n");
		return 1;
	}
	str = "石碑上写着：\n";
	str+= "─────────────────────────────\n";
	str+= HIW + BBLU"　　　　　　武　林　列　传　荣　誉　玩　家　榜　　　　　　\n"NOR;
	str+= "─────────────────────────────\n\n"HIW;
	for(i=0;i<sizeof(name);i++){
		str += sprintf("%-20s ",name[i]);
		if(i%3==2) str +="\n";
	}
	str+= "\n\n　　　　　　　　　　　　　感谢以上玩家对武林列传的支持！\n"NOR;
	str+= "─────────────────────────────\n";
	str+= HIW + BBLU"   　　　　　　　　　　  武林列传巫师组 2001年11月15日敬立\n"NOR;
	str+= "─────────────────────────────\n";
	write(str+"\n");
	return 1;
}
