
inherit ROOM;
#include <room.h>
void create()
{
	set("short", "长廊");
	set("long", @LONG
这里是给到这儿的小裤们更衣入浴的，地上是五光十色的彩带和香味
扑鼻的花瓣，昂贵的衣裳满地都是，透过蒙蒙水雾，你可以看到白腻的身
躯，修长的大腿，坚挺的胸膛，和乌黑的长发.......
LONG
	);
	set("exits", ([
		"east" : __DIR__"bathhouse_f2",
		"west" : __DIR__"bathhouse_fpool",
	]));
	set("objects", ([
		__DIR__"npc/bellboy": 1,
	]) );
	setup();
	create_door("west", "檀木门", "east", DOOR_CLOSED);

}
int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;
	int withtowel=0;
	if( dir == "west" && ob=present("little bellboy", this_object()))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			// if((string)(inv[i]->query("id")) != "white towel")
			if (inv[i]->query("equipped") && inv[i]->query("id") != "white towel")
			return notify_fail(ob->name()+"向你笑道：身上穿戴那么多，怎么能洗澡？\n");
			if( (string)(inv[i]->query("id")) == "white towel" &&
			    !(int) inv[i]->query("equipped"))
			return notify_fail(ob->name()+"向你笑道：还是围上毛巾再进去吧，不要吓到别人．\n");
			if( (string)(inv[i]->query("id")) == "white towel" )
				withtowel = 1;
		}
	if( !withtowel)
	return notify_fail(ob->name()+"向你笑道：没有白毛巾怎么洗？\n");
	}
	if( dir == "east" && ob=present("little bellboy", this_object()))
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
		if( (string)(inv[i]->query("id")) == "white towel")
			{
		tell_object(me,ob->name()+"笑咪咪的将你身上湿的"+
		inv[i]->name()+"拿了回去．\n\n\n");     
		destruct(inv[i]);
			}
		}


	}
	return 1;
}

