//securityd.c

//#pragma optimize
//#pragma save_binary

inherit F_DBASE;
inherit F_SAVE;

static mapping wiz_status=([]);//

string *wiz_levels = ({
	"(player)",
	"(immortal)",
	"(wizard)",
	"(arch)",
	"(admin)",
});

static mapping trusted_write = ([]);
static mapping exclude_write = ([]);
static mapping trusted_read = ([]);
static mapping exclude_read = ([]);

string query_save_file()
{
	return DATA_DIR "securityd";
}

void restore_list()
{
	string *t_read,*t_write;
	string *e_read,*e_write;
	set("wiz_status/robert","(admin)");
	t_read=query("trusted_read/\n");
	t_write=query("trusted_write/\n");
	if(sizeof(t_read))
	{
		t_read=t_read - ({ROOT_UID});
		t_read=t_read - ({"(admin)"});
		t_read=t_read + ({ROOT_UID,"(admin)"});
	}
	else
		t_read=({ROOT_UID,"(admin)"});
	if(sizeof(t_write))
	{
		t_write=t_write - ({ROOT_UID});
		t_write=t_write - ({"(admin)"});
		t_write=t_write + ({ROOT_UID,"(admin)"});
	}
	else
		t_write=({ROOT_UID,"(admin)"});
	set("trusted_read/\n",t_read);
	set("trusted_write/\n",t_write);

	e_read=query("exclude_read/\n");
	e_write=query("exclude_write/\n");
	if(sizeof(e_read))
	{
		e_read=e_read - ({"(player)"});
		e_read=e_read + ({"(player)"});
	}
	else
		e_read=({"(player)"});
	if(sizeof(e_write))
	{
		e_write=e_write - ({"(player)"});
		e_write=e_write + ({"(player)"});
	}
	else
		e_write=({"(player)"});
	set("exclude_read/\n",e_read);
	set("exclude_write/\n",e_write);

	wiz_status = query("wiz_status");
	trusted_write = query("trusted_write");
	trusted_read = query("trusted_read");
	exclude_write = query("exclude_write");
	exclude_read = query("exclude_read");
	return ;
}

void save_list()
{
	set("trusted_write",trusted_write);
	set("trusted_read",trusted_read);
	set("exclude_write",exclude_write);
	set("exclude_read",exclude_read);
	return ;
}

int save()
{
	save_list();
	return ::save();
}

//用户接口程序，负责输出权限列表！
string print_access_list(object user,string type)
{
	string str,file,*acc;
	if(wiz_level(user)<wiz_level("(admin)"))
		return "权限不够无法读取Access_List!\n";
	str="权限分配表如下：\n";
	if(type=="all"||type=="exclude_read")
	{
		str+="不可读>>\n";
		if(sizeof(exclude_read))
			foreach(file in keys(exclude_read))
			{
				acc=exclude_read[file];
				file=replace_string(file,"\n","/");
				str+=file+"\t: "+implode(acc,",")+"\n";
			}
	}
	if(type=="all"||type=="trusted_read")
	{
		str+="可读>>\n";
		if(sizeof(trusted_read))
			foreach(file in keys(trusted_read))
			{
				acc=trusted_read[file];
				file=replace_string(file,"\n","/");
				str+=file+"\t: "+implode(acc,",")+"\n";
			}
	}
	if(type=="all"||type=="exclude_write")
	{
		str+="不可写>>\n";
		if(sizeof(exclude_write))
			foreach(file in keys(exclude_write))
			{
				acc=exclude_write[file];
				file=replace_string(file,"\n","/");
				str+=file+"\t: "+implode(acc,",")+"\n";
			}
	}
	if(type=="all"||type=="trusted_write")
	{
		str+="可写>>\n";
		if(sizeof(trusted_write))
			foreach(file in keys(trusted_write))
			{
				acc=trusted_write[file];
				file=replace_string(file,"\n","/");
				str+=file+"\t: "+implode(acc,",")+"\n";
			}
	}
	return str;
}

