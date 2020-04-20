// named.c

//#pragma optimize
//#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

mapping first_name = ([]);
mapping global_words = ([]);
mapping male_words = ([]);
mapping female_words = ([]);
//姓氏，通用字，男性字，女性字
void create()
{
	seteuid(ROOT_UID);
	restore();
}

string query_save_file()
{
	return DATA_DIR + "named";
}


// 设置first_name
int set_name(string pattern, string def, int type)
{
	switch (type){
		case 1:{
			first_name[pattern] = def;
			save();
			return 1;
		}
		case 2:{
			global_words[pattern] = def;
			save();
			return 1;
		}
		case 3:{
			male_words[pattern] = def;
			save();
			return 1;
			}
		case 4:{
			female_words[pattern] = def;
			save();
			return 1;
		}
	}

}

// 删除first_name
int delete_name(string pattern, int type)
{
	switch (type){
		case 1:{
			map_delete(first_name, pattern);
			save();
			return 1;
		}
		case 2:{
			map_delete(global_words, pattern);
			save();
			return 1;
		}
		case 3:{
			map_delete(male_words, pattern);
			save();
			return 1;
		}
		case 4:{
			map_delete(female_words, pattern);
			save();
			return 1;
		}
	}
}

// 查询单个first_name
mapping query_name(string pattern, int type)
{
	switch (type){
		case 1:{
			if( !undefinedp(first_name[pattern]) ) return ([pattern:first_name[pattern]]);
			else return ([]);
		}
		case 2:{
			if( !undefinedp(global_words[pattern]) ) return ([pattern:global_words[pattern]]);
			else return ([]);
		}
		case 3:{
			if( !undefinedp(male_words[pattern]) ) return ([pattern:male_words[pattern]]);
			else return ([]);
		}
		case 4:{
			if( !undefinedp(female_words[pattern]) ) return ([pattern:female_words[pattern]]);
			else return ([]);
		}
	}
}

// 查询所有first_name
string *query_all_name(int type)
{
	switch (type){
		case 1: return keys(first_name);
		case 2: return keys(global_words);
		case 3: return keys(male_words);
		case 4: return keys(female_words);
	}
}

string random_name(int type)
{
	string *ename;
	int i ;
	switch (type){
		case 1:{
				ename = keys(first_name);
				i = sizeof( ename );
				if( !i ) return "";
				return first_name[ename[random(i)]];
		}
		case 2:{
				ename = keys(global_words);
				i = sizeof( ename );
				if( !i ) return "";
				return global_words[ename[random(i)]];
		}
		case 3:{
				ename = keys(male_words);
				i = sizeof( ename );
				if( !i ) return "";
				return male_words[ename[random(i)]];
		}
		case 4:{
				ename = keys(female_words);
				i = sizeof( ename );
				if( !i ) return "";
				return female_words[ename[random(i)]];
		}
	}
}
string query_Fname()
{
	string name;
	
	if(random(5) > 3)
		name = random_name(1) + random_name(4) + random_name(4);
	else 
		name = random_name(1) + random_name(4);

	return name;
}
string query_Mname()
{
	string name;
	
	if(random(5) > 3)
		name = random_name(1) + random_name(2) + random_name(3);
	else
		name = random_name(1) + random_name(3);

	return name;
}
