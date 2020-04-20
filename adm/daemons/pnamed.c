// named.c
// 中文名字记载

//#pragma optimize
//#pragma save_binary

#define NAME_FILE	DATA_DIR +"player_name.o"

inherit F_SAVE;
inherit F_DBASE;

mapping name=([ ]);

void create()
{
	seteuid(ROOT_UID);
	if(file_size(NAME_FILE)<0){
		name = ([ ]);
		save();
	}
	restore();
}
void add_name(string id,string user_name)
{
	if(stringp(id) && stringp(user_name) && !stringp(name[id])){
		name[id]=user_name;
		save();
		restore();
		return;
	}
}
void del_name(string id,string user_name)
{
	if(stringp(id) && stringp(name[id])){
		map_delete(name,id);
		save();
		restore();
		return;
	}
}
string query_save_file()
{
	return NAME_FILE;
}
int check_name(string user_name)
{
	int i;
	string *key=keys(name);

	for (i=0;i < sizeof(name);i++) {
		if (user_name==name[key[i]]) {
			write("对不起，这个名字和 "+ key[i] + " 的名字太相似了。\n");
			return 0;
		}

		else {
			if(strlen(user_name) > strlen(name[key[i]]) && strlen(name[key[i]]) >=4 
			&& strsrch(user_name,name[key[i]]) != -1 && strlen(user_name) >=4 ) {
				write("对不起，这个名字和 "+ key[i] + " 的名字太相似了。\n");
				return 0;
			}

			if (strlen(user_name) < strlen(name[key[i]])&&strlen(user_name) >=4 
			&& strsrch(name[key[i]],user_name)!=-1) {
				write("对不起，这个名字和 "+ key[i] +" 的名字太相似了。\n");
				return 0;
			}
		}
	}
	return 1;
}
