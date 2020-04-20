//room: /d/mingjiao/neishi.c
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short","明教内室");
	set("long", @LONG
这里是明教内室。小小桌前的窗外，望出去是连绵万里的巍巍昆仑。
窗棂门扇均雕制得美仑美奂，精巧异常桌前端坐一个亮丽女孩，你乍一见
惊异她的美貌，不禁轻轻叫出声来。
LONG
);
	set("exits",([
		"out" : __DIR__"dadian",
	]));
	set("objects",([
		CLASS_D("mingjiao")+"/xiaozhao":1,
	]));
	setup();
	replace_program(ROOM);
}
