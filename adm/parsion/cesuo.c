// cesuo.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","厕所");
	set("long",@LONG
$YEL$这里是武林列传用来收押那些喜欢造谣生事，满嘴胡言乱语的好事之
徒专用的厕所。污秽不堪，陈年的夜香散发着“醉”人的香味。此情此景
，配合着收押的人，搭配得恰到好处。厕所的边上放着一张方桌，上面有
一条牙膏，是给收押的犯人漱口用的。$NOR$
LONG
);
	set("outdoors","city");
	set("no_fight",1);
	set("no_kill",1);
	set("no_steal",1);
	set("no_magic",1);
	set("no_spells",1);
	set("no_beg",1);
	set("parsion_room",1);
	setup();
}
void init()
{
	object ob,*all;
	int i;

	seteuid(getuid());
	if(interactive(ob = this_player()) && !wizardp(ob)){
		all = all_inventory(ob);
		for (i = 0; i<sizeof(all); i++) {
		if(all[i]->query("equipped"))
			all[i]->delete("equipped");
			destruct(all[i]);
		}
		ob->set("startroom","/adm/parsion/cesuo");
		ob->disable_player("<漱口中>");
	}
}
