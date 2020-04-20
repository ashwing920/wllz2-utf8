
inherit ROOM;

void create()
{
	set("short","藏经阁");
	set ("long",@LONG
这里是曼陀罗山庄的藏经阁，天下武功皆荟粹与此，包罗万象，可与
“燕子坞”的藏书相辟敌。 屋子四周全是一排排高大的书架。
LONG);
	set("exits",([
		"down" : __DIR__"yunjinlou",
	]));
	set("biguan_room",1);
	set("no_fight",1);
	set("no_steal",1);
	set("no_magic",1);
	setup();
	replace_program(ROOM);
}
