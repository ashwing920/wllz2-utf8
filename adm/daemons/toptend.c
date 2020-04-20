//toptend.c
//Design By 蝴蝶君[robert] mail:robert_st@sina.com

//#pragma optimize
//#pragma save_binary

#include <ansi.h>
#include <mudlib.h>

#define TOPTEN_RICH             "/topten/rich.txt"
#define TOPTEN_PKER             "/topten/pker.txt"
#define TOPTEN_EXP              "/topten/exp.txt"
#define TOPTEN_AGE              "/topten/age.txt"
#define TOPTEN_FIGHT            "/topten/fight.txt"
#define TOPTEN_MKS              "/topten/mks.txt"
#define TOPTEN_WEIWANG          "/topten/weiwang.txt"
#define TOPTEN_POOR             "/topten/poor.txt"

#define RICH_B                  "武林列传十大福门豪强排行榜"
#define PKER_B                  "武林列传十大无情杀手排行榜"
#define EXP_B                   "武林列传十大武林高手排行榜"
#define AGE_B                   "武林列传十大武林前辈排行榜"
#define FIGHT_B                 "武林列传十大擂王积分排行榜"
#define MKS_B                   "武林列传十大勇猛战神排行榜"
#define WEIWANG_B               "武林列传十大江湖威望排行榜"
#define POOR_B                  "武林列传十大悲情人物排行榜"

void topten_checkplayer(object);
int get_all_data(object,string);
int topten_del(string,string);
int topten_add(object,string);
int topten_save(string,string,string);
string topten_query(string);
string query_type();

void topten_checkplayer(object player)
{//对于外貌等属性用先天还是后天呢？还有有些是需要有点区分的（比如男女性别）
	topten_add(player,"rich");
	topten_add(player,"pker");
	topten_add(player,"exp");
	topten_add(player,"age");
	topten_add(player,"fight");
	topten_add(player,"mks");
	topten_add(player,"weiwang");
	topten_add(player,"poor");
	return;
}
string query_type()
{
	return HIW+ "  "+ code_name()+"现在有以下类型的排行榜\n\n"+
		HIC"Rich\t"+RICH_B+"\n"+
		HIC"Exp\t"+EXP_B+"\n"+
		HIC"Pker\t"+PKER_B+"\n"+
		HIC"Age\t"+AGE_B+"\n"+
		HIC"Fight\t"+FIGHT_B+"\n"+
		HIC"Mks\t"+MKS_B+"\n"+
		HIC"Weiwang\t"+WEIWANG_B+"\n"+
		HIC"Poor\t"+POOR_B+"\n"+NOR;
}
int topten_save(string f_name,string b_name,string str)
{
	string *astr;
	int i;
	astr=explode(str,"\n");
	str="";
	for(i=0;i<sizeof(astr)&&i<10;i++)
		str+=astr[i]+"\n";
	if(!write_file(f_name,str,1))
		return notify_fail("无法写文件"+f_name+"，权限不够！不能更新"+b_name+"！\n");
	return 1;
}

string topten_query(string type)
{
	string b_name,f_name,str,*astr,*bstr,name,id;
	int i,j,data;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "fight":
			b_name=FIGHT_B;
			f_name=TOPTEN_FIGHT;
			break;
		case "mks":
			b_name=MKS_B;
			f_name=TOPTEN_MKS;
			break;
		case "weiwang":
			b_name=WEIWANG_B;
			f_name=TOPTEN_WEIWANG;
			break;
		case "poor":
			b_name=POOR_B;
			f_name=TOPTEN_POOR;
			break;
		default:
			return "没有"+type+"这种排行榜！\n";
	}
	if(file_size(f_name)==-1)
		return b_name+"的数据文件还没有创建！\n";
	astr=explode(read_file(f_name),"\n");

	str=HIW"≡"HIY"─────────────────"HIW"≡\n";
	str+=HIY"　│　"+b_name+HIY"　│\n"NOR;
	str+=HIY"　│　　　　　　　　　　　　　　　│\n"NOR;
	for(i=0;i<sizeof(astr);i++)
	{
		bstr=explode(astr[i],";");
		str+=HIY"　│　"HIR"第"+chinese_number(i+1)+"名："HIW;
		for(j=0;j<sizeof(bstr);j++)
		{
			if(sscanf(bstr[j],"%s[%s]%d",name,id,data)!=3)
				return "数据错误!文件："+f_name+"第"+i+"行第"+j+"项！\n"+
					"该行数据："+bstr[j]+"\n";
			str+=sprintf("%-20s"HIY"│\n",name+"["+id+"]");
		}
		str+=HIY"　│　　　　　　　　　　　　　　　│\n"NOR;
	}
	str+=HIW"≡"HIY"─────────────────"HIW"≡";
	return str;
}
int get_all_data(object player,string type)
{
	int total;
	switch(type)
	{
		case "rich":
			if((int)player->query("balance"))
			total=(int)player->query("balance");
			break;
		case "pker":
			if((int)player->query("PKS"))
			total=(int)player->query("PKS");
			break;
		case "exp":
			if((int)player->query("combat_exp"))
			total=(int)player->query("combat_exp");
			break;
		case "age":
			if((int)player->query("age"))
			total=(int)player->query("age");
			break;
		case "fight":
			if((int)player->query("fight_wins") || (int)player->query("fight_lose"))
			total=((int)player->query("fight_wins") - (int)player->query("fight_lose"));
			break;
		case "mks":
			if((int)player->query("MKS"))
			total=(int)player->query("MKS");
			break;
		case "weiwang":
			if((int)player->query("weiwang"))
			total=(int)player->query("weiwang");
			break;
		case "poor":
			if((int)player->query("VKS"))
			total=(int)player->query("VKS");
			break;
		default:
			total=-1;//用-1标志类型出错！
	}
	return total;
}

