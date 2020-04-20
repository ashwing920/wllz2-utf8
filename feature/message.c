// message.c

#include <ansi.h>
#include <dbase.h>

#define MAX_STRING_SIZE		6000
#define MAX_MSG_BUFFER		500

static string *msg_buffer = ({});
static int written = 0;
static string log_in = 0;
#define NONE			0
#define PROMPT_WRITTEN		1
#define COMMAND_RCVD		2

string prompt()
{
	string p;
	mapping my;

	my = this_object()->query_entire_dbase();

	if(query("env/no_prompt") || !stringp(p = query("env/prompt"))) 
		return HIC+">"+NOR;

	p= clean_color(p);

	switch(lower_case(p))
	{
		case "time":
			p = ctime(time())[11..18];
			break;
		case "status":
			p = sprintf("%d/%d|%d/%d",
				my["jing"],my["eff_jing"],my["qi"],my["eff_qi"]);
			break;
		case "force":
			p = sprintf("%d/%d|%d/%d",
				my["jingli"],my["max_jingli"],my["neili"],my["max_neili"]);
			break;
		case "file_name":
			if(!wizardp(this_object())) break;
			p = base_name(environment(this_object()));
			break;
		case "exp":
			p = sprintf("%d",my["combat_exp"]);
			break;
		case "pot":
			p = sprintf("%d",my["potential"] - my["learned_points"]);
			break;
		case "shen":
			p = sprintf("%s%d",my["shen"]>=0?HIW:HIC,my["shen"]);
			break;
		case "shaqi":
			p = sprintf("%s",
			my["bellicosity"] > (my["max_neili"] + my["neili"])?HIM"DANGEROUS":HIC"GENIALTY");
			break;
		default:
			p = "";
			break;
	}
	p += HIC"> "NOR;
	return WHT + p;
}

void receive_message(string msgclass, string msg)
{
	string subclass, *ch;

	if( !interactive(this_object()) ) {
		this_object()->relay_message(msgclass, msg);
		return;
	}

	if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
		switch(subclass) {
			case "channel":
				if( !pointerp(ch = query("channels"))
				||	member_array(msgclass, ch)==-1 )
					return;
				break;
			case "outdoor":
				if( !environment() || !environment()->query("outdoors") )
					return;
				break;
			case "system":
				break;
			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}

	if(query_temp("block_msg/all") || query_temp("block_msg/" + msgclass)) return;
	if(this_object()->query("env/no_color")) msg = clean_color(msg);

	if(in_input(this_object()) || in_edit(this_object())
	|| this_object()->is_attach_system() && msgclass != "system") {
		if (sizeof(msg_buffer) < MAX_MSG_BUFFER)
			msg_buffer += ({ msg });
	}
	else {

		if (written && ! this_object()->is_attach_system())
		{
			if (written == COMMAND_RCVD)
			{
				written = NONE;
				msg = ESC "[256D" ESC "[K" + msg;
			} else
				msg = ESC "[256D" ESC "[K" + msg + prompt();
		}
		while (strlen(msg) > MAX_STRING_SIZE)
		{
			receive(msg[0..MAX_STRING_SIZE - 1]);
			msg = msg[MAX_STRING_SIZE..<1];
		}

		receive(msg);
	}
}

void clear_written()
{
	written = COMMAND_RCVD;
}
int is_waiting_command()
{
	return (written == PROMPT_WRITTEN);
}
void write_prompt()
{
	if( sizeof(msg_buffer) ) {
		receive(BOLD "[输入时暂存讯息]\n" NOR);
		for(int i = 0; i < sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}

	if (! living(this_object())) return;

	if (this_object()->is_attach_system())
		receive(HIR "执行中" NOR "> ");
	else
		receive(ESC "[256D" + prompt());

	written = PROMPT_WRITTEN;
}

void receive_snoop(string msg)
{
	if ((msg[0..5] == ESC "[256D") && (msg[6..8] != ESC "[K"))
		// Don't snoop prompt
		return;

	msg = replace_string(msg, ESC "[1A", ""); 
	msg = replace_string(msg, NOR, NOR BBLU WHT);
	//msg = replace_string(msg, ESC "[K", NOR ESC "[K" BBLU WHT);
	msg = BBLU WHT + msg + NOR + " " + ESC "[1D";
	while (strlen(msg) > MAX_STRING_SIZE)
	{
		receive(msg[0..MAX_STRING_SIZE - 1]);
		msg = msg[MAX_STRING_SIZE..<1];
	}
	receive(msg);
}
