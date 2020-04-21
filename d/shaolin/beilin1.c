// Room: /d/shaolin/beilin1.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;
#include <ansi.h>
string look_tower();
string look_stone();

void create()
{
	set("short", "东碑林");
	set("long", @LONG
这里是少林寺一大片碑林。虽说是碑林，主要是少林历代高僧的佛塔
灵藏(tower)。一座座佛塔约有二三人高，有汉白玉的， 花冈石的，精工
雕凿，薄薄的浮雕面上飞禽走兽，佛谒禅诗，诸佛众生，可谓无所不包。
底座有须弥座的，也有莲花座的，各态纷呈。佛塔间疏疏落落的立着几块
碑(stone)，有的题着几句诗。
LONG
);
	set("exits", ([
		"west" : __DIR__"taijie",
	]));
	set("outdoors", "shaolin");
	set("item_desc",([
		"tower"	:  (: look_tower :),
		"stone"	:  (: look_stone :),
	]));
	setup();
}
string look_tower()
{
	return
	CYN"\n"
	"	※※※※※※※※※※※※※※※※※※※※\n"
	"	※※※※　　　　　　　　　　　　※※※※\n"
	"	※※※※　万物一般，众生平等。　※※※※\n"
	"	※※※※　　　　　　　　　　　　※※※※\n"
	"	※※※※　圣贤畜生，一视同仁。　※※※※\n"
	"	※※※※　　　　　　　　　　　　※※※※\n"
	"	※※※※　红颜白骨，亦幻一真。　※※※※\n"
	"	※※※※　　　　　　　　　　　　※※※※\n"
	"	※※※※　恩怨荣辱，俱在灰尘。　※※※※\n"
	"	※※※※　　　　　　　　　　　　※※※※\n"
	"	※※※※※※※※※※※※※※※※※※※※\n"NOR;
}

string look_stone()
{
	return
	CYN"\n"
	"	※※※※※※※※※※※※※※※※※※※※※※\n"
	"	※※※※　　　　　　　　　　　　　　※※※※\n"
	"	※※※※　境井漱寒齿，清心拂尘服。　※※※※\n"
	"	※※※※　闲持贝叶经，步出东斋读。　※※※※\n"
	"	※※※※　真源了无取，妄迹世所逐。　※※※※\n"
	"	※※※※　遗言冀可冥，缮性何由熟？　※※※※\n"
	"	※※※※　道人庭宇静，苔色连深竹。　※※※※\n"
	"	※※※※　日出雾露余，青松如膏沐。　※※※※\n"
	"	※※※※　淡然离言说，悟悦心自足！　※※※※\n"
	"	※※※※　　　　　　　　　　　　　　※※※※\n"
	"	※※※※※※※※※※※※※※※※※※※※※※\n"NOR;
}
