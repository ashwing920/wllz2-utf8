// restroom.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short","药房");
	set("long",@LONG
这里是间药房，靠墙放着一只大药柜。屋子里有张桌子，上边摆满了
炼药用的瓶瓶罐罐。其中一个药瓶(bottle)里只装了清水。炼药师是位小
姑娘，正在那里发呆，不知在想什么。北面是气派的长廊。
LONG
);
	set("exits",([
		"north" : __DIR__"changlang",
	]));
	set("item_desc",([
		"bottle" : "药罐上贴着标签：『蛇胆膏』，乃珍贵补品，生精补气，效果奇佳。\n",
	]));

	set("objects",([
		__DIR__"npc/xiaoqing" : 1,
	]));
	setup();
	replace_program(ROOM);
}

