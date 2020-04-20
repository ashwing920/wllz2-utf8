inherit ROOM;

void create()
{
	set("short", "渡船");
	set("long", @LONG
一叶小舟，最多也就能载七、八个人。一名六十多岁的老艄公手持长
竹篙，正在船尾吃力地撑着船。
LONG
);
	setup();
}
void run(object ob)
{
	if(!ob || environment(ob) != this_object()) return;
	ob->move(__DIR__"xiaozhou3");
	write("\n小船在荷花溏中缓缓而行,不一会你变看到曼佗罗山庄的轮廓了。\n\n");
}
void init()
{
	object ob = this_player();
	call_out("run", 10, ob);
}
