inherit ROOM;

void create()
{
	set("short", "大石块");
	set("long", @LONG
你发现自己身处一块大石上面，三面悬空，下面就是万丈绝壁，旁边
有一个小山洞，凭洞口的凿痕可以看得出这个山洞是由人工开出的，里面
隐约透出点光。
LONG
);
	set("exits",([
		"south" : __DIR__"shandong",
	]));
	setup();
	replace_program(ROOM);
}
