// biwuchang_fight_room.c - 比武场大擂台

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "比武场大擂台");
	set("long", @LONG

    $BRED$$HIY$※※※※※※※※※※※※※※※※※※※※※※※※※※※※$NOR$
    $BRED$$HIY$※※※※※※※※※※※※※※※※※※※※※※※※※※※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※          $HIW$这里是桃源城的竞技场大擂台。$HIY$          ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※                                                ※※$NOR$
    $BRED$$HIY$※※※※※※※※※※※※※※※※※※※※※※※※※※※※$NOR$
    $BRED$$HIY$※※※※※※※※※※※※※※※※※※※※※※※※※※※※$NOR$

LONG
);

	set("fight_room",1);
	set("no_sleep_room",1);
	set("no_steal",1);
	set("no_beg",1);
	set("exits", ([
		"down" : __DIR__"jingjichang",
	]) );
	setup();
}
void init()
{
/*	remove_call_out("cleanup_room");
	call_out("cleanup_room",1);
*/	
	add_action("do_quit","quit");
}
/*
void cleanup_room()
{
	object *inv;
	int i;
	
	inv = all_inventory(this_object());
	for(i=0;i<sizeof(inv);i++){
		if( (string)inv[i]->query("race") == "人类"
		&& inv[i]->is_character()) continue;
		destruct(inv[i]);
	}
	remove_call_out("cleanup_room");
	call_out("cleanup_room",1);
}
*/
int vulid_level(object me,string dir)
{
	if(dir =="down")
		me->remove_all_killer();
	return ::valid_leave(me, dir);
}
int do_quit(string arg)
{
	object me;
	me = this_player();
	
	if((int)me->query("eff_qi") <= 0) me->set("eff_qi",(int)me->query("max_qi"));
	if((int)me->query("eff_jing") <= 0) me->set("eff_jing",(int)me->query("max_jing"));
	if((int)me->query("qi") <= 0) me->set("qi",100);
	if((int)me->query("jing") <= 0) me->set("jing",100);
	return 0;
}
