inherit ROOM;

void create()
{
	set("short", "渡船");
	set("long", @LONG
你从听雨居的活动机关中掉到了一艘小舟上，船上的船夫对你说：“
坐稳了”，咱们这就到曼佗罗山庄去。
LONG
);
	setup();
}
void run(object ob)
{
	if(!ob || environment(ob) != this_object()) return;
	ob->move(__DIR__"xiaozhou1");
	write(@TEXT
船夫把船驶进了一片一望无际的荷花荡。一眼望去，满湖荷叶，菱叶，芦苇，
茭白，都是一模一样，兼之荷叶，菱叶在水面漂浮，随时一阵风来，便即变
化百端，就算此刻记得清清楚楚，霎时间局面便全然不同。
TEXT);
}

void init()
{
	object ob = this_player();
	call_out("run", 3, ob);
}
