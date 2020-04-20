// passwd.c

#include <ansi.h>
#include <login.h>

inherit F_CLEAN_UP;
int check_legal_password(object ob,string pass);

int main(object me, string arg)
{
	object ob;

	if( me != this_player(1) ) return 0;

	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

	write("为了安全起见，请先输入您原来的密码：");
	input_to("get_old_pass", 1, ob);
	return 1;
}
private void get_old_pass(string pass, object ob)
{
	string old_pass;

	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write("密码错误！\n");
		return;
	}
	write("请输入新的密码：");
	input_to("get_new_pass", 1, ob );
}
private void get_new_pass(string pass, object ob)
{
	if(check_legal_password(ob,pass)) {
	write("\n请再输入一次新的密码：");
#ifdef  ENABLE_MD5_PASSWORD
	input_to("confirm_new_pass", 1, ob, crypt(pass,sprintf("$1$%d", random(99999999))));
#else
	input_to("confirm_new_pass", 1, ob, crypt(pass,0));
#endif
	} else
	write("请输入新的密码：");
	input_to("get_new_pass", 1, ob );
	return;
}

private void confirm_new_pass(string pass, object ob, string new_pass)
{
	write("\n");
	if( crypt(pass, new_pass)!=new_pass ) {
		write("对不起，您输入的密码并不相同，继续使用原来的密码。\n");
		return;
	}
	seteuid(getuid());
	if( !ob->set("password", new_pass) ) {
		write("密码变更失败！\n");
		return;
	}

	ob->save();
	write("密码变更成功。\n");
	log_file("static/PASSWD", sprintf("[%s] %s[%s]修改密码，连线来自[%s]。\n",
		ctime(time()),this_player()->query("name"),getuid(this_player(1)), query_ip_name(this_player(1)) ));
}
int check_legal_password(object ob,string pass)
{
	int i;
	int bigletter=0;
	int smlletter=0;
	string id;

	i = strlen(pass);
	if( strlen(pass) <= 5)   {
		write("对不起，你的密码必须最少六个字符。\n");
		return 0;
	}

	id = ob->query("id");    
	if ( strsrch(id, pass) != -1 || strsrch(pass, id) != -1)
	{
		write("对不起，你的密码和你的英文名字太象了。\n");
		return 0;
	}

	while( i-- ) {
		if( pass[i]<='Z' && pass[i] >='A' ) bigletter++;
		if( pass[i]<='z' && pass[i] >='a' ) smlletter++;

	}
	if( bigletter == 0 || smlletter == 0 || bigletter + smlletter == strlen(pass) )
	{
		write("您的密码必须包含" HIR "大写" NOR "和" + HIR "小写英文字母" NOR
			"以及" HIR "其它字符" NOR "，例如：Mud-123。\n");
		return 0;
	}
	
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : passwd
 
这个指令可以修改你的人物密码。
 
HELP
	);
	return 1;
}