//用户接口程序，负责维护权限列表access_list
int modify_access_list(object user,string op,string type,string file,string *acc_user)
{
	string *acc;
	int i;
	if(!file||!sizeof(acc_user))
		return 0;
	if(wiz_level(user)!=wiz_level("(admin)"))//只允许admin维护列表
		return 0;
	file=replace_string(file,"/","\n");//对文件进行编码操作！不然路径的"/"和mapping的"/"混淆！
	switch(op)
	{
		case "add":
			switch(type)
			{
				case "trusted_read":
				case "trusted_write":
				case "exclude_read":
				case "exclude_write":
					sscanf(file,"/%s",file);//处理掉第一个/符号
					acc=query(type+"/"+file);
					if(sizeof(acc))
					{
						for(i=sizeof(acc_user);i>0;i--)
						{
							acc=acc - ({acc_user[i-1]});
							acc=acc + ({acc_user[i-1]});
						}
					}
					else
						acc= acc_user;
					set(type+"/"+file,acc);
					break;
				default:
					//不能识别的类型
					return 0;
			}
			break;
		case "del":
			switch(type)
			{
				case "trusted_read"://
				case "trusted_write":
				case "exclude_read":
				case "exclude_write":
					sscanf(file,"/%s",file);//处理掉第一个/符号
					acc=query(type+"/"+file);
					if(sizeof(acc))
					{
						for(i=sizeof(acc_user);i>0;i--)
							acc=acc - ({acc_user[i-1]});
					}
					if(sizeof(acc))
						set(type+"/"+file,acc);
					else
						delete(type+"/" +file);
					break;
				default:
					//不能识别的类型
					return 0;
			}
			break;
		default:
			//权限设置操作不能识别！
			return 0;
	}
	save();
	restore_list();
	return 1;
}

void create()
{
	//在wizlist属性里储存，而不再在/adm/etc/wizlist里存储！
	set("channel_id","管理精灵");
	restore();
	restore_list();
}

string *query_wizlist() { return keys(wiz_status); }

// 这个函数返回一个uid或者obj的status
string get_status(mixed ob)
{
	string euid;
	if( objectp(ob) )
	{
		euid = geteuid(ob);
		if( !euid ) euid = getuid(ob);
	}
	else if( stringp(ob) ) euid = ob;
	if( !undefinedp(wiz_status[euid]) ) return wiz_status[euid];
	else if( member_array(euid, wiz_levels)!=-1 ) return euid;
	else return "(player)";
}

int get_wiz_level(mixed ob)
{
	return member_array(get_status(ob), wiz_levels);
}

int set_status(mixed ob, string status)
{
	string uid;

	//应该检查一下status是否格式正确！
	if( geteuid(previous_object())!= ROOT_UID)
		if(!wiz_level(previous_object())>wiz_level("(admin)"))//允许admin设置巫师表
			return 0;
	//这个地方应该严格审核是否有权进行提升操作！
	if( objectp(ob)&&userp(ob) )
		uid = getuid(ob);
	else
		if(stringp(ob))
			uid = ob;
		else
		{
			CHANNEL_D->do_channel(this_object(),"sys","非法设置巫师级别："+ob+" "+status+"\n");
			return 0;
		}
	if( status == "(player)" )
		map_delete(wiz_status, uid);
	else
		wiz_status[uid] = status;
	set("wiz_status",wiz_status);
	save();
	log_file( "static/promotion", capitalize(uid) + " 成为 " + status + " 时间：" + ctime(time()) + "\n" );
	return 1;
}

string *get_wizlist() { return keys(wiz_status); }

int valid_read(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;
	if( !objectp(user) )
		error("SECURITY_D->valid_read: user这个参数的值非法！\n");

	// Modify By JackyBoy
	if(file == query_save_file() || 
		file == query_save_file()+__SAVE_EXTENSION__ ) 
			return 1;//如果是自身的存储文件，则任何人都可以读取！

	if( func=="restore_object" ) {
		if( sscanf(file, "/data/%*s")
		&& (file == (string)user->query_save_file()+__SAVE_EXTENSION__  
		|| file == (string)user->query_save_file()))
			return 1;
		if( sscanf(file,"/data/board/%*s"))
			return 1;//允许无条件读取board数据
	}
	
	if (func == "file_size") return 1;
	
	// 取得用户的euid和status
	euid = geteuid(user);
	if( !euid ) return 0;
	status = get_status(user);
	//"NONAME"在系统刚启动时经常遇到，所以这应该是安全的
	//不过这也是建立在没有人可以自己设置自己的euid这个基础上的。
	if( euid==ROOT_UID|| euid=="NONAME" ) return 1;
	//immortal以上的才可以进入/u目录！
	if((file=="/u/"||file=="/u")&&wiz_level(status)>wiz_level("(immortal)"))
	return 1;
	//对于/u下的可以读自己的目录！
	if( sscanf(file, "/u/" + euid + "/%*s") || file=="/u/"+euid) return 1;
	if( sscanf(file, "/" + "/%*s") ||file=="/") return 1;

	path = explode(file, "/");

	// 检查读排除表！如果排除了，则直接返回1，否则继续判断！
	// 由于编码的关系，"/"被"\n"取代！
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "\n");
		//此处如果exclude_read为空就出错！
		if( undefinedp(exclude_read[dir]) ) continue;
		if( member_array(euid, exclude_read[dir])!=-1 ) return 0;
		if( member_array(status, exclude_read[dir])!=-1 ) return 0;
	}

	// 检查读信任表，如果信任则返回1，否则失败
	if( member_array(euid, trusted_read["\n"])!=-1 ) return 1;
	if( member_array(status, trusted_read["\n"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "\n");
		if( undefinedp(trusted_read[dir]) ) continue;
		if( member_array(euid, trusted_read[dir])!=-1 ) return 1;
		if( member_array(status, trusted_read[dir])!=-1 ) return 1;
	}
	if(wizhood(user)!="(player)")
		log_file("wiz_read_fail.log", sprintf("%s(%s) 试图越权读取 %s ！\n",
			geteuid(user), wizhood(user), file));
	else
		log_file("read_fail.log", sprintf("%s(%s) 试图调用 %s 失败。\n",
			geteuid(user), wizhood(user), file));
	return 0;
}

