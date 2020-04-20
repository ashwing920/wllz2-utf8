// message.c

#include <ansi.h>

varargs void message_vision(string msg, object me, object you)
{
	string my_gender, your_gender, my_name, your_name;
	string str1, str2, str3;
	object *ob;
	int n,i;

	if(!me) return;
	my_name= me->name();
	my_gender = me->query("gender");

	if(!my_name || !my_gender) return; //mon 10/23/97

	str1 = replace_string(msg,  "$P", gender_self(my_gender));
	str1 = replace_string(str1, "$N", gender_self(my_gender));
	str3 = replace_string(msg,  "$P", my_name);
	str3 = replace_string(str3, "$N", my_name);
	if( you ) {
		your_name= you->name();
		your_gender= you->query("gender");
		str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
		str2 = replace_string(str2, "$p", gender_self(your_gender));
		str2 = replace_string(str2, "$N", my_name);
		str2 = replace_string(str2, "$n", gender_self(your_gender));
		message("vision", str2, you);
		str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
		str1 = replace_string(str1, "$n", your_name);
		str3 = replace_string(str3, "$p", your_name);
		str3 = replace_string(str3, "$n", your_name);
	}
	message("vision", str1, me);
	message("vision", str3,  environment(me), ({ me, you}) );

	if( environment(me) )
		if( n = (environment(me)->query("fight_room")
			|| environment(me)->query("show_room")) ) {
			ob = users();
			i = sizeof(ob);
			while( i-- ) {
				if( !ob[i]) continue;
				if( !environment( ob[i] ) )continue;
				if( environment( ob[i] )->query("watch_fight_room") == n ) {
					message("vision", HIW "你看到：" NOR + str3,  environment( ob[i] ), ({ me, you }) );
					break;
				}
			}
	}
}
void write(string str)
{
	if( this_player() )
		message("write",str, this_player());
	else if( previous_object() )
		message("write",str, previous_object());
	else
		efun::write(str);
}

varargs void say(string str, mixed exclude)
{
	if( living(previous_object()) )
		message("say", str, environment(previous_object()), previous_object());
	else if( this_player() )
		message("say", str, environment(this_player()), this_player());
}
nomask varargs void printf(mixed *arg1...)
{
	mixed *arg;
	string output;

	arg = arg1[1..];
	output = sprintf(arg1[0],arg...);
	write(output);
}
void tell_object(object ob, string str)
{
	if(ob) message("tell_object", str, ob);
}
void tell_team(object *obs, string str)
{
        foreach( object ob in obs )
                tell_object(ob, str);
}
varargs void tell_room(mixed ob, string str, object *exclude)
{
	if( ob ) message("tell_room", str, ob, exclude);
}

void shout(string str)
{
	message("shout", str, users(), this_player());
}
/*
void message(mixed arg, string message, mixed target, mixed exclude)
{
	efun::message(arg, message, target, exclude);
}
*/
void message_system(string message)
{
	message("system", HIW"【系统公告】" + message + "\n" NOR,users(), 0);
}
void other_message(string color,string prompt,string message)
{
	object *listeners;

	listeners = filter_array(users(), (: !$1->query("env/no_other_msg") :));
	if(!color) color = HIY;
	message("other_msg",color +"【"+ prompt +"】" + clean_color(message) + "\n"NOR,listeners,0);
}
int notify_fail(string msg)
{
	if (this_player()) 
	{
		this_player()->set_temp("notify_fail", msg);
		return efun::notify_fail(ESC "[256D" ESC "[K" + msg);
	} else
		return 0;
}

string query_fail_msg()
{
	return this_player()->query_temp("notify_fail");
}
