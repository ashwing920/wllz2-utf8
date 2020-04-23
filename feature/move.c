// move.c

#include <dbase.h>

#define LOOK_CMD	"/cmds/std/look"

static int weight = 0;
static int encumb = 0, max_encumb = 0;

nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb;}
nomask int query_max_encumbrance() { return max_encumb;}
nomask void set_max_encumbrance(int e) { max_encumb = e; }

nomask void add_encumbrance(int w)
{
	encumb += w;
	if( encumb < 0 )
		log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
	if( encumb > max_encumb ) this_object()->over_encumbrance();
	if( environment() ) environment()->add_encumbrance(w);
}

void over_encumbrance()
{
	if( !interactive(this_object()) ) return;
	tell_object(this_object(), "你的负荷过重了！\n");
}

nomask int query_weight() { return weight; }

nomask void set_weight(int w)
{
	if( !environment() ) {
		weight = w;
		return;
	}
	if( w!=weight ) environment()->add_encumbrance( w - weight );
	weight = w;
}

nomask int weight() { return weight + encumb;}

varargs int move(mixed dest, int silently)
{
	object ob, env,me;

	me = this_object();

	if( query("equipped") && !me->unequip() )
		return notify_fail("你没有办法取下这样东西。\n");

	if( objectp(dest) )
		ob = dest;
	else if( stringp(dest) ) {
		ob = load_object(dest);
		if(!ob) return notify_fail("move: destination unavailable.\n");
	} else
		return notify_fail(sprintf("move: invalid destination %O.\n", dest));

	env = me; 

	while(env = environment(env)) 
		if( env==ob ) break;
	if( !env && (int)ob->query_encumbrance() + weight()
		> (int)ob->query_max_encumbrance() ) {
                if (silently && environment(ob))
                {
                        message_vision("可是$n对$N来说实在"
                                       "是太重了，$N只好暂且将其扔在一旁。\n",
                                       ob, this_object());
                        ob = environment(ob);
                } else
		if( ob==this_player() )
			return notify_fail( this_object()->name() + "对你而言太重了。\n");
		else
			return notify_fail( this_object()->name() + "对" + ob->name() + "而言太重了。\n");
	}

	if( environment() ) environment()->add_encumbrance( - weight());

	move_object(ob);

	ob->add_encumbrance(weight());

	if (!this_object()) return 0;

	if( interactive(this_object()) &&  living(this_object()) && this_object()->is_character()
	&&  objectp(env=environment()) &&  !silently ) {
		LOOK_CMD->look_room(me,ob,query("env/brief"));
	}

	if ((this_object()->query("is_monitored")
	|| file_name(this_object())[0..2]=="/u/")
	&& !wizardp(ob) && userp(ob)){
		MONITOR_D->report_system_object_msg (ob,"得到了"+this_object()->query("name")+"["+file_name(this_object())+"]。");
	}
	return 1;
}
varargs void remove(string euid)
{
	object default_ob;

	if( !previous_object()
	||  base_name(previous_object()) != SIMUL_EFUN_OB )
		error("move: remove() can only be called by destruct() simul efun.\n");
       me = this_object();
#ifdef DB_SAVE
        if( userp(me) && sizeof(me->query("id")) )
                DATABASE_D->db_set_player(me->query("id"), "online", 0);
#endif
	if( this_object()->query("equipped")) {
		if((string)this_object()->query("equipped") == "horse"
		&& this_player()->query_temp("is_riding"))
			this_player()->delete_temp("is_riding");
		else if( !this_object()->unequip())
			log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
	}

	if( environment() ) environment()->add_encumbrance( - weight );
	if( default_ob = this_object()->query_default_object() )
		default_ob->add("no_clean_up", -1);
}
varargs int move_or_destruct( object dest )
{
	if( userp(this_object()) ) {
		tell_object(this_object(), "一阵时空的扭曲将你传送到另一个地方....\n");
		move(VOID_OB);
	}
}
