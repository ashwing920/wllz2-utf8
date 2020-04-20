// pawn_ticket.c

inherit ITEM;

string query_autoload() { return "1"; }
void autoload() {}

void create()
{
	set_name("当票", ({ "pawn ticket", "ticket" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "这是一张当铺开出的当票。你可以通过它看到(read)你在当铺的存货。\n");
		set("no_drop", 1);
		set("no_get", 1);
	}
}

int init()
{
	add_action("do_read", "read");
}

int do_read(string arg)
{
	object me;
	mapping pawn;
	string *base_name, msg, str_path, str_name, str_id, str_unit;
	int i, num;

	me = this_player();
	seteuid(geteuid(me));

	if(!arg || !id(arg))    return 0;
	if(environment(this_object()) != me )   return 0;

	if(mapp(pawn = this_player()->query("pawn")) )
		base_name = keys(pawn);

	if(!sizeof(base_name))  return 0;

	msg = "这是一张当铺开出的当票。上面写着：\n";

	for(i = 0; i < sizeof(base_name); i++) {
		sscanf(pawn[base_name[i]], "%s~%s~%s~%d~%s", str_path, str_name, str_id, num, str_unit);
		msg += sprintf("%-2d ", i + 1) + chinese_number(num) + str_unit 
			+ str_name + "(" + str_id + ")\n";
	}

	tell_object(me, msg);

	return 1;
}
void owner_is_killed() { destruct(this_object()); }
