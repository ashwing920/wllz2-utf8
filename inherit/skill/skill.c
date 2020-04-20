//skill.c

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int valid_learn(object me) { return 1; }

int valid_effect(object me, object weapon, string action_name, int skill) 
{ 
	return 1;
}

string type() { return "martial"; }

void skill_improved(object me) {}
int practice_level(){ return 100;}               //自练隐含级别
int exert_function(object me, string arg)
{
	string func, target, file;
	object target_ob;

	if( sscanf(arg, "%s %s", func, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
	} else {
		func = arg;
		target_ob = me;
	}

	if( !stringp(file = (string)this_object()->exert_function_file(func))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "exert", me, target_ob);
}

int perform_action(object me, string arg)
{
	string action, target, file;
	object target_ob;

	if( sscanf(arg, "%s %s", action, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) return notify_fail("这里没有 " + target + "。\n");
	} else {
		action = arg;
	}

	if( !stringp(file = (string)this_object()->perform_action_file(action))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "perform", me, target_ob);
}

int cast_spell(object me, string spell, object target)
{
	string file;

	notify_fail("你所选用的咒文系中没有这种咒文。\n");

	if( !stringp(file = (string)this_object()->cast_spell_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "cast", me, target);
}

int conjure_magic(object me, string spell, object target)
{
	string file;

	notify_fail("你所选用的法术系中没有这种法术。\n");

	if( !stringp(file = (string)this_object()->conjure_magic_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "conjure", me, target);
}

int scribe_spell(object me, object ob, string spell)
{
	string file;

	if( !stringp(file = (string)this_object()->scribe_spell_file(spell))
	||	file_size(file + ".c") <= 0 )
		return 0;

	return (int)call_other( file, "scribe", me, ob );
}

int sum(int n,int base,int d)
{
	return (n*(2*base+(n-1)*d)/2);
}

int NewRandom(int n,int base,int d)
{ 
	int i = 1;
	int randnum = random(sum(n,base,d));

	if (sum(6,base,d) < randnum){
	i = 7;
	while (sum(i,base,d) < randnum)
	i++;
	}
	else {
	while (sum(i,base,d) < randnum)
	i++;
} 
	return (i-1);
}

// 特殊招式(由combatd.c调用)
void do_interlink(object me, object victim)
{
      return;
}

