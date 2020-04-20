inherit ROOM;

void create ()
{
	set("short","聚义厅");
	set("long",@LONG
这是一间宽敞明亮的大厅，厅的正中间是一根圆形的柱子。柱子上贴
满了各种广告：有换房的，有卖家具的，但其中最多的还是找打牌搭档的
广告。厅的东南西北各有个门，里面传出“拱啊！”“毙了！”等的叫声。
LONG
);

	set("exits",([
		"down" : __DIR__"clubpoem",
		"north": __DIR__"piggy",
		"south": __DIR__"qishi",
	]));
	setup();
	replace_program(ROOM);
}
