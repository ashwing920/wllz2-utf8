// mudlist.c
// Design By Robert email:robert_st@sina.com

#include <ansi.h>
#include <net/daemons.h>
#include <net/macros.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping mud_list;
	mapping mud_svc;
	mixed *muds;
	string output;
	int loop, size,pplno,total,total_mud,count=0;

	if( !find_object(DNS_MASTER) )
		return notify_fail("网路精灵并没有被载入。\n");

	//      Obtain mapping containing mud data
	mud_list = (mapping)DNS_MASTER->query_muds();

	// so we recognise ourselves as a DNS mud
	mud_svc = DNS_MASTER->query_svc() + ([ Mud_name() : 0 ]);

	if(!mud_list)
		return notify_fail( code_name() + "目前并没有跟网路上其他 Mud 取得联系。\n");

	//      Get list of all mud names within name server
	muds = keys( mud_list ) - ({ "DEFAULT" });

	//      Place mudlist into alphabetical format
	muds = sort_array(muds, 1);

	//      If mudname provided, search server's database for a match
	if( arg ) arg = upper_case(arg);
	if(arg && arg != "" && arg != "ALL" && arg != "ES" && arg != "WLLZ" ) {
		arg = htonn(arg);
		if(!mapp( mud_list[arg] )) {
			write(code_name() + "并没有和这个 Mud 取得联系。\n");
			return 1;
		}
		if( wizardp(me) && !me->query("env/debug") )
			write(sprintf("有关 %s 的资讯：\n%O\n", arg, mud_list[arg]));
		else
			write(sprintf("\n有关 %s 的资讯：\n"
				"──────────────────\n"
				"中文名称：  %s\n"
				"语言：      %s\n"
				"版本：      %s\n"
				"MudOS：     %s\n"
				"Mudlib：    %s\n"
				"主机：      %s\n"
				"端口：      %s\n"
				"状态：      %s\n"
				"在线玩家：  %s\n"
				"当地时间：  %s\n"
				"运行时间：  %s\n"
				"──────────────────\n\n",
				mud_list[arg]["NAME"],
				undefinedp(mud_list[arg]["MUDNAME"])?
				"不详":mud_list[arg]["MUDNAME"],
				undefinedp(mud_list[arg]["ENCODING"])?
				"不详":(mud_list[arg]["ENCODING"]=="GB"?"简体汉字":"繁体汉字"),
				undefinedp(mud_list[arg]["VERSION"])?
				"不详":mud_list[arg]["VERSION"],
				undefinedp(mud_list[arg]["DRIVER"])?
				"不详":mud_list[arg]["DRIVER"],
				undefinedp(mud_list[arg]["MUDLIB"])?
				"不详":mud_list[arg]["MUDLIB"],
				mud_list[arg]["HOSTADDRESS"],
				mud_list[arg]["PORT"],
				mud_list[arg]["_dns_no_contact"]<1?
				"连线":"断开",
				undefinedp(mud_list[arg]["USERS"])?
				"不详":mud_list[arg]["USERS"],
				undefinedp(mud_list[arg]["TIME"])?
				"不详":mud_list[arg]["TIME"],
				undefinedp(mud_list[arg]["UPTIME"])?
				"不详":mud_list[arg]["UPTIME"],
				));
		return 1;
	}

	output =
BRED + HIR" 中文名称             国际网路位址     端口  运行时间              人数 \n"NOR+
"────────────────────────────────────\n";
	//      Loop through mud list and store one by one
	for(loop = 0, size = sizeof(muds); loop<size; loop++) {

		if( !arg && mud_list[muds[loop]]["MUDLIB"] != MUDLIB_NAME ) continue;
		if( !wizardp(me) && arg == "ALL") arg ="";
		if( arg ) {
			if( arg =="ES" && mud_list[muds[loop]]["MUDLIB"] != "Eastern Stories" ) continue;
			if( arg =="WLLZ" && mud_list[muds[loop]]["MUDLIB"] != "武林列传" ) continue;
			if( arg!="ALL" && mud_list[muds[loop]]["MUDLIB"] != MUDLIB_NAME ) continue;
		}
		if( mud_list[muds[loop]]["_dns_no_contact"] > 0 ) {
			if( !wizardp(me) || (wizardp(me) && me->query("env/debug")) )
				continue;
		}
		if(undefinedp(mud_list[muds[loop]]["USERS"])) {
				continue;
		}
		count = loop;
		if( htonn(upper_case(muds[loop])) == htonn(upper_case(INTERMUD_MUD_NAME)) )
		if( mud_list[muds[loop]]["HOSTADDRESS"] == mud_list[muds[loop]]["HOSTADDRESS"]
		|| mud_list[muds[loop]]["HOSTADDRESS"]== 0) {
			mud_list[muds[loop]]["HOSTADDRESS"]= "LOCALHOST";
			output +=  BGRN+HIW;
		}
		else {
			output += NOR;
		}
		if( undefinedp(mud_list[muds[loop]]["MUDNAME"]) ) {
			output +=  sprintf("%-43s  %-15s  %4s",
				upper_case(muds[loop]),
				mud_list[muds[loop]]["HOSTADDRESS"],
				mud_list[muds[loop]]["PORT"]);
		}
		else {
			output +=  sprintf(" %-20s %-15s  %4s",
				undefinedp(mud_list[muds[loop]]["MUDNAME"])?
				"":clean_color(mud_list[muds[loop]]["MUDNAME"][0..35]),
				mud_list[muds[loop]]["HOSTADDRESS"],
				mud_list[muds[loop]]["PORT"]);
		}
		if(!undefinedp(mud_list[muds[loop]]["UPTIME"]))
				output+=sprintf("  %-21s",mud_list[muds[loop]]["MUDNAME"] == code_name()?
				CHINESE_D->chinese_time(uptime())[0..19]:mud_list[muds[loop]]["UPTIME"][0..19]);

		if(!undefinedp(mud_list[muds[loop]]["USERS"]))
				output+=sprintf("  %3s ", mud_list[muds[loop]]["USERS"]);

		output +=NOR"\n";
	if (undefinedp(mud_list[muds[loop]]["USERS"]))
	pplno = 0;
	 else
	sscanf(mud_list[muds[loop]]["USERS"], "%d", pplno);
	total += pplno;
		total_mud ++;
	}
	//      Display dumped mudlist output through user's more pager
output+="────────────────────────────────────\n";
	if(arg == "ALL" || arg == "ES")
		output += sprintf("共有 %d 个 Mud 与"+ code_name() +"连线，%d 个使用者正在进行游戏。\n",total_mud==0?0:total_mud-1,total);
	else
		output += sprintf("本泥潭共有 "HIY"%d"NOR" 位玩家正在进行游戏。\n",total);
	if (userp(me) ) this_player()->start_more( output );
	else write(output);

	return 1;
}

int help()
{
	write("\n指令格式：mudlist            列出连线中的"+ code_name() +"站点。\n"
		"          mudlist <MudName>  列出指定 Mud 的信息。\n");
	return 1;
}
