// checkd.c 设定检查系统
// Design By Robert 蝴蝶君 email:robert_st@sina.com

//#pragma optimize
//#pragma save_binary

#include <ansi.h>

private void create(){ seteuid(getuid());}

private string *banned_id = ({
	"fuck", "shit", "mother", "father" ,"root", "admin","arch","sex","obj","sexbaby",
	"wizard","apprentice" ,"immortal","user", "login","npc","char","makelove","test",
	"objects","observer","adm","master","seller","noname","wllz","mudos","config","euid",
	"sysop","sys","system","who","wizlist","mudlist","wiz","immortal","apprentice","mudos",
	"halt","fuckyou","fucky","tnnd","fengyao","save","reboot","call","shutdown","clone",
	"tnnd","tmd",
});
private string *banned_name = ({
	"你","我","他","她","它","　","","武林列传","烽火再起","自己","大家","的",
	"你","我","他","她","它","爸","妈","操","干","测试","蝴蝶君","蝴蝶","使用者",
	"扑","爷","奶","婆","叔","姨","爹","做爱","色狼","交","嫖","强奸","调戏","尝试",
	"性","的","妓","哥","姐","哈","嘻","呵","巫师","天神","神仙","大圣","大帝","看看",
	"天帝",MUD_NAME,code_name(),"伟哥","春药","鸡巴","武林","列传","周恩来","毛泽东","邓小平"," ","　",
	"江泽民","蒋介石","测试","试试","看看","黑客","捣蛋","破坏","搞","大米","沈嘉","姚宇斌",
	"　 "
});
private string *banned_msg = ({
	"fuck","操","他妈","我干","你娘","法轮功","你妈","日你","干","拷","kao","靠","shit","tnnd",
	"tmd","sex","你妈","逼","你奶奶","阴道","乳房","屁股","劳资","老子","扑","阴茎","阴沟",
	"阴道","高潮","避孕套","法轮","鸡",
});

int check_legal_name(string name)
{
	int i;

	i = strlen(name);
	if( (strlen(name) < 1) || (strlen(name) > 4 ) )
	{
		write("对不起，你的中文名字必须是 1 到 4 个中文字。\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			write("对不起，你的中文名字不能用控制字元。\n");
			return 0;
		}
		if( i%2==0 && ! CHINESE_D->is_chinese(name[i..<0]) )
		{
			write("对不起，请您用「中文」取名字。\n");
			return 0;
		}
	}

	if ( file_size(CONFIG_DIR + "banned_name") >=0 )
	{
		banned_name = explode(read_file(CONFIG_DIR + "banned_name"), "\n");
	}
	else
	{
		i = sizeof(banned_name);
		while(i--)
		{
			write_file(CONFIG_DIR + "banned_name", banned_name[i] + "\n", 0);
		}
	}

	for(i=0; i<sizeof(banned_name); i++) {
		if( strsrch(name, banned_name[i]) == -1) continue;
		write("对不起，这种名字会造成其他人的困扰。\n");
		return 0;
	}


	return 1;

}
int check_obj_name(string name)
{
	int i;

	i = strlen(name);
	if( (strlen(name) < 2) || (strlen(name) > 40 ) ) return 0;
	if ( file_size(CONFIG_DIR + "banned_name") >=0 )
	{
		banned_name = explode(read_file(CONFIG_DIR + "banned_name"), "\n");
	}
	else
	{
		i = sizeof(banned_name);
		while(i--)
		{
			write_file(CONFIG_DIR + "banned_name", banned_name[i] + "\n", 0);
		}
	}

	for(i=0; i<sizeof(banned_name); i++) {
		if( strsrch(name, banned_name[i]) == -1) continue;
		return 0;
	}
	return 1;

}

int check_legal_password(object ob,string pass)
{
	int i;
	int bigletter=0;
	int smlletter=0;
	string id;

	i = strlen(pass);
	if( strlen(pass) <= 6)   {
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
int check_msg(string msg)
{
	int i;
	i = strlen(msg);

	for(i=0; i<sizeof(banned_msg); i++) {
		if( strsrch(msg, banned_msg[i]) == -1) continue;
		return 0;
	}

	return 1;
}
