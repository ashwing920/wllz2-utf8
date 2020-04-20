
inherit ROOM;

void create()
{
	set("short", "渡船");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名老船夫手持长竹篙，正在
船尾吃力地撑着船。你放眼望去，湖面上的美丽景色使你浮想连篇。
LONG
);
	setup();
}
void run(object ob)
{
	if(!ob || environment(ob) != this_object()) return;
	ob->move(__DIR__"xiaozhou2");
	write(@TEXT
小舟驶进一片一望无际的荷花荡。一眼望去，满湖荷叶，菱叶，芦苇，茭
白，都是一模一样，兼之荷叶，菱叶在水面漂浮，随时一阵风来，便即变
化百端，就算此刻记得清清楚楚，霎时间局面便全然不同。
TEXT);
}
void init()
{
	object ob = this_player();
	call_out("run", 10, ob);
}
