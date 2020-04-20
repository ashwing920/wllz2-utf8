// 百人道场休息室
// Design By Robert 蝴蝶君 emial:robert_st@sina.com

inherit ROOM;

void create()
{
	set("short","百人道场大厅");
	set("long",@LONG
这里是桃源百人道场的大厅。一进大厅，大厅正中那副字画即刻印入
眼帘。只见上面龙飞凤舞的写着「$YEL$百人道场$NOR$」四个大字，字字刚劲有力，
显然是出于名家的手笔。大厅正中有位白发苍苍的长者，道貌岸然之势，
显出一股迫人的气势。据说百人道场内高手云集，只要能够挑战闯过道场
的一百名弟子，即可获得一些未曾所见的神兵利器或失传已久的武功秘籍
。各路武林高手慕名而来，成功闯过的却是寥寥无几。大厅右边的门口贴
着一张告示(sign)，上面好象写着什么。
LONG
);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	set("no_beg",1);
	set("item_desc",([
		"sign": @TEXT

　　　　　　　　　　百人道场挑战规则

　　入我百人道场者，需具一定的江湖威望以及江湖阅历，每次进入道场
参与挑战的武者只许一人。挑战者门派、性别、武功、兵刃不限。道场内
不得睡觉、终止战斗，挑战以生死搏斗直至一方死亡为止。
　　如符合以上要求者，请付黄金二千两即可加入挑战。

　　　　　　　　　　　　　　　　　　　　　　百人道场示

TEXT
	]));
	set("exits",([
		"east":	"/d/center/roads7",
	]));
	setup();
	replace_program(ROOM);

}
