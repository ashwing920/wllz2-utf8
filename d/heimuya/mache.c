// Design By Robert 蝴蝶君 Email:robert_st@sina.com

inherit ROOM;

void create()
{
        set("short", "马车");
        set("long", "一辆干净宽敞的马车,车夫坐在前面驾车。\n");
        setup();
        replace_program(ROOM);
}