int valid_write(string file, mixed user, string func)
{
	string euid, status, *path, dir;
	int i;

	if( !objectp(user) )
		error("SECURITY_D->valid_write: 参数user的值非法！\n");

	if( sscanf(file, LOG_DIR + "%*s") && func=="write_file" ) return 1;

	// 让用户和可存储对象能存储自己的
	// 或许可以使用这样的算法：如果USERP(user)，那么如果file==user->query_save_file()就可以写？
	if( func=="save_object" )
	{
		if(sscanf(file, "/data/%*s")
			&&(file == (string)user->query_save_file() + __SAVE_EXTENSION__
			|| file == (string)user->query_save_file())) 
				return 1;

		log_file("dpm.log","错误存储：\n"+user->name(1)+geteuid(user)+get_status(user)+"file："+file+"\n");
	}

	// Get the euid and status of the user.
	euid = geteuid(user);
	if(file == (string)ROOM_D->get_file_name(user)) return 1;
	if( !euid ) return 0;
	if( euid==ROOT_UID || euid=="NONAME") return 1;
	//不可读就不可写 add by jackyboy
	if(valid_read(file,user,func)==0)
		return 0;
	status = get_status(user);

	path = explode(file, "/");

	// 检查写排除表，如果被排除则返回0，否则继续判断
	// 编码的关系，在"/"分离后再用"\n"合并判断！
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "\n");
		if( undefinedp(exclude_write[dir]) ) continue;
		if( member_array(euid, exclude_write[dir])!=-1 ) return 0;
		if( member_array(status, exclude_write[dir])!=-1 ) return 0;
	}

	// 检查新信任表，如果信任则返回1，否则不允许写！
	if( member_array(euid, trusted_write["\n"])!=-1 ) return 1;
	if( member_array(status, trusted_write["\n"])!=-1 ) return 1;
	for(i=sizeof(path)-1; i>=0; i--) {
		dir = implode(path[0..i], "\n");
		if( undefinedp(trusted_write[dir]) ) continue;
		if( member_array(euid, trusted_write[dir])!=-1 ) return 1;
		if( member_array(status, trusted_write[dir])!=-1 ) return 1;
	}

	log_file("write_fail.log", sprintf("%s(%s) 试图写入 %s 失败。\n", geteuid(user), wizhood(user), file));
	return 0;
}

int valid_seteuid( object ob, string uid )
{
	if( uid==0 ) return 1;
	if( uid==getuid(ob) ) return 1;
	if( getuid(ob)==ROOT_UID ) return 1;
	if( sscanf(file_name(ob), "/adm/%*s") ) return 1;
	if( wiz_status[uid] != "(admin)"
	&&      wiz_status[getuid(ob)] == "(admin)" )
		return 1;
	return 0;
}

int valid_set(object ob, object user)
{
	int level_ob,level_user;

	if ( author_file(base_name(user)) ==ROOT_UID ) return 1;
	if (ob==user) return 1;

	level_ob=member_array(get_status(ob), wiz_levels);
	level_user=member_array(get_status(user), wiz_levels);

	if (!level_user)    return 1;                        // player set
	if (!level_ob && level_user<2)  return 0;            // wiz set player
	return ( level_user >= level_ob );                   // wiz set wiz
}
int valid_bind(object binder, object old_owner, object new_owner)
{
	// ROOT可以绑定任何函数
	if (geteuid(binder) == ROOT_UID) return 1;

	// 如果绑定者没有发生变化
	if (binder == new_owner) return 1;

	if (! wiz_level(new_owner) && geteuid(new_owner) != ROOT_UID)
		return 1;

	// 不同意绑定
	return 0;
}
