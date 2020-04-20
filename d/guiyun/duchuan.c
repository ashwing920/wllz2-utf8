// Design By Robert 蝴蝶君 email:stcoolman@21cn.com
// Room: /guiyun/duchuan.c

inherit ROOM;

void create()
{
	set("short", "渡船");
	set("long", @LONG
离岸渐远，四望空阔，真是莫知天地之在湖海，抑或是湖海之在天地
。老梢公在船尾悠闲地划着水。
LONG
);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}
