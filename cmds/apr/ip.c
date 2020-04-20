//ip.c
//Design By Robert 蝴蝶君

inherit F_CLEAN_UP;

#include <ansi.h>
#include <net/dns.h>
int help(object me);

void create(){ 	seteuid(getuid());}
private int check_multilogin();

int main(object me,string arg)
{
	string status;

	status = wizhood(me);
	if( me!=this_player(1) ||wiz_level(me) <wiz_level(status) )
		return notify_fail("你没有权力使用这个指令。\n");
	if(arg)
		return help(me);
	return check_multilogin();
}

private int check_multilogin()
{
	object *ob;
	string * ip_addr;
	string * temp;
	mixed * multy;
	int * count;
	string t;
	int i,j,s,s1;
	ob=users();
	s = sizeof(ob);
	write(sprintf ("现在共有"+ HIC +"%s"+ NOR +"个玩家\n",chinese_number(s)));
	ip_addr=allocate(s);
	ip_addr[0]=query_ip_number(ob[0]);
	temp=allocate(1);
	for (i=0;i<s;i++) {
		if( !environment(ob[i]) ) continue;
		if( wizardp(ob[i]) && ob[i]->query("env/invisibility") > 20) continue;
		temp[0]=query_ip_number(ob[i]);
		ip_addr=ip_addr-temp;
		ip_addr=ip_addr+temp;
	}
	ip_addr=ip_addr-({0});
	s1=sizeof(ip_addr);
	write(sprintf (HIC"%s"+ NOR +"个不同的IP\n\n",chinese_number(s1)));
	count=allocate(s1);
	multy=allocate(s1);
	for (i=0;i<s1;i++)
		multy[i]=allocate(s);
	for (i=0;i<s;i++) {
		t=query_ip_number(ob[i]);
		for (j=0;j<s1;j++)
			if (ip_addr[j]==t)  {
				multy[j][count[j]]=ob[i]->query("id");
				count[j]++;
			}
	}
	for (i=0;i<s1;i++)
		multy[i]=multy[i]-({0});
	write(sprintf("%s\t\t%s\n","IP 地址","人数"));
	for (i=0;i<s1;i++) {
		write(sprintf("%s\t%d\t",ip_addr[i],count[i]));
		for (j=0;j<sizeof(multy[i]);j++)
			write(sprintf("%s ",multy[i][j]));
		write("\n");
	}

	return 1;
}

int help(object me)
{
	write(@TEXT

指令格式：ip

这个指令是让你检查目前游戏中共有多少个相同的IP，相关
指令：mcheck。

TEXT);
	return 1;
}