int topten_del(string pid,string type)
{
	string str,*astr,*bstr,b_name,f_name;
	int i,j,k;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "fight":
			b_name=FIGHT_B;
			f_name=TOPTEN_FIGHT;
			break;
		case "mks":
			b_name=MKS_B;
			f_name=TOPTEN_MKS;
			break;
		case "weiwang":
			b_name=WEIWANG_B;
			f_name=TOPTEN_WEIWANG;
			break;
		case "poor":
			b_name=POOR_B;
			f_name=TOPTEN_POOR;
			break;
		default:
			return notify_fail("没有"+type+"这种排行榜！\n");
	}
	if(file_size(f_name)==-1)
		return notify_fail(b_name+"还没有创建！\n");
	str=read_file(f_name);
	astr=explode(str,"\n");
	for(i=0;i<sizeof(astr);i++)
	{
		if(strsrch(astr[i],pid)!=-1)//该行包括id则为真
		{
			if(strsrch(astr[i],";")==-1)
			//为真表示该行只有一个id，即pid
			{
				str="";
				for(j=0;j<sizeof(astr);j++)
					if(j!=i)
						str+=astr[j]+"\n";
				return topten_save(f_name,b_name,str);
			}
			else
			{
				bstr=explode(astr[i],";");
				for(j=0;j<sizeof(bstr);j++)
					if(strsrch(bstr[j],pid)!=-1)//说明该项即pid,应该去除
					{
						astr[i]="";
						for(k=0;k<sizeof(bstr);k++)
							if(k!=j)
							{
								if((k+1)!=sizeof(bstr)
									&&!((j+1)==sizeof(bstr)&&j==(k+1))
								)
									astr[i]+=bstr[k]+";";
								else
									astr[i]+=bstr[k];
							}
						//本来去除后j的循环应该停止,但是不影响结果
					}
				str=implode(astr,"\n");
				return topten_save(f_name,b_name,str);
			}
		}
	}
	return 1;
}

int topten_add(object player,string type)
{
	string str,name,id,b_name,f_name;
	string *astr;
	int i,j,data;

	//禁止巫师参加排行榜
	if(wizardp(player) || wizhood(player) == "(immortal)") return 0;
	switch(type)
	{
		case "rich":
			b_name=RICH_B;
			f_name=TOPTEN_RICH;
			break;
		case "pker":
			b_name=PKER_B;
			f_name=TOPTEN_PKER;
			break;
		case "exp":
			b_name=EXP_B;
			f_name=TOPTEN_EXP;
			break;
		case "age":
			b_name=AGE_B;
			f_name=TOPTEN_AGE;
			break;
		case "fight":
			b_name=FIGHT_B;
			f_name=TOPTEN_FIGHT;
			break;
		case "mks":
			b_name=MKS_B;
			f_name=TOPTEN_MKS;
			break;
		case "weiwang":
			b_name=WEIWANG_B;
			f_name=TOPTEN_WEIWANG;
			break;
		case "poor":
			b_name=POOR_B;
			f_name=TOPTEN_POOR;
			break;
		default:
			return notify_fail("没有"+type+"这种排行榜！\n");
	}
	if(!objectp(player)||!userp(player))
		return 0;
	if(file_size(f_name)==-1)
	{
		str=player->query("name")+"["+player->query("id")+"]"+
			get_all_data(player,type);
		return topten_save(f_name,b_name,str);
	}
	//主要程序！
	if(get_all_data(player,type)==-1)
		return notify_fail("数据查询错误，可能是查询类型错误！\n");
	//应该先排除该player的id!
	topten_del(player->query("id"),type);
	str=read_file(f_name);
	astr=explode(str,"\n");
	i=0;
	while(i<sizeof(astr))
	{
		if(sscanf(astr[i],"%s[%s]%d",name,id,data)!=3)
			if(sscanf(astr,"%s[%s]%d;%*s",name,id,data)!=3)
				return notify_fail(b_name+"文件数据错误！请呼叫巫师！\n");
		str="";
		if(data<(int)get_all_data(player,type))
		{
			//单独加入，暂时没考虑人数超过十行！
			for(j=0;j<sizeof(astr);j++)
			{
				if(j==i)
					str+=player->query("name")+"["+player->query("id")+"]"+
						get_all_data(player,type)+"\n";
				str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		else
		if(data==(int)get_all_data(player,type))
		{
			//并排加入
			for(j=0;j<sizeof(astr);j++)
			{
				/*
				if(j==i)
					str+=astr[j]+";"+player->query("name")+
						"["+player->query("id")+"]"+get_all_data(player,type)+"\n";
				else
				*/
					str+=astr[j]+"\n";
			}
			return topten_save(f_name,b_name,str);
		}
		i++;
	}
	if(sizeof(astr) < 10)
	{
		str=implode(astr,"\n")+"\n"+player->query("name")+"["+player->query("id")+
			"]"+get_all_data(player,type);
		return topten_save(f_name,b_name,str);
	}
	return 0;
}
