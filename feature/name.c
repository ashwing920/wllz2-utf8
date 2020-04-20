// name.c

#include <ansi.h>
#include <dbase.h>
#include <condition.h>

static string *my_id;

void set_name(string name, string *id)
{
	set("name", name);
	set("id", id[0]);
	my_id = id;
}

int id(string str)
{
	string *applied_id;

	if( this_player() && !this_player()->visible(this_object()) ) return 0;

	if( pointerp(applied_id = query_temp("apply/id"))
	&&  sizeof(applied_id))
	if( member_array(str, applied_id)!=-1 )
	return 1;
	else
	return 0;

	if( pointerp(my_id) && member_array(str, my_id)!=-1 )
	return 1;
	else
	return 0;
}

string *parse_command_id_list()
{
	return my_id;
}

varargs string name(int raw)
{
	string name,*mask;

	if( !raw && sizeof(mask = query_temp("apply/name")) )
		return mask[sizeof(mask)-1];
	else {
		if( stringp(name = query("name")) ){
			if( raw < 2)
				return name;
			else 
				return name + "(" + capitalize(query("id")) + ")";;
		}
		else
			return file_name(this_object());
	}
}

varargs string short(int raw)
{
	string str;
	
	if (raw || ! stringp(str = query("short")))
		str = name(raw) + "(" + capitalize(query("id")) + ")";
	return str;
}


varargs string long(int raw)
{
	string str, extra, *mask;

	if( !raw && sizeof(mask = query_temp("apply/long")) )
		str = mask[sizeof(mask)-1];
	else if( !stringp(str = query("long")) )
		str = short(raw) + "。\n";

	if( stringp(extra = this_object()->extra_long()) )
		str += extra;

	return str;
}
