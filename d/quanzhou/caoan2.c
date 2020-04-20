// chaoan2.c 草庵
// Design By 蝴蝶君(Robert) Email:robert@cnmuds.com

inherit ROOM;

void create()
{
	set("short", "草庵");
	set("long", @LONG
寺内有著名的摩尼石像。它面庞圆阔，眉弯隆起，散发披肩，身着宽
袍僧衣，双手掌心向上置于膝上，神态庄严，别具风采。庵前约四米处，
巨石鹘立，中刻明教咒语，劝念：『清净光明，大力智慧，无上至真，摩
尼光佛』。
LONG
);
	set("exits", ([ /* sizeof() == 4 */
		"out" : __DIR__"caoan1",
	]));
	setup();
}
