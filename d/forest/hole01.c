// /d/kunming/pubu

inherit ROOM;

void create()
{
	set("short","千年古洞");
	set("long", @LONG
这是位于松树林间的一个山洞。洞里一片漆黑，洞口照射进来的一线
微弱的光线，成为山洞里唯一的导向。洞里的通道十分宽敞，足可容纳四
个人并排而行。由于长期照射不到阳光，山洞的地面显得格外的潮湿。你
脚踩在地面上，不时发出咔哒的声响，仔细看去，地面上零散的披散着一
些鸟兽的骸骨。
LONG
);
	set("exits",([
		"out": __DIR__"path08",
		"north": __DIR__"hole02",
	]));
	setup();
	replace_program(ROOM);
}
