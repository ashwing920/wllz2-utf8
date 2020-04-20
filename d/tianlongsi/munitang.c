// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "牟尼堂");
	set("long",@LONG
这是高僧们的静修之处。整堂全以松木制成，板门木柱，木料均不去
皮，天然质朴，和一路行来金碧辉煌的殿堂截然不同。室中五个和尚分坐
五个蒲团。四僧朝外，东首一个和尚面朝里壁一动不动。
LONG
);
	set("exits", ([
		"north": __DIR__"banruotai",
	]));
	set("objects",([
		CLASS_D("tianlong")+"/benchen" : 1,
		CLASS_D("tianlong")+"/kurong" : 1,
		CLASS_D("tianlong")+"/benguan" : 1,
		CLASS_D("tianlong")+"/benxiang" : 1,
		CLASS_D("tianlong")+"/bencan" : 1,
	]));
	setup();
	replace_program(ROOM);
}
